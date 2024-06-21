##
## Bai kiem tra 4- Thuc hanh Ly thuyet Thong ke
## Lop: CT3 ca 1
##
## Ho ten: Lý Quang Thắng - MSSV: 22110202
##
##**************************************************
## Bai 1:
# 1.1
weights = read.csv("weights.csv")
weights

summary(weights)

hist(weights$Weight, main = "histogram of weights", col = "green")
boxplot(weights$Weight, main = "boxplot of weights", col = "green", horizontal = TRUE)
# nhan xet: trung binh cac sp la 50.0, box o giua nho -> trong luong cac san pham nhat quan, cac diem du lieu 
# trai deu trong khoang, ko co gia tri ngoai lai
# 1.2

# H0: p <= 30%
# H1: p > 30%

# 1.3
khongDatYC = weights$Weight[weights$Weight < 50]
y = length(khongDatYC)
## cach 1
prop.test(y, length(weights$Weight), p = 0.3, alternative = "greater", conf.level = 0.95)

# voi pvalue = 0.14 > 0.05 = alpha => khong bac bo H0 => ti le san pham khong dat yeu cau ko vuot qua 30%

## cach 2
p.hat = length(khongDatYC) / length(weights$Weight)

z0 = (p.hat - 0.3) / sqrt((0.3 * (1 - 0.3)) / length(weights$Weight))

if (z0 > qnorm(1-0.05)) {
  print("Bac bo H0")
} else { 
  print("Khong bac bo H0")
}

# 1.4

test.twoside = function(f, n, p0, alpha) {
  # H0 : p = p0
  # H1 : p # p0
  p.hat= f / n
  z0 = (p.hat - p0) / sqrt( (p0) * (1 - p0) / n )
  if (z0 > qnorm(1-alpha / 2)) {
    print("Bac bo H0")
  }
  else {
    print("Khong bac bo H0")
  }
  pvalue = 2 * (1 - pnorm(abs(z0)))
  return (pvalue)
}

test.twoside(length(khongDatYC), length(weights$Weight), 0.3, 0.05)
##-----------------------------------------------------------
## Bai 2:

# 2.1
satisfaction = read.csv("satisfaction.csv")
A = satisfaction$Satisfaction[satisfaction$Store == "A"]
B = satisfaction$Satisfaction[satisfaction$Store == "B"]
#2.2

# H0: mu1 = mu2
# H1: mu1 # mu2
# 2.3
alpha = 0.05
var.test(A, B)
# do p-value = 0.1211 > 0.05 = alpha nen phuong sai hai tong the ko bang nhau
t.test(A, B, alternative = "two.sided" , conf.level = 0.95, var.equal=FALSE)
# Do Pvalue = 0.7125 > 0.05 = alpha nen khong bac bo H0 => muc do hai long trung binhgiua hai cua hang A va B
# la ko sai khac voi muc y nghia alpha = 5%

# 2.4

# H0: mu >= 4
# H1: mu < 4

danhgia = satisfaction$Satisfaction
t.test(danhgia, mu = 4, alternative = "less", conf.level = 0.95)

# pvalue = 0.8481 > alpha = 0.05 => khong bac bo H0 => trung binh diem danh gia muc do hai long cua cua hang
# lon hon bang 4 voi muc y nghia alpha = 5%

##-----------------------------------------------------------

##**************************************************
## Ket thuc