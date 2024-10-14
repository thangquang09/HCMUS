# ---- libraby ----
library(nycflights13)
library(tidyverse)
data(flights)
glimpse(flights)
# ---- Thong ke tong hop cho bien dinh luong ----
flights |> summarise(tb = mean(dep_delay), dlc = sd(dep_delay))
# return NA boi vi co gia tri NA trong data, fix bang cach them na.rm=TRUE
flights |> summarise(tb = mean(dep_delay, na.rm=TRUE), dlc = sd(dep_delay, na.rm=TRUE))

# ---- BT1 ----
flights |> summarise(
    trung_vi = median(dep_delay, na.rm=TRUE),
    giatrilonhat = max(dep_delay, na.rm=TRUE),
    giatrinhonhat = min(dep_delay, na.rm=TRUE),
    iqr = IQR(dep_delay, na.rm=TRUE)
  )

flights |> summarise(
  trung_vi = median(arr_delay, na.rm=TRUE),
  giatrilonhat = max(arr_delay, na.rm=TRUE),
  giatrinhonhat = min(arr_delay, na.rm=TRUE),
  iqr = IQR(arr_delay, na.rm=TRUE)
)

flights |> summarise(
  trung_vi = median(air_time, na.rm=TRUE),
  giatrilonhat = max(air_time, na.rm=TRUE),
  giatrinhonhat = min(air_time, na.rm=TRUE),
  iqr = IQR(air_time, na.rm=TRUE)
)

flights |> summarise(
  trung_vi = median(distance, na.rm=TRUE),
  giatrilonhat = max(distance, na.rm=TRUE),
  giatrinhonhat = min(distance, na.rm=TRUE),
  iqr = IQR(distance, na.rm=TRUE)
)


# ---- BT2 ----

data <- read_csv('datasets/state.csv')
data

data |> summarise(
  tb = mean(Population, na.rm=TRUE),
  dlc = sd(Population, na.rm=TRUE),
  trungvi = median(Population, na.rm=TRUE),
  max_val = max(Population, na.rm=TRUE),
  min_val = min(Population, na.rm=TRUE),
  iqr = IQR(Population, na.rm=TRUE)
)


# ---- Thống kê tổng hợp cho nhiều biến định lượng ----
data_birth = read_table(file="datasets/birthwt.txt")
data_birth

# mutate category columns
data_birth <- data_birth |> mutate(
  race = factor(race, labels=c('white', 'black', 'other')),
  smoke = factor(smoke, labels=c('no', 'yes'))
)
glimpse(data_birth)

# summarise + accross để tính các ước lượng thống kê
df_sum <- data_birth |> summarise(
  across(
    c("bwt", "lwt", "age"),
    list(gtnn=min, gtln=max, tv=median, tb=mean, dlc=sd)
  )
)
df_sum

# tạo ra bảng dễ nhìn hơn

df_stats_tidy <- df_sum |> gather(ten, gt) |>
  separate(ten, into = c("bien", "tk"), sep = "_") |>
  spread(tk, gt) |>
  select(bien, gtnn, tv, tb, dlc)
print.data.frame(df_stats_tidy, digits=4)

# ---- BT3 ---- 
# Tạo bảng kết quả tổng hợp cho các biến dep_delay, arr_delay, air_time, theo các tháng khác nhau.

flights_summary <- flights |> group_by(month) |> summarise(
  across(
    c("dep_delay", "arr_delay", "air_time"),
    list(gtnn=~min(.x, na.rm = TRUE), 
         gtln=~max(.x, na.rm = TRUE), 
         tv=~median(.x, na.rm = TRUE), 
         tb=~mean(.x, na.rm = TRUE), 
         dlc=~sd(.x, na.rm = TRUE))
  )
) |> arrange(month)
flights_summary
# ---- BT4 ----
pima = read_csv("datasets/Pima.csv")
pima <- pima |> mutate(
  type = factor(type, labels = c("No", "Yes"))
)
pima

pima |> summarise(tb=mean(glu, na.rm=TRUE),
                  gtln=max(glu, na.rm=TRUE),
                  gtnn=min(glu, na.rm=TRUE),
                  tv=median(glu, na.rm=TRUE))

pima_sum <- pima |> summarise(
  across(
    c("glu", "bmi", "age"),
    list(
      tb=mean,
      tv=median,
      gtln=max,
      gtnn=min,
      dlc=sd
    )
  )
)
pima_stats <- pima_stats |> gather(ten, gt) |>
  separate(ten, into = c("bien", "tk"), sep = "_") |>
  spread(tk, gt) |>
  select(bien, tb, tv, gtln, gtnn, dlc)
print.data.frame(df_stats_tidy, digits=4)

# ---- Thống kê tổng hợp cho nhiều biến định lượng phân theo nhóm ----

data_birth |> group_by(race) |>
  summarise(n = n(), tb = mean(bwt), dlc = sd(bwt))
# ---- BT5 ----
data_birth |> group_by(smoke) |>
  summarise(
    n(),
    tb=mean(bwt),
    tv=median(bwt),
    dlc=sd(bwt)
  )

data_birth |> group_by(race, smoke) |>
  summarise(
    n(),
    tb=mean(bwt),
    tv=median(bwt),
    dlc=sd(bwt)
  )

# ---- BT6 ----

# Xét dữ liệu flights. Hãy tạo các bảng tổng hợp phù hợp để trả lời các câu hỏi sau:
# Số phút cất cánh trễ của chuyến bay là giống nhau cho các sân bay đi?

df1 <- flights |> mutate(dep_delay_minutes = (dep_delay %/% 100) * 60 + (dep_delay %% 100)) |>
  group_by(origin) |>
  summarise(
    avg_minutes=mean(dep_delay_minutes, na.rm=TRUE),
    med_minutes=median(dep_delay_minutes, na.rm=TRUE),
    sd_minutes=sd(dep_delay_minutes, na.rm=TRUE),
    max_minutes=max(dep_delay_minutes, na.rm=TRUE),
    min_minutes=min(dep_delay_minutes, na.rm=TRUE)
  )
df1

df2 <- flights |> mutate(dep_delay_minutes = (dep_delay %/% 100) * 60 + (dep_delay %% 100)) |>
  filter(dep_delay_minutes > 0) |> 
  group_by(month) |>
  summarise(
    delay_count=n()
  ) |>
  arrange(desc(delay_count))
df2

delay_sum_carrier_origin <- flights |> mutate(dep_delay_minutes = (dep_delay %/% 100) * 60 + (dep_delay %% 100)) |>
  filter(dep_delay_minutes > 0) |>
  group_by(carrier, origin) |>
  summarise(
    avg_minutes=mean(dep_delay_minutes, na.rm=TRUE),
    med_minutes=median(dep_delay_minutes, na.rm=TRUE),
    sd_minutes=sd(dep_delay_minutes, na.rm=TRUE)
  )
delay_sum_carrier_origin
# ---- Biểu diễn cho biến định lượng ----

#ggplot(data = ten_du_lieu,
#       mapping = aes(x = ten_bien_o_truc_x, y = ten_bien_truc_y,
#                     cac_doi_so_khac)) +
#  \\ các hàm vẽ đối tượng: histogram, boxplot, bar_plot +
#  \\ các hàm hiệu chỉnh hình

# Bieu do tan so va bieu do hop

ggplot(data=data_birth, aes(x=bwt))+geom_histogram(fill="white", color="black", bins=10)

ggplot(data=data_birth, aes(y=bwt)) + geom_boxplot()

