## sach thuc hanh ly thuyet thong ke trang 131
## 2.1
#a. kiem chung bang ly thuyet
#b. 
Y = function(){
  u = runif(1)
  2 * sqrt(u) - 1
}

mauY = function(m) replicate(m, Y())

l = list()
l[[1]]=mauY(100)
l[[2]]=mauY(1000)
l[[3]]=mauY(10000)
layout(1:3)
for(i in 1:3) {
  hist(l[[i]], freq=0)
  curve((x+1)/2, col="blue", add = TRUE)
}

## 2.2.

#a.
Y = function() max(rnorm(3, mean = 6, sd=2))
#b.
## xay dung ham mat do
dens = function(x) {
  3 * pnorm(x, 6, 2)^2*dnorm(x, 6, 2)
}
l = list()
l[[1]]=replicate(100, Y())
l[[2]]=replicate(1000, Y())

for(i in 1:2) {
  hist(l[[i]], freq=0)
  curve(dens(x), add=TRUE)
}

## 2.3
layout(1)
Y = function() {
  u = runif(1)
  sqrt(u)
}

mauY = function(m) replicate(m, Y())
f = function(y) ifelse(y<1, y, 1/y^3)
m = 100
hist(mauY(m), freq=0)
curve(f(x), add=TRUE)

## 2.4
Y = function() sum(rnorm(2)^2)
mauY = function(m) replicate(m, Y())


l = list()
l[[1]] = mauY(100)
l[[2]] = mauY(1000)
l[[3]] = mauY(10000)

layout(1:3)
for(i in 1:3){
  hist(l[[i]], freq=0)
  curve(dchisq(x, df=2), add=TRUE)
}



