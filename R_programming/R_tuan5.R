## 2.2.1
n = 10000
x = rnorm(n)
y = x^2
hist(y, freq=0, breaks=40)

curve(dchisq(x, df=1), col = "blue", lty=1, lwd=2, add=TRUE) # tham so add de ve chong len do thi cu
# tham so lty: loai duong

## 2.2.2 Mo hong X + Y ~ chi^2(m + n) khi X ~ chi^2(m), Y ~ chi^2(n)

n = 10000
x = rchisq(n, df = 10)
y = rchisq(n, df = 20)
z = x + y
hist(z, freq = 0, breaks=40)
curve(dchisq(x, df=30), col="blue", lty=1, lwd=2, add=TRUE)

### 2.2.3 mo phong X / sqrt(Y / n) ~ St(n) voi X ~ N(0, 1), Y~chi^2(n)
n = 10000
x = rnorm(n)
y = rchisq(n, df = 10)
z = x / sqrt(y / 10)
hist(z, freq=0, breaks=40)

curve(dt(x, df=10), col = "blue", lty=1, lwd=2, add=TRUE)

### 2.4.1

mu = 2
sigma = 2
Y = function() rnorm(1, mu, sigma) # (n, mean, sd): n la so mau
Y()
n = 4
vecY = function(n) replicate(n, Y())

vecY(n)
MeanY = function() mean(vecY(n))
MeanY()

SamepleMeanY = function(m) replicate(m, MeanY())
m = 10000
hist(SamepleMeanY(m), freq=0, breaks = 40)
curve(dnorm(x, mu, sigma/sqrt(n)), col = "blue", lty=1, lwd=2, add=TRUE)

### Dinh ly
mu = 2
sigma = 2
n = 10
z = function() {
  x = rnorm(n, mu, sigma)
  return(((n-1) * var(x)) / sigma ^ 2)

}

z()

vecZ = function(m) replicate(m, z())
hist(vecZ(1000), freq=0, breaks=40)
curve(dchisq(x, df=n-1), col = "blue", lty=1, lwd=2, add=TRUE)


hist(vecZ(10000), freq=0, breaks=40)
curve(dchisq(x, df=n-1), col = "blue", lty=1, lwd=2, add=TRUE)

### 2.4.2.
size=10
prob=0.3
mauX = function(n) {
x = rbinom(n, size, prob)
return(sqrt(n) * (mean(x)-3)/sqrt(2.1))
}
y = function(m) replicate(m, mauX(n))

n=100
m=1000
hist(y(m), freq=0, breaks=40)
curve(dnorm(x), col="blue", lty=1, lwd=2, add=TRUE)

n=10000
hist(y(m), freq=0, breaks=40)
curve(dnorm(x), col = "blue", lty=1, lwd=2, add=TRUE)


