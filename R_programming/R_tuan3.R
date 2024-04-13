### Tuan 3:

## d p q r

# norm, pois, hyper, unif, norm, chisq, t, f
### d: xac suat
### p: tich luy
### q: 
### r: random


runif(1) # tra ve mot so ngau nhien co phan phoi deu / runif(n, min, max)

throw.coin = function() {
  x = runif(1)
  if(x < 0.5) 0 else 1
}

sample.coin = function(n) {
  replicate(n, throw.coin())
}

x = sample.coin(10)
table(x)

x = rnorm(1)
x^2

n = 10000
x = rnorm(n, mean = 0, sd = 1)
x

y = x^2
hist(y, freq = 0, breaks = 40)
curve(dchisq(x, df=1), add=T, col='red', lty=1, lwd=2)



