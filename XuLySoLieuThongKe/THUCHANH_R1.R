# ---- bat dau ----
setwd('/home/thangquang/Documents/CODE/HCMUS/XuLySoLieuThongKe')
library(tidyverse)
library(ggplot2)

# ---- load data ----
data_students <- read_csv('datasets/students.csv')
data_students

# read data from online link
data_students <- read_csv("https://pos.it/r4ds-students-csv")
data_students

# ---- clean data ----

# hiệu chỉnh các giá trị khuyết về đúng định dạng của R là NA
data_students <- read_csv("datasets/students.csv", na=c("","NA", "N/A"))
data_students

# tên của features
library(janitor)
# clean name
data_students <- read_csv("datasets/students.csv", na=c("", "NA", "N/A")) |> clean_names()
data_students

# đổi kiểu dữ liệu - kiểm soát dữ liệu
data_students <- data_students |> mutate(age=parse_number(if_else(age == "five", "5", age)))
data_students

# lưu ý rằng biến phân loại phải được chuyển thành biến factor để có thể phân tích thống kê 
data_students <- data_students |> mutate(meal_plan=factor(meal_plan))
data_students

# mặc định hàm factor() sẽ xếp thứ tự của cấp độ của một nhân tố theo thứ tự bảng chữ cái 
levels(data_students$meal_plan)

# vậy ta có một pipeline để clean data
data_students <- read_csv('datasets/students.csv', na=c("NA", "", "N/A"))
data_students <- data_students |> clean_names() |> mutate(age=parse_number(if_else(age=="five", "5", age)))
data_students <- data_students |> mutate(meal_plan=factor(meal_plan))

data_students




# ---- read data from many csv file ----

# read_csv(list_path_file, id = "file")
## list_path_file: vector chứa các đường dẫn của các tập dữ liệu cần đọc
## id = "file" tạo ra cột mới có tên file vào trong bảng dữ liệu, nhầm chỉ rõ tên file dữ liệu gốc

sales_files <- c("datasets/01-sales.csv", "datasets/02-sales.csv", "datasets/03-sales.csv")
data_sales <- read_csv(sales_files, id="file")
data_sales

# ---- cac thao tac co ban tren du lieu
library(nycflights13)
data(flights)
flights

# để có thông tin tổng hợp về các cột của dataset này ta dùng glimpse().
glimpse(flights)

# để hiểu thêm thông tin chi tiết ta ?
?flights

# ---- lọc dữ liệu ----
## ---- data_name |> filter(dieu_kien_feature) ----

# lọc ra các chuyến bay có thời gian delay (dep_delay) nhiều hơn 120 phút
flights_delay_120 <- flights |> filter(dep_delay > 120)
flights_delay_120

# lọc các chuyến bay bị chậm trễ thời gian cất cánh trong tháng 3, lớn hơn hoặc bằng 30 phút

flights |> filter(dep_delay >= 30 & month == 3)

# lọc ra các chuyến bay trong tháng 6 hoặc tháng 7

flights |> filter(month == 6 | month == 7)

# ngoài ra có thể dùng toán tử %in% để thay thế cho month == 6 | month == 7

flights |> filter(month %in% c(6, 7))

## ---- lọc ra dữ liệu duy nhất ----

flights |> distinct(month)

flights |> distinct(origin, dest)

# thêm .keep_all = TRUE để giữ lại các cột khác trong quá trình lọc 

flights |> distinct(month, .keep_all = TRUE)

## ---- sắp xếp dữ liệu ----

flights |> arrange(dep_time)

flights |> arrange(desc(dep_time))

# sắp xếp dữ liệu theo nhiều tiêu chí

flights |> arrange(year, month, day, dep_time)

## ---- các thao tác với cột dữ liệu ----

# cu phap: data_name_new <- data_name |> mutate(ten_bien = gia_tri)

flights_2 <- flights |> mutate(gain = dep_delay - arr_delay)

glimpse(flights_2)

flights_2 <- flights |> mutate(
  gain=dep_delay - arr_delay,
  speed = distance / air_time * 60
)
glimpse(flights_2)


# thông thường các biến mới tạo sẽ được chèn vào sau cùng của bảng, nên để thuận tiện cho kiểm tra
# ta thêm .before=1

flights_3 <- flights |> mutate(
  gain = dep_delay - arr_delay,
  speed = distance / air_time * 60,
  .before = 1
)
flights_3

## ---- Lựa chọn theo tên biến ----

# ta dùng select()

flights_4 <- flights |> select(year, month, day) # chi dinh cu the ten cot
flights_4 <- flights |> select(year:day) # chon ra cac cot nam giua tu year den day

flights_4 <- flights |> select(!year:day) # bo ra cac cot tu year den day
flights_4 <- flights |> select(where(is.character)) # lay ra cac cot co kieu du lieu text

## ---- Đổi tên cột và di chuyển cột ----

# dùng rename(), cu phap: rename(new_name = old_name)

flights |> rename(depart_time = dep_time)

# để di chuyển cột dùng relocate(), cú pháp: relocate(columns_name, .before,=<> .after=.<>)

# mặc định không chỉ before và after sẽ đưa lên làm cột đầu tiên

flights |> relocate(air_time)
# them .before
flights |> relocate(air_time, .before = dep_time) # air_time dung truoc dep_time
# them .after
flights |> relocate(air_time, .after = day) # air_time dung sau day

# co the di chuyen nhieu cot cung 1 luc
flights |> relocate(air_time, origin, dest, distance)
