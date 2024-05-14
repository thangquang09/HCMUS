## uoc luong khoang

### BAI TAP THUC HANH trang 149

# 3.1
# a
MauX = function(n, theta) rpois(n, theta)
# b
objective = function(theta, X) - sum(log(dpois(X, theta))) # dau tru vi tim max
theta.hat = function(X) return(nlminb(start=0.5, objective, X=X)$par)

n = 100
theta = 1
X = MauX(n, theta)
theta.hat(X)

# 3.2
MeanX = function(n, theta) mean(rexp(n, rate = 1/theta))
SampleMeanX = function(m, n, theta) replicate(m, MeanX(n, theta))

M = function(X) mean(X)
V = function(X) var(X)
n = 10
m = 100
theta=2
SMX = SampleMeanX(m, n, theta)
M(SMX)
theta

V(SMX)
theta^2 / n

# 3.3
MauX = function(n, theta) rnorm(n=n, mean=0, sd = theta)
Y = function(n, theta) mean(MauX(n, theta)^2)
SampleY = function(m, n, theta) replicate(m, Y(n, theta))
M = function(X) mean(X)
V = function(X) var(X)

theta = 1
n = 10
m = 100
SY = SampleY(m, n, theta)
M(SY); theta
V(SY); 2 * theta^2 / n

### FILE C3_UocLuongThamSoThongKe

# 1. 95% -> alpha = 0.05
alpha = 0.05
MauX = rnorm(n=35, mean = 10, sd = 5)
# biet truoc sd -> co var -> TH1

epsilon = qnorm(1-alpha/2) * 5 / sqrt(35)
# khoang tin cay
mean(MauX) - epsilon; mean(MauX)  + epsilon

# 2. read file from data directory

df = read.csv("data31.csv")
data = df$profit
n = length(data); n # >= 30

ci.mean = function(x, alpha) {
  n = length(x)
  epsilon = qnorm(1-alpha/2) * sqrt(var(x) / n)
  return (c(mean(x) - epsilon, mean(x) + epsilon))
}
ci.mean(data, 0.05); ci.mean(data, 0.01)


# 3. 
# a
df = read.csv("data32.csv")
data = df$KHTN
ci.mean(data, 0.05)
# b
ci.prob = function(f, n, alpha) {
  p.hat = f / n
  epsilon = qnorm(1 - alpha/2) * sqrt((p.hat * (1-p.hat)) / n)
  return (c(p.hat - epsilon, p.hat + epsilon))
}


ci.prob(sum(data >= 5), length(data), 0.1)
ci.prob(sum(data >= 5), length(data), 0.05)
ci.prob(sum(data >= 5), length(data), 0.01)


# 4.
data = c(replicate(6, 1.3), replicate(34, 1.5), replicate(31, 1.7), replicate(42, 1.9), replicate(12, 2.1))
ci.mean(data, 0.05)

gt1m7 = sum(data >= 1.7)
ci.prob(gt1m7, length(data), 0.05)

# 5.

ktc.tb = function(tbmau, dolechchuan, n, alpha) {
  epsilon = 0
  if (n >= 30) {
    epsilon = qnorm(1-alpha/2) * dolechchuan / sqrt(n)
  }
  else {
    epsilon = qt(1-alpha/2, n-1) * dolechchuan / sqrt(n)
  }
  
  return (c(tbmau - epsilon, tbmau + epsilon))
}

# 6. 

ktc.tb.mau = function(x, dolechchuan = -1, n, alpha) {
  epsilon = 0
  tbmau = mean(x)
  if (dolechchuan == -1) dolechchuan = sqrt(var(x))
  if (n >= 30) {
    epsilon = qnorm(1-alpha/2) * dolechchuan / sqrt(n)
  }
  else {
    epsilon = qt(1-alpha/2, n-1) * dolechchuan / sqrt(n)
  }
  
  return (c(tbmau - epsilon, tbmau + epsilon))
}

# 7.

X = c(replicate(2, 12), replicate(3, 12.05), replicate(7, 12.1), replicate(9, 12.15), replicate(10, 12.2), 
      replicate(8, 12.25), replicate(6, 12.3), replicate(5, 12.35), replicate(3, 12.4))

ktc.tb.mau(x= X, n = length(X), alpha = 0.05)
