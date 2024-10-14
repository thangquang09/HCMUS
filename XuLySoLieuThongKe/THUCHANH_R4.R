# PHUONG PHAP BOOTSTRAP

library(boot)
library(tidyverse)
library(ggplot2)
library(nycflights13)
# out_boot = boot(data, statistic, R, sim = "ordinary", ...)
# data: du lieu can phan tich
# statistic: ten ham dung de uoc luong hoac nhieu tham so
# R: so lan lay lai mau bootstrap

data_birth <- read_table("datasets/birthwt.txt")
glimpse(data_birth)

# ---- BOOTSTRAP CHO STATISTIC ----
# tao ham statistic
boot_mu_fun <- function(data, ind) {
  # data: du lieu 
  # ind: index da duoc xao tron
  data_new <- data[ind]
  out <- mean(data_new)
  return(out)
}

set.seed(34)

out_1 <- boot(data = data_birth$bwt, statistic = boot_mu_fun, R=1000)
out_1

# original: gia tri trung binh cua bwt
# bias: gia tri cua do lech giua gia tri trung binh (mau goc) va trung binh uoc luong bootstrap
# std.error: sai so chuan cua uoc luong bootstrap

ggplot(data=data.frame(t=out_1$t), mapping=aes(x=t)) + 
  geom_histogram(fill = "gray80", color="black", bins=20) +
  geom_vline(xintercept = out_1$t0, color = "blue", linetype="dashed") +
  xlab("bootstrap mean") + ylab("Frequency") + theme_bw()





# ---- BOOTSTRAP CHO CI ----

# boot.ci(boot.out, type="perc", conf=0.95)  syntax
boot.ci(out_1, type="perc", conf=0.95)

# ---- BT1 ----
data_bt1 <- read_table("datasets/birthwt.txt")

# ---- a)
# trung binh ta su dung lai boot_mu_fun

# ---- b)
boot_med_fun <- function(data, ind) {
  # data: du lieu
  # ind: index da dc xao tron
  new_data <- data[ind]
  out <- median(new_data)
  return(out)
}

set.seed(42)
med_out <- boot(data_bt1$age, statistic = boot_med_fun, R=1000)
boot.ci(med_out, type="perc", conf=0.95)

ggplot(data=data.frame(t=med_out$t), mapping=aes(x=t)) + 
  geom_histogram(fill = "gray80", color="black", bins=20) +
  geom_vline(xintercept = med_out$t0, color = "blue", linetype="dashed") +
  xlab("bootstrap median") + ylab("Frequency") + theme_bw()

# ---- c)
boot_cor_fun <- function(data, ind) {
  # data: du lieu
  # ind: index da dc xao tron
  new_data <- data[ind, ]
  data1 <- new_data$lwt
  data2 <- new_data$bwt
  out <- cor(data1, data2)
  return(out)
}

set.seed(42)
cor_out <- boot(data_bt1, statistic = boot_cor_fun, R=1000)
cor_out
boot.ci(cor_out, type="perc", conf=0.95)

ggplot(data=data.frame(t=cor_out$t), mapping=aes(x=t)) + 
  geom_histogram(fill = "gray80", color="black", bins=20) +
  geom_vline(xintercept = cor_out$t0, color = "blue", linetype="dashed") +
  xlab("bootstrap corr of lwt vs bwt") + ylab("Frequency") + theme_bw()

# ---- BT2 ----
data_bt2 <- read_csv("datasets/state.csv")
glimpse(data_bt2)
set.seed(42)
boot_wmean_fun <- function(data, ind) {
  
  new_data <- data[ind, ]
  x <- new_data$Murder.Rate
  weight <- new_data$Population
  out <- weighted.mean(x=x, w=weight)
  return(out)
}
set.seed(42)
out_wmean <- boot(data = data_bt2, statistic = boot_wmean_fun, R=1000)
out_wmean

boot.ci(out_wmean, type="perc", conf=0.95)

