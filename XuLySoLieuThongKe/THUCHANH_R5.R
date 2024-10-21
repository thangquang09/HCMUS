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

# ---- BÀI TẬP 1.1 ----

permuatation_test <- function(data1, data2, R, alter) {
  nA <- length(data1)
  nB <- length(data2)
  n <- nA + nB
  meanA <- mean(data1)
  meanB <- mean(data2)
  
  DATA <- c(data1, data2)
  
  mean_diff = numeric(length=R)
  
  for (i in 1:R) {
    idx_a = sample(1:n, nA)
    idx_b = setdiff(1:n, idx_a)
    mean_diff[i] <- mean(DATA[idx_a]) - mean(DATA[idx_b])
  }
  p_value <- -1
  if (alter == "left") {
    p_value <- mean(mean_diff < meanA - meanB)
  }
  else if (alter == "right") {
    p_value <- mean(mean_diff > meanA - meanB)
  }
  else if (alter == "two_sided") {
    p_value <- mean(abs(mean_diff) > abs(meanA - meanB))
  }
  
  result <- list(
    mean_diff=mean_diff,
    meanA = meanA,
    meanB = meanB,
    p_value = p_value
  )
  return (result)
}

X = data_web$time[data_web$page == "Page A"]
Y = data_web$time[data_web$page == "Page B"]
res <- permuatation_test(X, Y, R = 1000, alter = "right")
res
# print p-value

# ---- BÀI TẬP 1.2 ----
data_12 <- read_csv("datasets/Beerwings.csv")
glimpse(data_12)
# ---- a)
data_12 |> group_by(Gender) |> summarise(
  tb=mean(Hotwings, na.rm = TRUE),
  dlc=sd(Hotwings, na.rm = TRUE),
  tv=median(Hotwings, na.rm = TRUE),
  gtln=max(Hotwings, na.rm = TRUE),
  gtnn=min(Hotwings, na.rm = TRUE)
)

ggplot(data_12, aes(x=Gender, y=Hotwings, fill=Gender)) +
  geom_violin() +
  geom_boxplot(width=0.15) +
  scale_fill_manual(breaks=c("F", "M"),
                    values=c("forestgreen", "skyblue")) +
  labs(x="Gender",  y = "Number Hotwings") + 
  theme_bw() +
  theme(legend.position = "none")

# ---- b)
# male consume hot wings more than female !

# ---- BÀI TẬP 1.3 ----

# ---- a)
data_13 <- read_csv("datasets/Verizon.csv")
glimpse(data_13)

data_13 |> group_by(Group) |> summarise(
  tb=mean(Time, na.rm=TRUE),
  dlc=sd(Time, na.rm = TRUE),
  tv=median(Time, na.rm = TRUE),
  gtln=max(Time, na.rm = TRUE),
  gtnn=min(Time, na.rm = TRUE)
)

ggplot(data_13, aes(x=Group, y=Time, fill=Group)) +
  geom_violin() +
  geom_boxplot(width=0.15) +
  scale_fill_manual(breaks=c("CLEC", "ILEC"),
                    values=c("forestgreen", "skyblue")) +
  labs(x="Group",  y = "Time") + 
  theme_bw() +
  theme(legend.position = "none")

# ---- b)

# H0: mu_ILEC >= mu_CLEC
# H1: mu_ILEC < mu_CLEC
# alpha = 1%
data1 <- data_13$Time[data_13$Group == "ILEC"]
data2 <- data_13$Time[data_13$Group == "CLEC"]
res <- permuatation_test(data1, data2, R=1000, alter="right")
res

# p-value = 0.02 > alpha -> khong bac bo H0 -> thoi gian sua chua cua Verizon thuc hien sua chua cham hon





