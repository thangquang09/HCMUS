## 2.4.1 Mau ngau nhien phan phoi chuan
mu= 2
sigma = 2
Y = function() rnorm(1, mu, sigma)
vecY = function(n) replicate(n, Y())
n = 4
vecY(n)

MeanY = function() mean(vecY(n))
MeanY()

SampleMeanY = function(m) replicate(m, MeanY())
m = 10000
hist(SampleMeanY(m), freq = 0, breaks = 40)
curve(dnorm(x, mu, sigma/sqrt(n)), col = 'blue', lty=1, lwd = 2, add = TRUE)

