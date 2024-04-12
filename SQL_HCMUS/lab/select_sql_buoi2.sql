USE Csdl_Congty;

-- Q1: Liệt kê họ tên, ngày sinh, giới tính, địa chỉ tất cả các nhân viên của phòng số 5.

SELECT HoNV, DEM, TenNV, NgaySinh, GioiTinh, DiaChi, MaPB 
FROM NHANVIEN
WHERE MaPB = 5;

-- Q2: Lập danh sách các phòng ban của công ty

SELECT pb.*, tsp.TruSo
FROM PHONGBAN pb, TRUSO_PHONG tsp
WHERE pb.MaPB = tsp.MaPB;

-- Q3: Cho biết mã số, họ tên của các nhân viên phòng Nghiên cứu có mức lương từ 25,000 đến 45,000.
-- Sắp xếp theo mức lương giảm dần, mã số tăng dần.

SELECT nv.*, pb.TenPB
FROM NHANVIEN nv, PHONGBAN pb
WHERE nv.MaPB = 5 AND (nv.Luong BETWEEN 25000 AND 45000) AND nv.MaPB = pb.MaPB
ORDER BY nv.Luong DESC, nv.MaNV ASC;

-- Q6: Lập danh sách mã số các nhân viên không có người thân nào. Sắp xếp kết quả theo thứ tự tăng dần của mã số.

