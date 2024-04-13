getwd()
setwd('/home/thangquang/Documents/Ly thuyet thong ke/R_programing')


## 1.
A = matrix(data = c(1,2,3,2,2,2,3,2,3), nrow = 3, ncol = 3, byrow = T)
B = matrix(data = c(-3, 4, -6, 2, -1, 2, -2, -5, 4, -6, 3, 9, 7, -2, -6), nrow = 3, ncol = 5, byrow = T)

### 1.1
B[,4]
### 1.2
C = A%*%B
### 1.3
AT = t(A)
BT = t(B)

productATBT = BT%*%AT
productATBT
C

# vay productATBT la C chuyen vi

### 1.4
idx = t(matrix(c(1,1,1), nrow = 1, ncol = 3, byrow = T))
# Giai pt A.X = idx
inverstA = A^-1
X = inverstA %*% idx
X

### 1.5
## 2
### 2.1
year = c(1970:1979)
snow_cover = c(6.5, 12, 14.9, 10, 10.7, 7.9, 21.9, 12.5, 14.5, 9.2)
data.frame(year, snow_cover)
### 2.2
plot(year, snow_cover) # bieu do phan tan
corr_ = cor(year, snow_cover) # 
corr_

# nhan xet: hai dai luong khong co nhieu moi quan he tuyen tinh

### 2.3
layout(matrix(1:2, nrow = 1, ncol = 2, byrow = T))
hist(snow_cover, freq = T); hist(snow_cover, freq = F);
# tan so la so lan xuat hien, tan suat la ty le phan tram xuat hien

### 2.4
?boxplot
layout(1)
boxplot(x = snow_cover, horizontal = T)
min(snow_cover); max(snow_cover); mean(snow_cover); quantile(snow_cover, c(.25, .5, .75))
summary(snow_cover)
## 3
### 3.1
data = read.csv('./data/data01.csv')
data
### 3.2
index = as.vector(cut(data$Age, breaks = c(0,60,70,80, Inf), labels = c(0, 1, 2, 3), right = FALSE))
### 3.3
### tron
pie_chart = pie(table(index), main = "Bieu do tron Index")
data
### cot
barplot(table(index), main = "Bieu do cot Index")
### 3.4
# bieu do cot kep
bar_chart = barplot(table(index, data$K), beside = T, legend.text = c("<=60", "60<Age<=70", "70<Age<=80", ">80"))
### 3.5
phuongsai = function(x) {
  trung_binh = 0
  for (number in x) {
    trung_binh = trung_binh + number
  }
  trung_binh = trung_binh / length(x)
  phuong_sai = 0
  for (number in x) {
    phuong_sai = phuong_sai + (number - trung_binh)^2
  }
  phuong_sai = phuong_sai / (length(x)-1)
  return (phuong_sai)
}

phuongsai(as.numeric(data$FPSA))
## 4
### 4.1
phanvi = function(X, p) {
  X = sort(X)
  n = length(X)
  i = p * n / 100
  if (i - as.integer(i) != 0) {
    return (X[as.integer(i) + 1])
  }
  else {
    return ((X[i] + X[i + 1]) / 2)
  }
}

x = c(1,2,3,4,5, 6, 7)
phanvi(x, 50)
summary(x)
