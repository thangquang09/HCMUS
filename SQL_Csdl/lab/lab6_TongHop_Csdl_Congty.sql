-- use Csdl_Congty;
-- -- CO SO DU LIEU CONG TY
-- -- Phan 1: SELECT CO BAN
-- -- 1. Cho biết mã số, họ tên, ngày sinh của các nhân viên phòng số 4. 
-- SELECT 
--     MaNV, HoNV, Dem, TenNV, NgaySinh
-- FROM
--     NHANVIEN
-- WHERE
--     MaPB = 4;

-- -- 2. Tìm những nhân viên có mức lương trên 30,000. 
-- SELECT MaNV, HoNV, Dem, TenNV, Luong
-- FROM
--     NHANVIEN
-- WHERE
--     Luong > 30000;

-- -- 3. Tìm những nhân viên có mức lương trên 25,000 ở phòng số 4 hoặc có mức
-- -- lương trên 30,000 ở phòng số 5.

-- SELECT MaNV, HoNV, Dem, TenNV, Luong, MaPB
-- FROM
--     NHANVIEN
-- WHERE
--     (Luong > 25000 AND MaPB = 4) OR (Luong > 30000 AND MaPB = 5);

-- -- 4. Cho biết họ tên, ngày sinh, địa chỉ của các nhân viên ở TpHCM. 

-- SELECT HoNV, Dem, TenNV, DiaChi
-- FROM
--     NHANVIEN
-- WHERE
--     DiaChi LIKE "% TpHCM";

-- -- 5. Cho biết ngày sinh, địa chỉ của nhân viên có tên là “Nguyen Bao Hung”. 

-- SELECT NgaySinh, DiaChi
-- FROM 
--     NHANVIEN
-- WHERE
--     CONCAT(HoNV, " ", Dem, " ", TenNV) = "Nguyen Bao Hung";

-- -- PHAN 2: Gom nhom, sap xep, ket ngoai
-- -- 18. Cho biết họ tên, mã phòng làm việc của các nhân viên và mã số các dự án
-- -- mà họ tham gia, sắp xếp tăng dần theo mã phòng, trong mỗi phòng sắp xếp
-- -- theo họ, tên với thứ tự alphabe. 

-- SELECT HoNV, Dem, TenNV, nv.MaPB, da.MaDA
-- FROM
--     NHANVIEN nv JOIN DUAN da ON nv.MaPB = da.MaPB
-- ORDER BY
--     nv.MaPB, HoNV;

-- -- 19. Cho biết tổng số nhân viên, mức lương cao nhất, mức lương thấp nhất và
-- -- mức lương trung bình của phòng “Nghien cuu”. 

-- SELECT COUNT(nv.MaNV), MAX(nv.Luong), MIN(nv.Luong), AVG(nv.Luong)
-- FROM
--     PHONGBAN pb JOIN NHANVIEN nv ON pb.MaPB = nv.MaPB AND pb.TenPB = "Nghien cuu"
-- GROUP BY
--     pb.MaPB;

-- -- 20. Với mỗi phòng, cho biết mã số phòng và tổng số nhân viên của phòng đó.

-- SELECT pb.MaPB, COUNT(nv.MaNV) AS "Tong nhan vien"
-- FROM
--     PHONGBAN pb JOIN NHANVIEN nv ON pb.MaPB = nv.MaPB
-- GROUP BY pb.MaPB;

-- -- 21. Với mỗi phòng, cho biết mã số phòng và mức lương trung bình của các
-- -- nhân viên của phòng đó. 

-- SELECT pb.MaPB, AVG(nv.Luong) as "Luong trung binh"
-- FROM
--     PHONGBAN pb JOIN NHANVIEN nv ON pb.MaPB = nv.MaPB
-- GROUP BY
--     pb.MaPB;

-- -- 22. Với mỗi dự án có nhân viên tham gia, cho biết mã số, tên và tổng số nhân
-- -- viên tham gia của dự án đó. 

-- SELECT da.MaDA, TenDA, COUNT(tg.MaNV) AS "Tong nhan vien"
-- FROM
--     DUAN da JOIN THAMGIA tg ON da.MaDA = tg.MaDA
-- GROUP BY
--     da.MaDA;

