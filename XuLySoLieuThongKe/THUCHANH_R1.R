# ---- bat dau ----
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
## data_name |> filter(dieu_kien_feature)

# lọc ra các chuyến bay có thời gian delay (dep_delay) nhiều hơn 120 phút
flights_delay_120 <- flights |> filter(dep_delay > 120)
flights_delay_120






