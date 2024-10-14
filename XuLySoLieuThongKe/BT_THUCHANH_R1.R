# ---- Description ----
# setwd to directory

# ---- load lib and data ----
library(ggplot2)
library(tidyverse)
library(nycflights13)

data(flights)
flights
glimpse(flights)

# ---- BT1 ----

# Đến nơi trễ từ hai giờ trở lên

flights |> filter(arr_delay > 2*60)

# Bay tới Houston (IAH hoặc HOU)

flights |> filter(dest %in% c('IAH', 'HOU')) |> relocate('dest')

# Được điều hành bởi United, American hoặc Delta

flights |> filter(carrier %in% c('UA', 'AA', 'DL')) |> relocate(carrier)

# Khởi hành vào mùa hè (tháng 7, tháng 8, tháng 9)

flights |> filter(month %in% c(7, 8, 9)) |> relocate(month)

# Đến muộn hơn hai tiếng nhưng không cất cánh muộn

flights |> filter(arr_delay > 2 * 60 & dep_delay <= 0) |> relocate(arr_delay, dep_delay)

# Bị trì hoãn ít nhất một giờ nhưng lại kéo dài hơn 30 phút trên chuyến bay

flights |> filter(dep_delay > 60 & dep_delay - arr_delay > 30) |> relocate(dep_delay, arr_delay)




# ---- BT2 ----
# Sắp xếp flights để tìm chuyến bay có thời gian khởi hành trễ nhất. Tìm các chuyến bay khởi
# hành sớm nhất vào buổi sáng.

flights |> arrange(desc(dep_delay)) |> arrange(sched_dep_time) |> relocate(dep_delay, sched_dep_time)

# ---- BT3 ----
# Sắp xếp flights để tìm chuyến bay có vận tốc nhanh nhất. (Gợi ý: Hãy thử đưa phép tính toán
# vào bên trong hàm của bạn.)

flights |> mutate(speed = distance / air_time) |> arrange(desc(speed)) |> relocate(speed)

# ---- BT4 ----
# Các chuyến bay hàng ngày trong năm 2013, đúng hay không?

flights |> filter(year == 2013) |> distinct(year, month, day) |> nrow()

# ---- BT5 ----
#Chuyến bay nào đi được quãng đường xa nhất? Chuyến nào đã đi được quãng đường ngắn nhất?

flights |> arrange(desc(distance)) |> relocate(distance)
flights |> arrange(distance) |> relocate(distance)

# 
# ---- BT6 ----
# So sánh các biến dep_time, sched_dep_time và dep_delay, liệu chúng có mối liên hệ nào với nhau.
# thời gian cất cánh thực tế dep_time = sched_dep_time + dep_delay

# tao ham chuyen doi hh:mm sang so phut, sau do cong so phut tre, chuyen ket qua lai thanh hh:mm

trans_time_delay <- function(sched, delay){
  temp <- sched %/% 100 * 60 + sched %% 100 + delay
  res <- temp %/% 60 * 100 + temp %% 60
  res <- if_else(res > 2400, res - 2400, res)
  return(res)
}

flights_guess <- flights |>
  mutate(dep_time_guess = trans_time_delay(sched_dep_time, dep_delay)) |>
  relocate(dep_time, dep_time_guess, sched_dep_time, dep_delay)

# kiem tra
all.equal(flights_guess$dep_time_guess, flights_guess$dep_time)

# ---- BT7 ----

#Tìm hiểu các hàm starts_with, ends_with, contains(). Áp dụng chúng vào trong nhiệm vụ
#lựa chọn các cột dep_time, dep_delay, arr_time và arr_delay

# dùng như pattern starts_with là bắt đầu với, ends_with là kết thúc với, contains là chứa

flights |> select(starts_with(c("arr", "dep")))
flights |> select(ends_with(c("_delay", "_time")), -contains('sched'))


# ---- BT8 ----

# Hàm any_of() làm gì? Tại sao nó có thể hữu ích khi kết hợp với vectơ này?

variables <- c("year", "month", "day", "dep_delay", "arr_delay")

# co tac dung khi lua chon cac cot ma xuan hien trong variables, du variables co cot k nam trong du lieu cung k bi loi
flights |> select(any_of(variables))



# ---- BT9 ----
# Tại sao đoạn chương trình sau không hoạt động? Lỗi được báo có ý nghĩa gì?

flights |> select(tailnum) |>
  arrange(arr_delay)

# bi loi do chi select tailnum nen cac cot khac k con, neu muon sap theo arr_delay can chi dinh .keep_all = TRUE

# ---- BT10 ----
# Đổi tên cột air_time thành air_time_min để chỉ rõ đơn vị đo, đồng thời, di chuyển cột này
# về vị trí bắt đầu của bảng dữ liệu.

flights |> select(air_time_min = air_time) |> relocate(air_time_min)
