# Change direction
# getwd()
# setwd("/home/thangquang/Documents/code/HCMUS/R_programing")
#---------- File ----------
data <- read.csv("DataExcel.csv")
data
str(data) 
?str
attach(data)
z <- data$T1
z <- T1
T1
z
dim(data) # 100 56
# save(data, file="data.rda")
# dr = load("data.rda")

#---------- Plot ----------
TanSoKV <- table(KV)
pie(TanSoKV)

DanhGiaT1 <- T1
DanhGiaT1
DanhGiaT1[T1 < 5] <- "Kem"
DanhGiaT1[T1 >= 5 & T1 < 7] <- "Trung binh"
DanhGiaT1[T1 >= 7 & T1 < 8] <- "Kha"
DanhGiaT1[T1 >= 8] <- "Gioi"
DanhGiaT1
TanSoT1 <- table(DanhGiaT1)
TanSoT1
pie(TanSoT1)

?barplot
barplot(TanSoT1)


#--------Bai tap--------
# 1.1
CoBan = c(4,15,24,10,1,27,31,14,2,16,32,7,13,36,29,6,12,18,14,15,18,6,13,21,20,8,3,24)
Moi = c(5,20,29,15,7,32,36,17,15,19,35,10,16,39,27,14,10,16,12,13,16,9,18,33,30,29,31,27)
layout(matrix(1:4, nrow = 2, byrow = T))
hist(CoBan); hist(CoBan, freq = F)
hist(Moi); hist(Moi, fre = F)

# 1.2
Chung = c(CoBan, Moi)
layout(matrix(1:2, nrow = 1, byrow = T))
hist(Chung); hist(Chung, freq = T)

# 1.3
DuLieu = c(55,70,85,65,90,50,60,110,90,115,90,75,55,85,70,8,5,23,31,50)
mean(DuLieu); median(DuLieu)
,
(TanSoDuLieu = table(DuLieu))
DuLieu

(as.numeric(names(TanSoDuLieu))[TanSoDuLieu == max(TanSoDuLieu)])

# 1.4
DuLieu2 = c(55,70,85,65,90,50,60,345,90,467,90,75,55,85,70,8,5,23,31,50)
list(tb = mean(DuLieu2), trungvi = median(DuLieu2))
(TanSoDuLieu = table(DuLieu2))
(as.numeric(names(TanSoDuLieu))[TanSoDuLieu == max(TanSoDuLieu)])

# Trung bình có thể bị ảnh hưởng bởi outlayer
# Trung vị thì không ảnh hưởng

# 1.5
mean(DuLieu, trim = .1); mean(DuLieu2, trim =.1)
mean(DuLieu, trim = .05); mean(DuLieu2, trim = .05)

# 1.6
Nam = c(6,3,10,4,4,2,4,7)
mean(Nam); var(Nam); sd(Nam)

# 1.7
Tuoi = c(39,38,31,26,18,36,20,31)
mean(Tuoi); var(Tuoi); sd(Tuoi)
# Độ phân tán của tuổi lớn hơn độ phân tán của Nam

# 1.8
TG = c(21,20,31,24,15,21,24,18,33,8,26,17,27,29,24,14,29,41,15,11,
       13,28,22,16,12,15,11,16,18,17,29,16,24,21,19,7,16,12,45,24,
       21,12,10,13,20,35,32,22,12,10)
boxplot(TG)
quantile(TG, probs=.25)
