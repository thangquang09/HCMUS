-- phep toan outer join

use Csdl_Congty;

-- Q3: Lập danh sách mã số, tên phòng và tổng sốnhân viên của mỗi phòng.
-- • Do các ràng buộc mỗi nhân viên phải làm việc cho một phòng ban và mỗi phòng ban phải có một nhân viên là
-- trưởng phòng nên với câu hỏi truy vấn này sử dụng JOIN và OUTER JOIN đều cho cùng kết quả.

SELECT Pb.MaPB, Pb.TenPB, COUNT(Nv.MaNV) as "Tong so nhan vien"
FROM
    PHONGBAN as Pb LEFT JOIN NHANVIEN as Nv ON Pb.MaPB = Nv.MaPB
GROUP BY
    Pb.MaPB, Pb.TenPB
ORDER BY
    Pb.MaPB;

-- Q4: Lập danh sách mã số, tên phòng và tổng số dự án mà phòng điều phối.

SELECT Pb.MaPB, Pb.TenPB, COUNT(Da.MaDA) as "Tong so du an"
FROM
    PHONGBAN as Pb LEFT JOIN DUAN as Da ON Pb.MaPB = Da.MaPB
GROUP BY
    Pb.MaPB, Pb.TenPB;

-- Q5: Với mỗi nhân viên hãy cho biết mã số, tênnhân viên và tổng số người thân là nữ của nhânviên đó.

SELECT nv.MaNV, nv.TenNV, count(tn.TenTN) as "Tong nguoi than nu"
FROM
    NHANVIEN as nv LEFT JOIN THANNHAN as tn ON nv.MaNV = tn.MaNV AND tn.GioiTinh = "F"
GROUP BY
    nv.MaNV, nv.TenNV;

/*
Cu phap with:
_____________________________________________
with <ten bang tam> (<cot1>, <cot2>, ...)
as
(select ... dung de tao bang tam)
select chinh ... (sau lenh nay bang tam se bi xoa)
_____________________________________________

*/
-- Q6: Với mỗi nhân viên, hãy cho biết mã số, họ tên,
-- mức lương và độ chênh lệch với mức lương trungbình của công ty

WITH luong_trung_binh (LuongTB)
AS
(SELECT avg(Luong)
FROM NHANVIEN)

SELECT Nv.MaNV, HoNV, Dem, TenNV, Luong, LuongTB, ABS(Luong - LuongTB) as "Do chenh lech voi LTB"
FROM
    NHANVIEN as Nv, luong_trung_binh;

-- Q7: Lập danh sách nhân viên gồm mã số, họ tên, mức lương, mức lương trung bình của phòng ban
-- mà nhân viên làm việc, và mức lương trung bìnhcủa công ty

WITH Luong_CT(LuongTBCT)
AS
(SELECT avg(Luong)
FROM NHANVIEN),
Luong_PB(MaPB, LuongTB)
AS
(SELECT MaPB, avg(Luong)
FROM NHANVIEN
GROUP BY MaPB)

SELECT MaNV, HoNV, Dem, TenNV, Luong, LuongTB as "Luong tb phong ban", LuongTBCT as "Luong tb cong ty"
FROM
    NHANVIEN as nv JOIN Luong_PB as lpb ON nv.MaPB = lpb.MaPB JOIN Luong_CT;

-- Lam bai Lab 5 Assignment

/*
Thực hiện các yêu cầu truy xuất dữ liệu sau với cơ sở dữ liệu Csdl_DonDatHang trong bài tập Lab 2:

1. Cho biết mã số, tên của nhà cung cấp có cung cấp tất cả các mặt hàng.
2. Cho biết mã số, tên, đơn giá của mặt hàng xuất hiện trong tất cả các đơn đặt hàng của khách hàng có mã số 34.
3. Với mỗi măt hàng, hãy cho biết mã số, tên và tổng số khách hàng có đặt mua mặt hàng đó.
4. Với mỗi mặt hàng, hãy cho biết mã số, tên, tổng số đơn đặt hàng có mặt hàng đó và tổng số lượng đã bán.
5. Với mỗi mặt hàng, hãy cho biết mã số, tên, đơn giá niêm yết và độ chênh lệch giữa đơn giá niêm yết và trung bình đơn giá đặt hàng của mặt hàng đó.
*/

use Csdl_DonDatHang;

-- 1.

-- 2.
SELECT mh.MaMH, mh.TenMH, ctddh.DonGia, ddh.MaKH
FROM
    DONDATHANG as ddh LEFT JOIN CHITIETDDH as ctddh ON ddh.MaDDH = ctddh.MaDDH AND ddh.MaKH=34 JOIN MATHANG as mh ON ctddh.MaMH = mh.MaMH;
    

-- 3.
SELECT mh.MaMH, mh.TenMH, count(ddh.MaKH) as "Tong nguoi mua"
FROM
    MATHANG as mh LEFT JOIN CHITIETDDH as ctddh ON mh.MaMH = ctddh.MaMH LEFT JOIN DONDATHANG as ddh ON ctddh.MaDDH = ddh.MaDDH
GROUP BY mh.MaMH, mh.TenMH;

-- 4.

SELECT mh.MaMH, mh.TenMH, COUNT(ctddh.MaDDH) as "tong so don dat hang co mat", SUM(ctddh.SoLuong) as "tong so luong ban"
FROM MATHANG as mh LEFT JOIN CHITIETDDH as ctddh ON mh.MaMH = ctddh.MaMH
GROUP BY
    mh.MaMH, mh.TenMH;

-- 5.
WITH tb_dongia_dh(MaMH, tb_dongia)
as
(SELECT MaMH, avg(DonGia)
FROM CHITIETDDH
GROUP BY
    MaMH)

SELECT mh.MaMH, mh.TenMH, mh.DonGia, tb.tb_dongia, ABS(mh.DonGia - tb.tb_dongia) as "chenh lech"
FROM
    MATHANG AS mh LEFT JOIN tb_dongia_dh as tb ON mh.MaMH = tb.MaMH;