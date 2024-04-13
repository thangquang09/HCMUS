## BAI KIEM TRA 1 - THUC HANH LY THUYET THONG KE
## Thu 3 - Tiet 6_8

## Ho ten: Ly Quang Thang - MSSV: 22110202

##
## Bai kiem tra 1 - Thuc hanh Ly thuyet Thong ke
## Thu ... - tiet ....
##
## Ho ten: ......... - MSSV: ...........
##
##**************************************************
## Bai 1:
### 1.1
A = matrix(data = c(1,2,3,2,2,2,3,2,3), ncol = 3, nrow = 3, byrow = T)
B = matrix(data = c(-3, 4, -6, 2, -1, 2, -2, -5, 4, -6, 3, 9, 7, -2, -6), ncol = 5, nrow = 3, byrow = T)

print("Cot thu 4 cua ma tran B")
B[,4]
print("Phan tu thu 2, 3, 5 cua hang 1 cua ma tran B")
B[1, c(2,3,5)]
### 1.2
print("Ma tran C la tich cua A va B")
C = A%*%B
C
### 1.3
At = t(A)
Bt = t(B)
print("Ma tran chuyen vi cua A")
At
print("Ma tran chuyen vi cua B")
Bt
Ct = Bt %*% At
print("Tich cua A chuyen vi va B chuyen vi")
Ct
C
#### nhan xet: Ct la ma tran chuyen vi cua ma tran C
### 1.4
one_matrix = t(matrix(data = c(1,1,1), nrow = 1, ncol = 3, byrow = T))
#### giai phuong trinh A.X = one_matrix => X = A^-1 . one_matrix
A_inverse = solve(A)
A_inverse
X = A_inverse %*% one_matrix
X ## X la ma tran 3x1
A %*% X ## dung de kiem tra lai ket qua

##------------------------------------------------------------
## Bai 2:
### 2.1
year = c(1970:1979)
snow.cover = c(6.5, 12.0, 14.9, 10.0, 10.7, 7.9, 21.9, 12.5, 14.5, 9.2)
df.snow = data.frame(year, snow.cover)
df.snow
### 2.2
plot(year, snow.cover, main = "Bieu do phan tan cua snow.cover theo year")
cor_ = cor(year, snow.cover)
print("He so tuong quan cua year va snow.cover")
cor_
#### nhan xet: year va snow.cover tuong quan dong bien nhung kha yeu
### 2.3
layout(matrix(data= c(1,2), ncol = 2, nrow = 1, byrow = T))
hist(snow.cover, freq = F); hist(snow.cover, freq = T)
### 2.4
layout(matrix(data = c(1), nrow = 1, ncol = 1))
boxplot(snow.cover, horizontal = T, outline = T, main = "Boxplot cua snow.cover")
summary(snow.cover)
##------------------------------------------------------------

## Bai 3:
### 3.1
data = read.csv("data01.csv")
data
### 3.2
attach(data)
Index = as.numeric(as.vector(cut(data$Age, breaks = c(0,60,70,80, Inf), labels = c(0, 1, 2, 3), right = FALSE)))
Index
### 3.3
pie(table(Index), main = "Bieu do tron cho Index")
barplot(table(Index), main = "Bieu do cot cho Index")

### 3.4
barplot(table(K, Index), beside = T, legend.text = c("K = 0", "K = 1"), main = "Bieu do cot kep cua Index va K")
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

phuongsai(FPSA) # dung ham tinh
sd(FPSA) ^ 2 # dung de so sanh

# vay phuong sai tinh bang ham va phuong sai tinh bang thu vien bang nhau

##------------------------------------------------------------

## Bai 4:

#### 4.1
phanvi = function(X, p) {
  X_sorted = sort(X)
  n = length(X)
  i = (p * n) / 100
  if (i - as.integer(i) == 0) {
    return ((X[i] + X[i + 1]) / 2)
  }
  else 
    return(X[round(i)])
}
x = c(1,2,3,4,5,6,7)
phanvi(x, 50)

#### 4.2
data("iris")
x = iris
p_0 = 02
phanvi(x$Petal.Length, p_0)

## y nghia: phan vi thu p_0 trong chieu dai canh hoa trong tap du lieu iris
##------------------------------------------------------------

##**************************************************
## Ket thuc

