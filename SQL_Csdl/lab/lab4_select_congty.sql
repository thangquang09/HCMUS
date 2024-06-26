-- DBMS: MySQL
use Csdl_Congty;

-- Q1: Với mỗi phòng ban, cho biết tên phòng, tổng số nhân viên, mức lương cao nhất, mức lương thấp nhất.

SELECT pb.TenPB, count(nv.MaNV) as "TongNhanVien", max(nv.Luong) as "LuongCaoNhat", 
min(nv.Luong) as "LuongThapNhat"
FROM
    PHONGBAN AS pb JOIN NHANVIEN as nv ON pb.MaPB = nv.MaPB
GROUP BY
    pb.MaPB;

-- Q2: - Lập danh sách mã số, tên dự án và tổng số nhân viên đang làm việc cho các dự án được triển khai ở
-- Phú Nhuận.

SELECT da.MaDA, da.TenDA, count(tg.MaNV) AS TongSoNhanVien
FROM
    THAMGIA tg JOIN DUAN da ON da.MaDA = tg.MaDA AND da.DiaDiem = "Phu Nhuan"
GROUP BY
    da.MaDA, da.TenDA;

-- Q3: - Yêu cầu tương tự Q2 nhưng thêm điều kiện để
-- lọc ra các dự án có nhiều hơn 2 nhân viên.

SELECT da.MaDA, da.TenDA, count(tg.MaNV) AS TongSoNhanVien
FROM
    THAMGIA tg JOIN DUAN da ON da.MaDA = tg.MaDA AND da.DiaDiem = "Phu Nhuan"
GROUP BY
    da.MaDA, da.TenDa
HAVING TongSoNhanVien > 2;

-- Q4: - Lập danh sách các nhân viên có mức lương cao nhất.

SELECT MaNV, HoNV, Dem, TenNV, Luong
FROM
    NHANVIEN
WHERE
    Luong = (
        SELECT MAX(Luong)
        FROM
            NHANVIEN
    );

-- Q5: Lập danh sách các phòng ban mà các nhân viên có mức lương không thấp hơn 30,000.

SELECT *
FROM PHONGBAN pb
WHERE not exists (SELECT * FROM NHANVIEN n WHERE n.MaPB = pb.MaPB AND Luong < 30000);