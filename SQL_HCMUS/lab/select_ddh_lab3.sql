use Csdl_DonDatHang;

-- 1. Cho biết mã số, họ tên, email của các nhà cung cấp ở Germany.

SELECT MaNCC, TenNCC, Email
FROM
    NHACUNGCAP
WHERE
    QuocGia = "Germany";

-- 2. Cho biết mã số, họ tên, số điện thoại của các khách hàng có tên bắt đầu bằng chữ L 
-- (ví dụ Elizabeth Lincoln, Maria Larsson, …).

SELECT MaKH, HoTen, SoDT
FROM
    KHACHHANG
WHERE
    HoTen LIKE '% L%';

-- 3. Tìm các đơn đặt hàng trong tháng trước thời điểm hiện tại 3 tháng.

SELECT * 
FROM
    DONDATHANG
WHERE
    NgayDathang = DATE_SUB(NOW(), INTERVAL 3 MONTH);

-- 4: Với các nhà cung cấp ở Germany, cho biết mã số, tên nhà cung cấp và mã số, 
-- tên các mặt hàng của họ.

SELECT ncc.MaNCC, ncc.TenNCC, mh.TenMH, ncc.QuocGia
FROM
    NHACUNGCAP ncc, MATHANG mh
WHERE
    ncc.QuocGia = 'Germany' AND ncc.MaNCC = mh.MaNCC;

-- 5. Cho biết mã số, tên, đơn giá của các mặt hàng được đặt hàng trong tháng 07/2012. 
-- Sắp xếp theo thứ tự giảm dần của đơn giá.

SELECT mh.MaMH, mh.TenMH, mh.DonGia, ddh.NgayDathang
FROM
    DONDATHANG ddh, CHITIETDDH cddh, MATHANG mh
WHERE
    ddh.MaDDH = cddh.MaDDH AND cddh.MaMH = mh.MaMH AND ddh.NgayDathang LIKE '2012-07% %'
ORDER BY
    mh.DonGia DESC;

-- 6. Cho biết mã số của các mặt hàng không có đơn đặt hàng trong tháng 07/2012.

SELECT MaMH
FROM
    MATHANG
WHERE
    MaMH NOT IN (
        SELECT mh.MaMH
        FROM
            DONDATHANG ddh, CHITIETDDH cddh, MATHANG mh
        WHERE
            ddh.MaDDH = cddh.MaDDH AND cddh.MaMH = mh.MaMH AND ddh.NgayDathang LIKE '2012-07% %'
    );
