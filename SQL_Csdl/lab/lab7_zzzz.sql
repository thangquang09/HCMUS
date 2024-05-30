
-- Với mỗi phòng nhiều hơn 2 nhân viên, cho biết tên phòng và số nhân viên có mức lương trên 30000

SELECT pb.TenPB, COUNT(nv.MaNV) AS SoLuongNhanVien
FROM
    PHONGBAN pb JOIN NHANVIEN nv ON pb.MaPB = nv.MaPB
WHERE
    Pb.TenPB IN (
        SELECT PB.TenPB
        FROM
            PHONGBAN pb LEFT JOIN NHANVIEN nv ON pb.MaPB = nv.MaPB
        GROUP BY
            pb.MaPB
        HAVING COUNT(nv.MaNV) > 2
    )
    AND
    nv.Luong > 30000
GROUP BY
    pb.TenPB


