##
## Bai kiem tra 3- Thuc hanh Ly thuyet Thong ke
## Lop: CT3 ca 1
##
## Ho ten: Ly Quang Thang- MSSV: 22110202
##
##**************************************************
## Bai 1:
# 1.1
data("mtcars")
mtcars
qsecc = mtcars$qsec

hist(qsecc)
# 1.2
ci.var = function(x, alpha) {
  n = length(x)
  epsilon_trai = ((n - 1) * var(x)) / qchisq(1-alpha/2, df = n - 1)
  epsilon_phai = ((n - 1) * var(x)) / qchisq(alpha/2, df = n - 1)
  return (c(epsilon_trai, epsilon_phai))
}
# 1.3
ci.var(qsecc, 0.05)
ci.var(qsecc, 0.01)

##-----------------------------------------------------------
## Bai 2:
# 2.1
X = c(92.5, 97.5, 102.5, 107.5, 112.5, 117.5)
n = c(10, 8, 20, 18, 29, 15)

X = rep(X, n)

hist(X, breaks=seq(90, 120, by=5), main = "Tan so chieu cao", xlab = "Chieu cao (cm)")

# 2.2

ktc.tyle = function(data, data.p, alpha) {
  n = length(data)
  p.hat = data.p / n
  if (n * p < 5 || n * (1 - p) < 5) {
    return
  }
  epsilon = qnorm(1 - alpha/2) * sqrt((p.hat * (1-p.hat)) / n)
  return (c(p.hat - epsilon, p.hat + epsilon))
}

# 2.3
caoTu110 = sum(X >= 110)
ktc.tyle(X, caoTu110, 0.05)

# 2.4
find_N = function(data, data.p, alpha, epsilon0) {
  n = length(data)
  p.hat = data.p / n
  tmp = ceiling(qnorm(1 - alpha/2)^2 * p.hat * (1-p.hat) / epsilon0^2)
  return(tmp)
}

find_N(X, caoTu110, 0.02, 0.1)

##-----------------------------------------------------------
## Bai 3:
X = c(2.7972,1.7834,4.6553,3.8512,4.2964,7.5559,2.4536,4.2729,4.3036,2.6815)

# 3.1
f <- function(x,theta){
  return (1 / theta^2 * x * exp(-x / theta))
}

log_likelihood <- function(theta){
  n = length(X)
  L = 1
  for(i in 1:n){
    L = L * f(X[i],theta)
  }
  return(log(L))
}
log_likelihood(0.5)

# 3.2
## Cach 1:
theta.hat <- function(X){
  n <- length(X)
  return ((sum(X) / (2 * n)))
}
theta.hat(X)
## Cach 2:
objective <- function(theta,X){
  return(-log_likelihood(theta))
}
theta = 0.5
theta.hat <- function(X) nlminb(start=0.5,objective,X=X)$par
theta.hat(X)


##**************************************************
## Ket thuc