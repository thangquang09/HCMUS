-- 22110202
-- Ly Quang Thang
-- MySQL
drop schema if exists Csdl_Taxi;
create schema Csdl_Taxi;

use Csdl_Taxi;

create table LOAI_PHUONGTIEN(
    LoaiPT  int not null,
    TenLoai varchar(64) not null,
    constraint PK_LOAIPHUONGTIEN primary key (LoaiPT)
);

create table LAIXE(
    MaLX    int not null,
    Ho  varchar(15) not null,
    Dem varchar(15),
    Ten varchar(15) not null,
    NgaySinh    date,
    SoGP    char(12) not null,
    HanGP date not null,
    constraint PK_LAIXE primary key (MaLX)
);

create table PHUONGTIEN(
    LoaiPT int not null,
    SoPT    int not null,
    BienSo  char(10) not null,
    NamSanXuat  int not null,
    ChuPT   int,
    TinhTrang   bit not null default 1,
    constraint PK_PHUONGTIEN primary key (SoPT),
    constraint FK_PHUONGTIEN_LoaiPT foreign key (LoaiPT) references LOAI_PHUONGTIEN(LoaiPT),
    constraint FK_PHUONGTIEN_ChuPT foreign key (ChuPT) references LAIXE(MaLX)
);

create table CALAMVIEC(
    MaCLV   int not null,
    MaLX    int not null,
    SoPT    int not null,
    BatDau  datetime,
    KetThuc datetime,
    constraint PK_CALAMVIEC primary key (MaCLV),
    constraint FK_CALAMVIEC_SoPT foreign key (SoPT) references PHUONGTIEN(SoPT),
    constraint FK_CALAMVIEC_MaLX foreign key (MaLX) references LAIXE(MaLX)
);

INSERT INTO LAIXE VALUES
		(1, 'Nguyen', 'Van', 'Tung', '2000-01-15', 799876543210, '2030-07-05'),
		(2, 'Le', 'Quoc', 'Huy', '1998-02-20', 798765432109, '2032-11-20');


INSERT INTO LOAI_PHUONGTIEN VALUES
		(1, 'Hatchback'),
		(2, 'Sedan'),
		(3, 'SUV');


INSERT INTO PHUONGTIEN VALUES
		(2, 1, '51E-135.75', 2018, NULL, 1),
		(3, 2, '51E-482.36', 2018, 2.0, 1);

	
INSERT INTO CALAMVIEC VALUES
		(1, 1, 1, '2023-01-01 08:00:00', '2023-01-01 16:00:00'),
		(2, 2, 2, '2023-02-01 10:00:00', '2023-02-01 18:00:00');

UPDATE LAIXE SET HanGP = '2031-07-05' WHERE SoGP = '799876543210';
DELETE FROM CALAMVIEC c WHERE MaLX = 2;