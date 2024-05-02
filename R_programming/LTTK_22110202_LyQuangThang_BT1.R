##
## Bai tap them 1 - Thuc hanh Ly thuyet Thong ke
## Lop 22TTH ca chieu thu 3
##
## Ho ten: Ly Quang Thang - MSSV: 22110202
##
##**************************************************
## Bai 1:
### 1.1.



mass.prob = function(k, n, p) {
  k = as.integer(k)
  P = choose(n, k) * p^k * (1-p)^(n-k)
  return(P)
}

### 1.2.
cdf = function(k, n, p) {
  F_X = 0
  for (i in 0:k) {
    F_X = F_X + mass.prob(i, n, p)
  }
  return(F_X)
}
### 1.3.
#a.
n=10
p=0.25
F_X5 = cdf(5, n, p)
F_X85 = cdf(8.5, n, p)

F_X5
F_X85
#b
EX = n * p
EX

VarX = n*p*(1-p)
VarX
#c
P_vec = numeric(length=11)
for (i in 0:n) {
  P_vec[i] = round(mass.prob(i, n, p), 4)
} 
#d
k = 0:10
plot(k, P_vec, type = "b", xlab = "Giá trị k", ylab = "Trọng lượng xác suất")

FX_vec = numeric(length=11)
for (i in 0:n) {
  FX_vec[i] = round(cdf(i, n, p), 4)
}
plot(k, FX_vec, type = "b", xlab = "Giá trị k", ylab = "Phân phối xác suất")


##------------------------------------------------------------
## Bai 2:
### 2.1
diesel_engine = read.csv("diesel_engine.csv")
diesel_time = read.csv("diesel_time.csv")

names(diesel_engine)
names(diesel_time)

### 2.2
isna_diesel_engine = sum(is.na(diesel_engine))
isna_diesel_time = sum(is.na(diesel_time))

isna_diesel_engine
isna_diesel_time


diesel_engine$speed = replace(diesel_engine$speed, is.na(diesel_engine$speed), 1500)
diesel_engine$load = replace(diesel_engine$load, is.na(diesel_engine$load), 20)

print(diesel_engine)
### 2.3
mean(diesel_engine$alcohol); var(diesel_engine$alcohol); sd(diesel_engine$alcoho); max(diesel_engine$alcoho); min(diesel_engine$alcoho)
### 2.4
diesel = cbind(diesel_engine, diesel_time)
diesel

### 2.5
diesel[diesel$delay < 1.000,]$run
### 2.6
nrow(diesel[diesel$timing == 30,])
### 2.7
layout(matrix(1:3, nrow = 1, byrow = T))
boxplot(diesel$speed, horizontal = T, main = "boxplot speed")
boxplot(diesel$timing, horizontal = T, main = "boxplot timing")
boxplot(diesel$delay, horizontal = T, main = "boxplot delay")

### 2.8
layout(matrix(1:2, nrow = 1, byrow = T))
plot(diesel$timing, diesel$speed, xlab = "timing", ylab = "speed", main="speed & timing")
plot(diesel$temp, diesel$press, xlab = "temp", ylab = "press", main="temp & press")

### 2.9
mi = min(diesel$delay)
ma = max(diesel$delay)
bar = (ma - mi)/ 4
delay_cut = cut(diesel$delay, breaks=c(mi, mi + bar, mi + 2*bar, mi + 3*bar, mi + 4*bar))

count_delay = table(delay_cut)
layout(matrix(1:1, nrow = 1, byrow = T))
barplot(count_delay, main="4 doan bang nhau")

### 2.10
diesel$delay
barplot(table(cut(diesel$delay, breaks=c(0.283, 0.7, 0.95, 1.2, 1.56))), main = "4 doan dc chia")

##------------------------------------------------------------
##............................
##**************************************************
## Ket thuc