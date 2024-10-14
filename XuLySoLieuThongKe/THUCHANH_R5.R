# A/B TESTING
library(tidyverse)
library(janitor)

data_web <- read_csv(file="datasets/web_page_data.csv")

data_web <- data_web |> clean_names()
glimpse(data_web)

# ---- SUMMARISE DATA ----

data_web |> group_by(page) |>
  summarise(n = n(), mean = mean(time), sd = sd(time))

ggplot(data_web, aes(x=page, y=time, fill=page)) +
  geom_violin() +
  geom_boxplot(width=0.15) +
  scale_fill_manual(breaks=c("Page A", "Page B"),
                    values=c("forestgreen", "skyblue")) +
  labs(x="Page",  y = "Session Time (in seconds)") + 
  theme_bw() +
  theme(legend.position = "none")



# ---- ABTEST ----

## H0: mu_A = mu_B
## H1: mu_A < mu_B

perm_fun <- function(x, nA, nB, R) {
  n <- nA + nB
  mean_diff <- numeric(R)
  for (i in 1:R) {
    idx_a <- sample(x = 1:n, size = nA)
    idx_b <- setdiff(x = 1:n, y = idx_a)
    mean_diff[i] <- mean(x[idx_a]) - mean(x[idx_b])
  }
  return (mean_diff)
}

set.seed(42)
diff_mean_perm <- perm_fun(data_web$time, nA=21, nB=15, R=1000)

ggplot(data = tibble(perm_diffs = diff_mean_perm), aes(x = perm_diffs)) +
  geom_histogram(bins = 10, fill = "pink", color = "black") +
  labs(x = "Session time differences (in seconds)", y = "Frequency") +
  theme_bw()

mean_a <- mean(data_web$time[data_web$page == "Page A"])
mean_b <- mean(data_web$time[data_web$page == "Page B"])
# pvalue = 1/R sum (delta*_i < delta_i)
p_value <- mean(diff_mean_perm < (mean_a - mean_b))
p_value