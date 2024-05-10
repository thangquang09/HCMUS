##
## Bai kiem tra 2 - Thuc hanh Ly thuyet Thong ke
## Lop: CT3 ca 1
##
## Ho ten: Ly Quang Thang - MSSV: 22110202
##
##**************************************************
## Bai 1:
### 1.1.

twosided.interval <- function(p) {
  alpha <- (1 - p) / 2
  a <- qchisq(alpha, df = 15)
  b <- qchisq(1 - alpha, df = 15)
  return(c(a, b))
}
twosided.interval(0.9)

### 1.2.
right.interval <- function(p) {
  c <- qchisq(1 - p, df = 15)
  return(c(c, Inf))
}
right.interval(0.95)

### 1.3.
left.interval <- function(p) {
  c <- qchisq(p, df=15)
  interval <- c(0, c)
  return(interval)
}
left.interval(0.95)

##------------------------------------------------------------
## Bai 2:
### 2.1
mu = 2
sigma = 2
X = rnorm(10000, mean=mu, sd=sigma)
Y = (X - mu) / sigma
hist(Y, freq=0, main="Histogram of Y", breaks=40)
x = rnorm(10000, mean=0, sd=1)
curve(dnorm(x), add=TRUE, col="blue", lty=1, lwd=2)
# nhan xet: Y xap xi phan phoi chuan khi co mau du lon vay dinh ly tren phat bieu dung nghia la chuan
# hoa mot bien ngau nhien pp chuan thi ta dc pp N(0,1)
###2.2
n=10
mu=2
sigma=2
  
Z = function() {
  x = rnorm(n, mean=mu, sd=sigma)
  z_val = ((mean(x) - mu) / (sqrt(var(x)) / sqrt(n)))
  return(z_val)
}

vecZ = function(m) replicate(m, Z())
hist(vecZ(10000), freq=0, main = "histogram of Z", breaks=40)
x = rt(10000, df=n-1)
curve(dt(x, df=n-1), col = "blue", lty=1, lwd=2, add=TRUE)
# nhan xet: Z tien xap xi phan phoi student(n-1) khi co mau du lon vay dinh ly tren phat bieu dung

##------------------------------------------------------------
## Bai 3:

## 3.1
# Dat X_i (i=0:50) la bien bernoulli the hien cau thu i lam dung hay sai vay X_i ~ B(1, 0.25)
# X tuan theo phan phoi nhi thuc B(n=50, p=0.25)
## 3.2
x = 0:50
pp = dbinom(x, size=50, prob=0.25)
plot(pp, type="h", main="Phan phoi xac suat cua X")
## 3.3
## cach 1 dung sum va d-
sum(dbinom(0:19, size=50, prob=0.25))m
## cach 2 dung p- P(X >= 20) = P(X <= 50) - P(X <= 19)
pbinom(19, size=50, prob=0.25)


##------------------------------------------------------------
## Bai 4:
### 4.1
throw.dice = function() {
  tmp = runif(1)
  res = -1
  if(tmp <= 0.1) {
    res = 1
  }
  else if(tmp <= 0.25) {
    res = 2
  }
  else if(tmp <= 0.45) {
    res = 3
  }
  else if(tmp <= 0.7) {
    res = 4
  }
  else if(tmp <= 0.9) {
    res = 5
  }
  else if(tmp <= 1)
    res = 6
  return (res)
}
### 4.2
sample.dice = function(n) replicate(n, throw.dice())

tansuat = table(sample.dice(110202)) / 110202
tansuat
barplot(tansuat, main = "Tan suat so cham tren xuc sac xuat hien", xlab="x", ylab="P", ylim = c(0, 0.3))

##**************************************************
## Ket thuc