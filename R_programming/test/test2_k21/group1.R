## bai 1

### 1.1.
# X tuan theo phan phoi nhi thuc B(n=40, p=0.8)

### 1.2.
p = 0.8
n = 40
hamxacsuat = function(n, k, p) {
  return(choose(n, k) * p^k * (1-p)^(n-k))
}
vecP = numeric(length = n)
for (i in 1:n) {
  vecP[i] = hamxacsuat(n, i, p)
}
plot(vecP, type="h")

### 1.3
# P(5 <= X <= 30) = sum_i=5 ^ 30 P(X = i)
P = 0
for (i in 5:30) {
  P = P + hamxacsuat(n, i, p)
}
P
### 1.4
m.vec = c(10, 50, 100, 500, 1000, 5000, 10^5, 10^6, 2 * 10^6)
SampleMean.vec= numeric(length = length(m.vec))

for (k in 1:length(m.vec)) {
  m = m.vec[k]
  SampleMean.vec[k] = mean(rbinom(m, n, p))
}
plot(x=1:length(SampleMean.vec), y=SampleMean.vec, col = "blue", lty=1, type="l")
abline(h=n*p, col="red", lty=4)
## khi m -> vocung thi trung binh mau se gan nhu la bang E(X)

## bai 2
## 2.1


plotW = function(n, color) {
  X = rnorm(n)
  Y = rchisq(n, df = n)
  W = X / sqrt(Y / n)
  
  hist(W, freq=0)
  x = rt(n, df=n)
  curve(dt(x, df = n), add=TRUE, col=color)
}
layout(1:3)
plotW(10, "blue")
plotW(100, "red")
plotW(1000, "violet")



size.vec = c(10, 100, 1000, 10^4, 10^5)
colors.vec = c("blue", "orange", "violet", "green", "cyan")

for(i in 1:size.vec) {
  plotW(n = size.vec[i], color = colors.vec[i])
}
layout(matrix(1:6, nrow = 3, byrow = T))
for(i in 1:length(size.vec)) {
  plotW(n = size.vec[i], color = colors.vec[i])
}

## W khi n tien ra vo cung thi gan nhu la phan phoi student