# ---- BT3 ----
data(flights)
data_bt3 <- flights
glimpse(data_bt3)
data_bt3 <- data_bt3 |> filter(!is.na(dep_delay))
# -- a)
set.seed(42)
year_2013 <- data_bt3 |> filter(year==2013)
data_3a <- sample_n(year_2013, 250, replace = TRUE) 
data_3a
out_3a <- boot(data_3a$dep_delay, statistic=boot_mu_fun, R=1000)

boot.ci(out_3a, type="perc", conf=0.95)

# -- b)
set.seed(42)
UA <- data_bt3 |> filter(carrier == "UA")
data_3b <- sample_n(UA, 300, replace = TRUE) 
out_3b <- boot(data_3b$dep_delay, statistic=boot_mu_fun, R=1000)
out_3b

boot.ci(out_3b, type="perc", conf=0.95)
# -- c)
set.seed(42)
DL <- data_bt3 |> filter(carrier == "DL")
data_3c <- sample_n(data_bt3, 250, replace = TRUE) 
out_3c <- boot(data_3c$dep_delay, statistic=boot_mu_fun, R=1000)
out_3c

boot.ci(out_3c, type="perc", conf=0.95)

# ---- BT4 ----
data_bt4 <- flights
glimpse(data_bt4)
# UA <- data_bt4 |> filter(!is.na(dep_delay) & carrier == "UA")
# DL <- data_bt4 |> filter(!is.na(dep_delay) & carrier == "DL")

UA <- data_3b
UB <- data_3c

N1 <- 300 # b)
N2 <- 250 # c)

R <- 1000
Means <- c()
alpha = 0.05
for (i in (0:R)) {
  ind1 <- sample(1:N1, size=N1, replace=TRUE)
  ind2 <- sample(1:N2, size=N2, replace=TRUE)
  
  mau_1 <- UA[ind1, ] 
  mau_2 <- DL[ind2, ]
  
  mean1 <- mean(mau_1$dep_delay)
  mean2 <- mean(mau_2$dep_delay)
  
  tk <- abs(mean1 - mean2)
  Means[i] <- tk
}

Means <- sort(Means)

idx1 <- floor(R * alpha/2)
idx2 <- floor(R*(1-alpha/2))

Means[idx1]; Means[idx2]
hist(Means)

# ---- BT5 ----

data_bt5 <- flights |> filter(month %in% c(11, 12, 1))
data_bt5 <- sample_n(data_bt5, 1000)

length_data <- nrow(data_bt5)

# ---- a)

gt_30 <- data_bt5 |> filter(dep_delay>30)
length_a <- nrow(gt_30)

tyle_a <- length_a / length_data
tyle_a

# ---- b)
boot_proportion_fun <- function(data, ind) {
  new_data <- data[ind, ]
  N <- nrow(new_data)
  gt_30 <- new_data |> filter(dep_delay > 30)
  n <- nrow(gt_30)
  return (n / N)
}

set.seed(42)
p_out <- boot(data_bt5, statistic = boot_proportion_fun, R=1000)
boot.ci(p_out, type="perc", conf=0.95)

# ---- c)
EV_data <- flights |> filter(!is.na(dep_delay) & carrier=="EV")
DL_data <- flights |> filter(!is.na(dep_delay) & carrier=="DL")
whole_data <- flights |> filter(!is.na(dep_delay))
N1 <- nrow(EV_data)
N2 <- nrow(DL_data)
N <- nrow(whole_data)

R <- 1000
Ps <- c()
alpha=0.05
for (i in (0:R)) {
  ind1 <- sample(1:N1, size=N1, replace=TRUE)
  idn2 <- sample(1:N2, size=N2, replace=TRUE)
  
  data_1 <- EV_data[ind1, ] |> filter(dep_delay > 30)
  data_2 <- DL_data[ind2, ] |> filter(dep_delay > 30)
  
  n1 <- nrow(data_1)
  n2 <- nrow(data_2)
  
  p1 <- n1 / N
  p2 <- n2 / N
  
  P <- abs(p1-p2)
  Ps[i] <- P
}

Ps <- sort(Ps)

idx1 <- floor(R * alpha/2)
idx2 <- floor(R*(1-alpha/2))

Ps[idx1]; Ps[idx2]

hist(Ps)
