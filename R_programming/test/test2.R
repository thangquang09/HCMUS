
## cau 1.1
twosided.interval <- function(p) {
  alpha <- (1 - p) / 2
  a <- qt(alpha, df = 15)
  b <- qt(1 - alpha, df = 15)
  return(c(a, b))
}

# Kiểm tra với p=0.8
twosided.interval(0.8)


# Test với p = 0.8
right.interval <- function(p) {
  c <- qt(1 - p, df = 15)
  return(c(c, Inf))
}

# Kiểm tra với p=0.9
right.interval(0.9)

# Test với p = 0.9
result <- right.interval(0.8) # Vì chúng ta cần tìm cho xác suất 0.9, ta sử dụng 1 - p tức là 0.1
print(result)

## 1.3
left.interval <- function(p) {
  c <- qt(p, df=15)
  interval <- c(-Inf, c)
  return(interval)
}
left.interval(0.8)


## Bai 2

##2.1
mu = 2
sigma=2
c=7
d=5

x = rnorm(10000, mean=mu, sd=sigma)
Y = c*x + d
hist(Y, freq=0, main="Y=7X+5")
curve(dnorm(x, mean = c*mu + d, sd=c*sigma), add=TRUE, col = "blue", lty=1, lwd=2)

##2.2.
n=10
mu=2
sigma=2
Z = function() {
  X = rnorm(n, mean=mu, sd=sigma)
  Z_val = (mean(X) - mu) / (sqrt(var(X)) / sqrt(n))
  return (Z_val)
}


vecZ = function(m) replicate(m, Z())
hist(vecZ(10000), freq=0, main="Hist of vecZ", breaks=40)
x = rt(10000, df=n-1)
curve(dt(x, df=n-1), col="blue", add=TRUE, lty=1, lwd=2)

## bai 3
# X tuan theo phan phoi nhi thuc X~Binom(n=50, p=0.2)
n = 50
p = 0.2

P = function(n, k, p) {
  # tinh P(X = k)
  P_val = choose(n, k) * p^k * (1-p)^(n-k)
  return (P_val)
}

FX = function(n, k, p) {
  # tinh tong P(X <= k)
  F_val = 0
  for (i in 0:k) {
    F_val = F_val + P(n, i, p)
  }
  return (F_val)
}



vecP = numeric(length = n)
for (i in 0:n) {
  vecP[i] = P(n, i, p)
}
plot(vecP, type="h")
## tinh xac suat dau
## P(X >= 25) = 1 - P(X <= 24)
P_dau = 0
for(i in 0:24) {
  P_dau = P_dau + P(n, i, p)
}
1 - P_dau

sum(dbinom(25:50, size=n, prob=p)) # dung 1 cau lenh cach 1
pbinom(50, n, p) - pbinom(24, n, p) # dung 1 cau lenh cach 2

## bai 4
## 4.1
throw.coin = function() {
  x = runif(1)
  if(x <= 0.6) "S" else "N"
}
## 4.2
sample.coin = function(n) replicate(n, throw.coin())
## 4.3: 22110202
tansuat = table(sample.coin(110202)) / 110202
barplot(tansuat, xlab = "mặt đồng xu", ylab="tần suất", main="Biểu đồ cột thể hiện tần suất")
