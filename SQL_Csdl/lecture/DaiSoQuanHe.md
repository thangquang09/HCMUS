- [1. Đại số quan hệ](#1-đại-số-quan-hệ)
  - [1.1. Khái niệm](#11-khái-niệm)
  - [1.2. Một số phép toán](#12-một-số-phép-toán)
- [2. Các phép toán quan hệ một ngôi](#2-các-phép-toán-quan-hệ-một-ngôi)
  - [2.1. Phép toán chọn](#21-phép-toán-chọn)
  - [2.2. Phép toán chiếu](#22-phép-toán-chiếu)
    - [2.2.1. Phép toán chiếu tổng quát](#221-phép-toán-chiếu-tổng-quát)
  - [2.3. Biểu thức đại số quan hệ](#23-biểu-thức-đại-số-quan-hệ)
  - [2.4. Phép toán đổi tên](#24-phép-toán-đổi-tên)
- [3. Các phép toán tập hợp](#3-các-phép-toán-tập-hợp)
- [4. Các phép toán quan hệ hai ngôi](#4-các-phép-toán-quan-hệ-hai-ngôi)
- [5. Các phép toán khác](#5-các-phép-toán-khác)
- [6. Các thao tác cập nhật dữ liệu](#6-các-thao-tác-cập-nhật-dữ-liệu)


## 1. Đại số quan hệ

### 1.1. Khái niệm

Đại số quan hệ là tập hợp các phép toán cơ bản của mô hình quan hệ. Các phép toán này cho phép người dùng chỉ định các yêu cầu truy xuất dữ liệu.

Kết quả của phép toán là một quan hệ mới, được hình thành từ một hoặc nhiều quan hệ đầu vào.

Một chuỗi các phép toán đại số quan hệ tạo thành một **biểu thức đại số quan hệ**. Trong đó kết quả của một biểu thức quan hệ cũng là một quan hệ biểu diễn kết quả của một yêu cầu truy suất dữ liệu.

### 1.2. Một số phép toán

- Phép toán quan hệ một ngôi: `chọn`, `chiếu`, `đổi tên`.
- Phép toán tập hợp:`hội`, `giao`, `hiệu`, `tích Descartes`.
- Phép toán quan hệ hai ngôi: `kết`, `chia`.
- Phép toán khác: `kết ngoài`, `outer union`, `hàm tổng hợp`.

## 2. Các phép toán quan hệ một ngôi

### 2.1. Phép toán chọn

**Phép toán chọn** (select) để chọn một tập con các bộ dữ liệu từ một quan hệ dựa trên một **điều kiện chọn**. Ký hiệu $\sigma$ (sigma).

Cho $R$ là một quan hệ: phép toán chọn biễu diễn như sau:

$$
\sigma_{\text{<điều kiện chọn>}}(R)
$$

Điều kiện chọn là một biểu thức luận lý gồm các mệnh đề quan hệ có dạng: `<thuộc tính> <phép toán so sánh> <hằng>`, hoặc  `<thuộc tính> <phép toán so sánh> <thuộc tính>`.

Phép toán so sánh gồm: $=, <, \leq, >, \geq, \neq$.

**Q1:** Lập danh sách nhân viên của bộ phận có mã số là 4 và mức lương trên 30.000.

$$
\sigma_{\text{Dno = 4 and Salary > 3000}}(\text{EMPLOYEE})
$$

Phép toán chọn có các tính chất sau: 
- Kết quả là một quan hệ có lược đồ giống như $R$, nghĩa là giống về số lượng thuộc tính và tên thuộc tính.
- Giao hoán: 

$$
\sigma_{<dk1>} (\sigma_{<dk2>}(R)) = \sigma_{<dk2>} (\sigma_{<dk1>}(R))
$$

Số bộ của quan hệ kết quả nhỏ hơn hoặc bằng quan hệ số bộ của quan hệ $R$.

### 2.2. Phép toán chiếu

**Phép toán chiếu** (project) để chiếu quan hệ lên một số thuộc tính nhất định. Ký hiệu là $\pi$. 

Nếu xem quan hệ như một bảng thì phép chiếu sẽ chọn ra một số cột nhất định và loại bỏ các cột khác.

$$\pi_{<\text{danh sách các thuộc tính}>}(R)$$

Trong đó $R$ là một quan hệ. Danh sách các thuộc tính chiếu là các thuộc tính chọn từ quan hệ $R$.

**Q2:** Cho biết các phòng của công ty.

$$
\pi_{\text{Dname, Dnumber, Mgrssn, Mgrstartdate}}(\text{DEPARTMENT})
$$

Phép toán chiếu có các tính chất sau:

- Kết quả là một quan hệ có lược đồ với số lượng thuộc tính và tên các thuộc tính giống như trong *danh sách thuộc tính chiếu*.
- Không có tính giao hoán.
- Số bộ của quan hệ kết quả nhỏ hơn hoặc bằng số bộ của quan hệ $R$.
- Quan hệ kết quả không chứa các bộ giống nhau.

#### 2.2.1. Phép toán chiếu tổng quát

**Phép toán chiếu tổng quát** là phép toán chiếu cho phép áp dụng các hàm hoặc biểu thức tính toán với các thuộc tính trong danh sách thuộc tính chiếu.

$$
\pi_{F_1, F_2, F_3, ..., F_n} (R)
$$

**Q3:** Lập danh sách mã số, mức lương và mức đóng bảo hiểm của tất cả các nhân viên. Biết mức đóng bảo hiểm bằng 28% mức lương.

$$
\pi_{\text{Ssn, Salary, 0.28 * Salary}}(\text{EMPLOYEE})
$$

### 2.3. Biểu thức đại số quan hệ

Hầu hết các truy vấn dữ liệu cần áp dụng lần lượt một số phép toán đại số quan hệ.

Các phép toán có thể được áp dụng *kết hợp lồng nhau* tạo thành một **biểu thức đại số quan hệ**. 

Các phép toán cũng có thể sử dụng *đơn lẻ, tuần tự* và tạo ra các quan hệ chứa kết quả trung gian. Trong trường hợp này phải đặt tên cho các quan hệ chứa kết quả trung gian.

**Q4:** Cho biết họ tên của các nhân viên có mức lương trên 30.000.

$$
\pi_{\text{Fname, Lname}} (\sigma_{\text{Salary > 30000}}(\text{EMPLOYEE}))
$$

**Phép gán**: dùng để lưu kết quả của một phép toán vào một tên biến quan hệ tạm thời, ký hiệu: $\leftarrow$

$$
Q \leftarrow \sigma_{\text{Salary > 30000}}(\text{EMPLOYEE})
$$

### 2.4. Phép toán đổi tên

**Phép toán đổi tên** (rename) để đổi tên thuộc tính, quan hệ. Ký hiệu $\rho$. Đổi tên quan hệ $R(A_1, A_2, ..., A_n)$ thành $S(B_1, B_2, ..., B_n)$

$$
\rho_{S(B_1, B_2, ..., B_n)}(R)
$$

Đổi tên quan hệ $R$ thành $S$

$$
\rho_S(R)
$$

Đổi tên các thuộc tính thành $B_1, B_2, ..., B_n$.

$$
\rho_{(B_1, B_2, ..., B_n)}(R)
$$

Một số trường hợp cần sử dụng

- Khi áp dụng phép toán với hai quan hệ có thuộc tính trùng tên để tránh nhập nhằng.
- Đặt tên thuộc tính cho quan hệ kết quả khi áp dụng hàm tập hợp.
- Khi áp dụng các phép toán tập hợp, kết tự nhiên.

$$
Q \leftarrow \sigma_{\text{Salary > 30000}}(\text{EMPLOYEE})
$$

$$
R \leftarrow \rho_{(\text{Fn, Ln})} (\pi_{\text{(Fname, Lname)}}(Q))
$$

## 3. Các phép toán tập hợp

## 4. Các phép toán quan hệ hai ngôi

## 5. Các phép toán khác

## 6. Các thao tác cập nhật dữ liệu

