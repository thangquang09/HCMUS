library(tidyverse)
library(ggplot2)
final_data <- read.csv("final_data.csv")

ab_testing <- function(data1, data2, alter, R=1000) {
  n1 <- nrow(data1)
  n2 <- nrow(data2)
  total_n <- n1 + n2
  
  rate1_origin <- nrow(data1 |> filter(converted == 1)) / n1
  rate2_origin <- nrow(data2 |> filter(converted == 1)) / n2
  
  full_data <- bind_rows(data1, data2)
  rate_diff <- numeric(length=R)
  
  for (i in 1:R) {
    idx_1 <- sample(1:total_n, n1)
    idx_2 <- setdiff(1:total_n, idx_1)
    
    rate1_per <- nrow(full_data[idx_1, ] |> filter(converted == 1)) / n1
    rate2_per <- nrow(full_data[idx_2, ] |> filter(converted == 1)) / n2
    
    rate_diff[i] <- rate1_per - rate2_per
  }
  
  p_value = -1
  if (alter == "left") {
    p_value <- mean(rate_diff < rate1_origin - rate2_origin)
  }
  else if (alter == "right") {
    p_value <- mean(rate_diff > rate1_origin - rate2_origin)
  }
  else if (alter == "two_sided") {
    p_value <- mean(abs(rate_diff) > abs(rate1_origin - rate2_origin))
  }
  
  result <- list(
    rate_diff = rate_diff,
    rate1_origin = rate1_origin,
    rate2_origin = rate2_origin,
    p_value = p_value
  )
  return (result)
}

## PHAT BIEU GIA THUYET
## Ti le nguoi dung mua san pham khi su dung trang web moi cao hon web cu
## H0: p1 >= p2
## H1: p1 < p2

data1 <- final_data |> filter(landing_page == 0)
data2 <- final_data |> filter(landing_page == 1)

res <- ab_testing(data1, data2, R = 1000, alter = "left")
print(res)
rate_diff <- res$rate_diff

ggplot(data = tibble(perm_diffs = rate_diff), aes(x = perm_diffs)) +
  geom_histogram(bins = 10, fill = "pink", color = "black") +
  labs(x = "Propotion converted differences", y = "Frequency") +
  theme_bw()

