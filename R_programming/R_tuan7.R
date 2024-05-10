# uoc luong diem
## uoc luong cho trung binh
theta = 8
SampleMean = function(n) {
  mean(rnorm(n, mean=theta, sd=1))
}
SampleMean(100)
SampleMean(1000)
SampleMean(10000)
SampleMean(100000)

# tinh chech lech
MeanSample.n = function(m) replicate(m, SampleMean(n))
n=100
mean(MeanSample.n(1000))
mean(MeanSample.n(10000))

## uoc luong cho phuong sai
theta=1
SampleVar = function(n) {
  x.n = rnorm(n, mean=8, sd=sqrt(theta))
  mean(x.n^2)-mean(x.n)^2
}
SampleVar(10000)

# chenh lech
n=10
MeanSampleVar.n = function(m) {
  replicate(m, SampleVar(n))
}
mean(MeanSampleVar.n(100))
mean(MeanSampleVar.n(1000))
mean(MeanSampleVar.n(10000))

## ham phan phoi tich luy thuc nghiem
X=function() rnorm(1)
vecXn = function(n) replicate(n, X())

Fnhat=function(n) {
  ecdf(vecXn(n))
}
vecX = rnorm(100)
sort(vecX)
plot(ecdf(vecX), xlim=c(-2,2), main="")

plot(Fnhat(10), xlim=c(-4,4))
curve(pnorm(x), add=T, col="blue")

plot(Fnhat(100), xlim=c(-4,4))
curve(pnorm(x), add=T, col="blue")

plot(Fnhat(1000), xlim=c(-4,4))
curve(pnorm(x), add=T, col="blue")

## tim uoc luong hop ly cuc dai bang nlog
objective = function(theta, X)
{
  obj = -sum(log(dnorm(X, theta, 2)))
  return(obj)
}

theta.hat = function(X) {
  start = 0.5
  nlminb(start, objective, X=X)$par
}

n = 1000
theta.guess = 8

sample = rnorm(n, mean=theta.guess, 2)
theta.hat(sample)