-- -- PHAN 3: TRUY VAN LONG
-- -- 29. Cho biết tên các dự án có nhân viên tham gia mang họ “Nguyen” hoặc
-- -- người trưởng phòng điều phối mang họ “Nguyen”. 

-- SELECT TenDA
-- FROM
--     DUAN da JOIN THAMGIA tg ON da.MaDA = tg.MaDA JOIN NHANVIEN nv ON nv.MaNV = tg.MaNV
-- WHERE
--     nv.MaNV IN (
--         SELECT MaNV
--         FROM NHANVIEN
--         WHERE
--             HoNV = "Nguyen"
--     )
--     OR
--     nv.MaNV IN (
--         SELECT MaNV
--         FROM NHANVIEN nv JOIN PHONGBAN pb ON nv.MaPB = pb.MaPB AND nv.MaNV = pb.MaQL
--         WHERE
--             nv.HoNV = "Nguyen"
--     );

-- -- 30. Với mỗi phòng có mức lương trung bình lớn hơn 30,000, cho biết tên
-- -- phòng và tổng số nhân viên nữ của phòng đó. 

-- SELECT pb.TenPB, pb.MaPB, COUNT(CASE WHEN GioiTinh = "F" THEN 1 END) AS "TONG_NHAN_VIEN_NU", AVG(nv.Luong) as "Luong trung binh"
-- FROM
--     PHONGBAN pb JOIN NHANVIEN nv ON pb.MaPB = nv.MaPB
-- GROUP BY
--     pb.MaPB
-- HAVING AVG(nv.Luong) IN (
--         SELECT AVG(nv.Luong)
--         FROM
--             PHONGBAN pb JOIN NHANVIEN nv ON pb.MaPB = nv.MaPB
--         GROUP BY
--             pb.MaPB
--         HAVING AVG(nv.Luong) > 30000
-- )   AND TONG_NHAN_VIEN_NU > 0;

-- -- 31. Cho biết họ tên các nhân viên có trên 2 người thân. 


-- SELECT HoNV, Dem, TenNV
-- FROM
--     NHANVIEN
-- WHERE
--     MaNV IN (
--             SELECT MaNV
--             FROM THANNHAN
--             GROUP BY MaNV
--             HAVING COUNT(*) >= 2
--     );

-- -- 32. Cho biết họ tên các nhân viên không có người thân nào.

-- SELECT HoNV, Dem, TenNV
-- FROM
--     NHANVIEN
-- WHERE
--     MaNV NOT IN (
--             SELECT MaNV
--             FROM THANNHAN
--             GROUP BY MaNV
--     );

-- -- 33. Cho biết họ tên các trưởng phòng có ít nhất một người thân. 

-- SELECT HoNV, Dem, TenNV
-- FROM
--     PHONGBAN pb JOIN NHANVIEN nv ON pb.MaPB = nv.MaPB AND pb.MaQL = nv.MaNV
-- WHERE
--     MaNV IN (
--         SELECT MaNV
--         FROM THANNHAN
--         GROUP BY MaNV
--     );

-- CO SO DU LIEU CHUYEN BAY

use CsdlHangkhong;
-- Phan 1: SELECT co ban
-- 1. Cho biết các chuyến bay đi Đà Lạt (DAD). 
SELECT MaCB
FROM
    CHUYENBAY
WHERE
    GaDen = "DAD";

-- 2. Cho biết các loại máy bay có tầm bay lớn hơn 10,000km. 
SELECT * FROM MAYBAY WHERE TamBay > 10000;

-- 3. Tìm các nhân viên có lương nhỏ hơn 10,000. 

SELECT * FROM NHANVIEN
WHERE
    Luong < 10000;

-- 4. Cho biết các chuyến bay có độ dài đường bay nhỏ hơn 10.000km và lớn hơn 8.000km. 

SELECT *
FROM
    CHUYENBAY
WHERE
    DoDai BETWEEN 8000 AND 10000;

-- 5. Cho biết các chuyến bay xuất phát từ Sài Gòn (SGN) đi Ban Mê Thuộc (BMV). 

