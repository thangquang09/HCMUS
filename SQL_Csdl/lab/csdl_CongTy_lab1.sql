-- THỰC HÀNH BUỔI 1

-- CREATE DATABASE Csdl_Congty

create database Csdl_Congty;
go

-- Change the working database to Csdl_Congty
use Csdl_Congty;

-- Create table PHONGBAN
create table PHONGBAN (
	MaPB			int				not null,
	TenPB			varchar(15) 	not null,
	MaQL			char(9)			not null default '888665555',
	NgayBoNhiem		date,
	constraint PK_PHONGBAN primary key (MaPB),
	constraint AK_PHONGBAN_TenPB unique (TenPB)
);

-- Create table NHANVIEN
create table NHANVIEN (
	MaNV			char(9)			not null,
	HoNV			varchar(15) 	not null,
	Dem				varchar(15),
	TenNV			varchar(15) 	not null,
	NgaySinh		date,
	DiaChi			varchar(50),
	GioiTinh		char			check (GioiTinh in ('F', 'f', 'M', 'm')),
	Luong			int,
	MaGS			char(9),
	MaPB			int				not null default 1,
	constraint PK_NHANVIEN primary key (MaNV),
	constraint FK_NHANVIEN_MaGS foreign key (MaGS) 
								references NHANVIEN (MaNV)
								on delete no action,
	constraint FK_NHANVIEN_PHONGBAN foreign key (MaPB) 
									references PHONGBAN (MaPB)
									on delete no action on update no action
);

-- Add a referential constraint for PHONGBAN
alter table PHONGBAN add constraint FK_PHONGBAN_NHANVIEN foreign key (MaQL) 
														 references NHANVIEN (MaNV)
														 on delete no action on update cascade;

-- Create table TRUSO_PHONG
create table TRUSO_PHONG (
	MaPB			int				not null,
	TruSo			varchar(50) 	not null,
	constraint PK_TRUSO primary key (MaPB, TruSo),
	constraint FK_TRUSO_PHONGBAN foreign key (MaPB) 
								 references PHONGBAN (MaPB)
								 on delete cascade on update cascade
);

-- Create table DUAN
create table DUAN (
	MaDA			int				not null,
	TenDA			varchar(30) 	not null,
	DiaDiem			varchar(50),
	MaPB			int				not null,
	constraint PK_DUAN primary key (MaDA),
	constraint AK_DUAN_TenDA unique (TenDA),
	constraint FK_DUAN_PHONGBAN foreign key (MaPB) 
								references PHONGBAN (MaPB)
								on delete cascade on update cascade
);

-- Create table THAMGIA
create table THAMGIA (
	MaNV			char(9)			not null,
	MaDA			int				not null,
	SoGio			decimal(6,1),
	constraint PK_THAMGIA primary key (MaNV, MaDA),
	constraint FK_THAMGIA_NHANVIEN foreign key (MaNV) 
								   references NHANVIEN (MaNV)
								   on delete cascade on update cascade,
	constraint FK_THAMGIA_DUAN foreign key (MaDA) 
							   references DUAN (MaDA)
							   on delete no action on update no action
);

-- Create table THANNHAN
create table THANNHAN (
	MaNV			char(9)			not null,
	TenTN			varchar(45)		not null,
	GioiTinh		char			check (GioiTinh in ('M', 'm', 'F', 'f')),
	NgaySinh		date,
	QuanHe			varchar(10),
	constraint PK_THANNHAN primary key (MaNV, TenTN),
	constraint FK_THANNHAN_NHANVIEN foreign key (MaNV) 
									references NHANVIEN (MaNV)
									on delete cascade on update cascade
);

-- Off checking referential constraint FK_PHONGBAN_NHANVIEN
alter table PHONGBAN nocheck constraint FK_PHONGBAN_NHANVIEN;

-- Insert tuples into PHONGBAN
insert into PHONGBAN 
values (5,'Nghien cuu','333445555','1988-05-22'),
	   (4,'Dieu hanh','987654321','1995-01-01'),
	   (1,'Quan ly','888665555','1981-06-19');

-- On checking referential constraint FK_PHONGBAN_NHANVIEN
alter table PHONGBAN nocheck constraint FK_PHONGBAN_NHANVIEN;
	  	  
-- Insert tuples into NHANVIEN
insert into NHANVIEN 
values ('888665555','Le','Van','Bo','1937-11-10','450 Trung Vuong, Ha Noi','M',55000,null,1),
	   ('333445555','Phan','Van','Nghia','1955-12-08','638 Nguyen Van Cu, Q5, TpHCM','M',40000,'888665555',5),
	   ('123456789','Nguyen','Bao','Hung','1965-01-09','731 Tran Hung Dao, Q1, TpHCM','M',30000,'333445555',5),
	   ('666884444','Tran',null,'Nam','1962-09-15','975 Ba Ria Vung Tau','M',38000,'333445555',5),
	   ('453453453','Hoang','Kim','Yen','1972-07-31','543 Mai Thi Luu, Q1, TpHCM','F',25000,'333445555',5),
	   ('987654321','Du','Thi','Hau','1951-06-20','291 Ho Van Hue, QPN, TpHCM','F',43000,'888665555',4),
	   ('999887777','Au',null,'Vuong','1968-07-19','332 Nguyen Thai Hoc, Q1, TpHCM','F',25000,'987654321',4),
	   ('987987987','Nguyen','Van','Giap','1969-03-09','980 Le Hong Phong, Q10, TpHCM','M',25000,'987654321',4);

-- Insert tuples into TRUSO_PHONG
insert into TRUSO_PHONG 
values (1,'Phu Nhuan'),
	   (4,'Go Vap'),
	   (5,'Tan Binh'),
	   (5,'Phu Nhuan'),
	   (5,'Thu Duc');

-- Insert tuple into DUAN
insert into DUAN 
values (1,'San pham X','Tan Binh',5),
	   (2,'San pham Y','Thu Duc',5),
	   (3,'San pham Z','Phu Nhuan',5),
	   (10,'Tin hoc hoa','Go Vap',4),
	   (20,'Tai to chuc','Phu Nhuan',1),
	   (30,'Phuc loi','Go Vap',4);

-- Insert tuples into THAMGIA
insert into THAMGIA 
values ('123456789',1,32.5),
	   ('123456789',2,7.5),
	   ('666884444',3,40),
	   ('453453453',1,20),
	   ('453453453',2,20),
	   ('333445555',2,10),
	   ('333445555',3,10),
	   ('333445555',10,10),
	   ('333445555',20,10),
	   ('999887777',30,30),
	   ('999887777',10,10),
	   ('987987987',10,35),
	   ('987987987',30,5),
	   ('987654321',30,20),
	   ('987654321',20,15),
	   ('888665555',20,null),
	   ('333445555', 1, 5),
	   ('333445555', 30, 5);

-- Insert tuples into THANNHAN
insert into THANNHAN 
values ('333445555','Anh','F','1986-04-05','Con gai'),
	   ('333445555','The','M','1983-10-25','Con trai'),
	   ('333445555','Loi','F','1958-05-03','Vo'),
	   ('987654321','An','M','1942-02-28','Chong'),
	   ('123456789','Minh','M','1988-01-01','Con trai'),
	   ('123456789','Anh','F','1988-12-30','Con gai'),
	   ('123456789','Yen','F','1967-05-05','Vo');