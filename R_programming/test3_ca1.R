# bai 1

# 1.1
data("mtcars")
mtcars
qsecc = mtcars$qsec
hist(qsecc, breaks=40)
# 1.2
# length(qsecc) >= 30
ci.mean = function(x, alpha) {
  n = length(x)
  epsilon = qnorm(1-alpha/2) * sqrt(var(x) / n)
  return (c(mean(x) - epsilon, mean(x) + epsilon))
}
# 1.3
ci.mean(qsecc, 0.05)
ci.mean(qsecc, 0.01)

# 1.4
find_N = function(x, alpha, epsilon0) {
  ceiling(var(x) * qnorm(1-alpha/2)^2 / epsilon0^2)
}

find_N(qsecc, 0.05, 0.4)
find_N(qsecc, 0.01, 0.4)

# bai 2

data = c(replicate(10, 92.5), replicate(8, 97.5), replicate(20, 102.5), replicate(18, 107.5),
         replicate(29, 112.5), replicate(15, 117.5))

# 2.1

hist(data, breaks=seq(90, 120, by=5))

# 2.2

ktc.tyle = function(data, data.p, alpha) {
  epsilon = qnorm(1-alpha/2) * sqrt((data.p * (1-data.p)) / n)
  return(c(data.p - epsilon, data.p + epsilon))
}

# 2.3

giongtot = sum(data >= 110)
giongtot
length(data)

ktc.tyle(data, giongtot / length(data), 0.05)

# bai 3

X = c(0.0192,0.4773,0.3399,0.4324,0.8675,0.2079,0.3713,0.2547,0.3976,0.2048)

# 3.1
f <- function(x,theta){
  return(theta*x^(theta-1))
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
  return(-n/sum(log(X)))
}
theta.hat(X)
## Cach 2:
objective <- function(theta,X){
  return(-log_likelihood(theta))
}
theta = 0.5
theta.hat <- function(X) nlminb(start=0.5,objective,X=X)$par
theta.hat(X)

