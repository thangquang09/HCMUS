CREATE DATABASE DONDATHANG;
GO

-- change the the working database
USE DONDATHANG;

-- create table

CREATE TABLE NHACUNGCAP(
    MaNCC   INT NOT NULL,
    TenNCC  VARCHAR(40) NOT NULL,
    Email   VARCHAR(40),
    ThanhPho    VARCHAR(40),
    QuocGia VARCHAR(40),
    CONSTRAINT PK_NHACUNGCAP PRIMARY KEY (MaNCC)
);

CREATE TABLE MATHANG(
    MaMH    INT,
    TenMH   VARCHAR(50),
    MaNCC INT,
    DonGia  DECIMAL(12,2),
    TinhTrang   BIT
    CONSTRAINT PK_MATHANG PRIMARY KEY (MaMH)
)

CREATE TABLE CHITIETDDH(
    MaCT    INT,
    MaDDH   INT,
    MaMH    INT,
    DonGia DECIMAL(12,2),
    SoLuong INT
    CONSTRAINT PK_CHITIETDDH PRIMARY KEY (MaCT, MaDDH)
)

CREATE TABLE DONDATHANG(
    MaDDH INT,
    NgayDatHang DATETIME,
    MaKH INT,
    TriGia  DECIMAL(12,2)
    CONSTRAINT PR_DONDATHANG PRIMARY KEY(MaDDH)
);

CREATE TABLE KHACHHANG(
    MaKH INT,
    HoTen VARCHAR(50),
    DiaChi VARCHAR(50),
    ThanhPho VARCHAR(40),
    QuocGia VARCHAR(40),
    SoDT VARCHAR(15)
    CONSTRAINT PK_KHACHHANG PRIMARY KEY (MaKH)
);

-- CREATE REFERENCE
ALTER TABLE MATHANG ADD CONSTRAINT FK_MATHANG FOREIGN KEY (MaNCC) REFERENCES NHACUNGCAP (MaNCC);
ALTER TABLE CHITIETDDH ADD CONSTRAINT FK_CHITIETDDH FOREIGN KEY (MaMH) REFERENCES MATHANG (MaMH);
ALTER TABLE CHITIETDDH ADD CONSTRAINT FK_CHITIETDDH_MADDH FOREIGN KEY (MaDDH) REFERENCES DONDATHANG (MaDDH);
ALTER TABLE DONDATHANG ADD CONSTRAINT FK_DONDATHANG FOREIGN KEY (MaKH) REFERENCES KHACHHANG (MaKH);

-- INSERT VALUES
INSERT INTO NHACUNGCAP
VALUES
(1, 'Exotic Liquids', NULL, 'London', 'UK'),
(2, 'New Orleans Cajun Delights', NULL, 'New Orleans', 'USA'),
(3, 'Grandma Kellys Homestead', NULL, 'Ann Arbor', 'USA'),
(4, 'Tokyo Traders', NULL, 'Tokyo', 'Japan'),
(5, 'Cooperativa de Quesos Las Cabras', NULL, 'Oviedo', 'Spain'),
(6, 'Mayumis', NULL, 'Osaka', 'Japan'),
(7, 'Pavlova, Ltd.', NULL, 'Melbourne', 'Australia'),
(8, 'Specialty Biscuits, Ltd.', NULL, 'Manchester', 'UK'),
(9, 'PB Knackebrod AB', NULL, 'Goteborg', 'Sweden'),
(10, 'Refrescos Americanas LTDA', NULL, 'Sao Paulo', 'Brazil'),
(11, 'Heli Subwaren GmbH & Co. KG', NULL, 'Berlin', 'Germany'),
(12, 'Plutzer Lebensmittelgrobmarkte AG', NULL, 'Frankfurt', 'Germany'),
(13, 'Nord-Ost-Fisch Handelsgesellschaft mbH', NULL, 'Cuxhaven', 'Germany'),
(14, 'Formaggi Fortini s.r.l.', NULL, 'Ravenna', 'Italy'),
(15, 'Norske Meierier', NULL, 'Sandvika', 'Norway'),
(16, 'Bigfoot Breweries', NULL, 'Bend', 'USA'),
(17, 'Svensk Sjofoda AB', NULL, 'Stockholm', 'Sweden'),
(18, 'Aux joyeux ecclesiastiques', NULL, 'Paris', 'France'),
(19, 'New England Seafood Cannery', NULL, 'Boston', 'USA'),
(20, 'Leka Trading', NULL, 'Singapore', 'Singapore'),
(21, 'Lyngbysild', NULL, 'Lyngby', 'Denmark'),
(22, 'Zaanse Snoepfabriek', NULL, 'Zaandam', 'Netherlands'),
(23, 'Karkki Oy', NULL, 'Lappeenranta', 'Finland'),
(24, 'Gday, Mate', NULL, 'Sydney', 'Australia'),
(25, 'Ma Maison', NULL, 'Montreal', 'Canada'),
(26, 'Pasta Buttini s.r.l.', NULL, 'Salerno', 'Italy'),
(27, 'Escargots Nouveaux', NULL, 'Montceau', 'France'),
(28, 'Gai paturage', NULL, 'Annecy', 'France'),
(29, 'Forets derables', NULL, 'Ste-Hyacinthe', 'Canada');



INSERT INTO MATHANG VALUES
(1, 'Chai', 1, 18.0, 0),
(2, 'Chang', 1, 19.0, 0),
(3, 'Aniseed Syrup', 1, 10.0, 0),
(4, 'Chef Antons Cajun Seasoning', 2, 22.0, 0),
(5, 'Chef Antons Gumbo Mix', 2, 21.35, 1),
(6, 'Grandmas Boysenberry Spread', 3, 25.0, 0),
(7, 'Uncle Bobs Organic Dried Pears', 3, 30.0, 0),
(8, 'Northwoods Cranberry Sauce', 3, 40.0, 0),
(9, 'Mishi Kobe Niku', 4, 97.0, 1),
(10, 'Ikura', 4, 31.0, 0),
(11, 'Queso Cabrales', 5, 21.0, 0),
(12, 'Queso Manchego La Pastora', 5, 38.0, 0),
(13, 'Konbu', 6, 6.0, 0),
(14, 'Tofu', 6, 23.25, 0),
(15, 'Genen Shouyu', 6, 15.5, 0),
(16, 'Pavlova', 7, 17.45, 0),
(17, 'Alice Mutton', 7, 39.0, 1),
(18, 'Carnarvon Tigers', 7, 62.5, 0),
(19, 'Teatime Chocolate Biscuits', 8, 9.2, 0),
(20, 'Sir Rodneys Marmalade', 8, 81.0, 0),
(21, 'Sir Rodneys Scones', 8, 10.0, 0),
(22, 'Gustafs Knackebröd', 9, 21.0, 0),
(23, 'Tunnbrod', 9, 9.0, 0),
(24, 'Guarana Fantastica', 10, 4.5, 1),
(25, 'NuNuCa Nub-Nougat-Creme', 11, 14.0, 0),
(26, 'Gumbar Gummibarchen', 11, 31.23, 0),
(27, 'Schoggi Schokolade', 11, 43.9, 0),
(28, 'Rossle Sauerkraut', 12, 45.6, 1),
(29, 'Thuringer Rostbratwurst', 12, 123.79, 1),
(30, 'Nord-Ost Matjeshering', 13, 25.89, 0),
(31, 'Gorgonzola Telino', 14, 12.5, 0),
(32, 'Mascarpone Fabioli', 14, 32.0, 0),
(33, 'Geitost', 15, 2.5, 0),
(34, 'Sasquatch Ale', 16, 14.0, 0),
(35, 'Steeleye Stout', 16, 18.0, 0),
(36, 'Inlagd Sill', 17, 19.0, 0),
(37, 'Gravad lax', 17, 26.0, 0),
(38, 'Cote de Blaye', 18, 263.5, 0),
(39, 'Chartreuse verte', 18, 18.0, 0),
(40, 'Boston Crab Meat', 19, 18.4, 0),
(41, 'Jacks New England Clam Chowder', 19, 9.65, 0),
(42, 'Singaporean Hokkien Fried Mee', 20, 14.0, 1),
(43, 'Ipoh Coffee', 20, 46.0, 0),
(44, 'Gula Malacca', 20, 19.45, 0),
(45, 'Rogede sild', 21, 9.5, 0),
(46, 'Spegesild', 21, 12.0, 0),
(47, 'Zaanse koeken', 22, 9.5, 0),
(48, 'Chocolade', 22, 12.75, 0),
(49, 'Maxilaku', 23, 20.0, 0),
(50, 'Valkoinen suklaa', 23, 16.25, 0),
(51, 'Manjimup Dried Apples', 24, 53.0, 0),
(52, 'Filo Mix', 24, 7.0, 0),
(53, 'Perth Pasties', 24, 32.8, 1),
(54, 'Tourtiere', 25, 7.45, 0),
(55, 'Pâté chinois', 25, 24.0, 0),
(56, 'Gnocchi di nonna Alice', 26, 38.0, 0),
(57, 'Ravioli Angelo', 26, 19.5, 0),
(58, 'Escargots de Bourgogne', 27, 13.25, 0),
(59, 'Raclette Courdavault', 28, 55.0, 0),
(60, 'Camembert Pierrot', 28, 34.0, 0),
(61, 'Sirop derable', 29, 28.5, 0),
(62, 'Tarte au sucre', 29, 49.3, 0),
(63, 'Vegie-spread', 7, 43.9, 0),
(64, 'Wimmers gute Semmelknodel', 12, 33.25, 0),
(65, 'Louisiana Fiery Hot Pepper Sauce', 2, 21.05, 0),
(66, 'Louisiana Hot Spiced Okra', 2, 17.0, 0),
(67, 'Laughing Lumberjack Lager', 16, 14.0, 0),
(68, 'Scottish Longbreads', 8, 12.5, 0),
(69, 'Gudbrandsdalsost', 15, 36.0, 0),
(70, 'Outback Lager', 7, 15.0, 0),
(71, 'Flotemysost', 15, 21.5, 0),
(72, 'Mozzarella di Giovanni', 14, 34.8, 0),
(73, 'Rod Kaviar', 17, 15.0, 0),
(74, 'Longlife Tofu', 4, 10.0, 0),
(75, 'Rhonbrau Klosterbier', 12, 7.75, 0),
(76, 'Lakkalikoori', 23, 18.0, 0),
(77, 'Original Frankfurter grune Sobe', 12, 13.0, 0),
(78, 'Stroopwafels', 22, 9.75, 0);

INSERT INTO KHACHHANG VALUES
(1, 'Maria Anders', NULL, 'Berlin', 'Germany', '030-0074321'),
(2, 'Ana Trujillo', NULL, 'Mexico D.F.', 'Mexico', '(5) 555-4729'),
(3, 'Antonio Moreno', NULL, 'Mexico D.F.', 'Mexico', '(5) 555-3932'),
(4, 'Thomas Hardy', NULL, 'London', 'UK', '(171) 555-7788'),
(5, 'Christina Berglund', NULL, 'Lulea', 'Sweden', '0921-12 34 65'),
(6, 'Hanna Moos', NULL, 'Mannheim', 'Germany', '0621-08460'),
(7, 'Frederique Citeaux', NULL, 'Strasbourg', 'France', '88.60.15.31'),
(8, 'Martin Sommer', NULL, 'Madrid', 'Spain', '(91) 555 22 82'),
(9, 'Laurence Lebihan', NULL, 'Marseille', 'France', '91.24.45.40'),
(10, 'Elizabeth Lincoln', NULL, 'Tsawassen', 'Canada', '(604) 555-4729'),
(11, 'Victoria Ashworth', NULL, 'London', 'UK', '(171) 555-1212'),
(12, 'Patricio Simpson', NULL, 'Buenos Aires', 'Argentina', '(1) 135-5555'),
(13, 'Francisco Chang', NULL, 'Mexico D.F.', 'Mexico', '(5) 555-3392'),
(14, 'Yang Wang', NULL, 'Bern', 'Switzerland', '0452-076545'),
(15, 'Pedro Afonso', NULL, 'Sao Paulo', 'Brazil', '(11) 555-7647'),
(16, 'Elizabeth Brown', NULL, 'London', 'UK', '(171) 555-2282'),
(17, 'Sven Ottlieb', NULL, 'Aachen', 'Germany', '0241-039123'),
(18, 'Janine Labrune', NULL, 'Nantes', 'France', '40.67.88.88'),
(19, 'Ann Devon', NULL, 'London', 'UK', '(171) 555-0297'),
(20, 'Roland Mendel', NULL, 'Graz', 'Austria', '7675-3425'),
(21, 'Aria Cruz', NULL, 'Sao Paulo', 'Brazil', '(11) 555-9857'),
(22, 'Diego Roel', NULL, 'Madrid', 'Spain', '(91) 555 94 44'),
(23, 'Martine Rance', NULL, 'Lille', 'France', '20.16.10.16'),
(24, 'Maria Larsson', NULL, 'Bracke', 'Sweden', '0695-34 67 21'),
(25, 'Peter Franken', NULL, 'Munchen', 'Germany', '089-0877310'),
(26, 'Carine Schmitt', NULL, 'Nantes', 'France', '40.32.21.21'),
(27, 'Paolo Accorti', NULL, 'Torino', 'Italy', '011-4988260'),
(28, 'Lino Rodriguez', NULL, 'Lisboa', 'Portugal', '(1) 354-2534'),
(29, 'Eduardo Saavedra', NULL, 'Barcelona', 'Spain', '(93) 203 4560'),
(30, 'Jose Pedro Freyre', NULL, 'Sevilla', 'Spain', '(95) 555 82 82'),
(31, 'Andre Fonseca', NULL, 'Campinas', 'Brazil', '(11) 555-9482'),
(32, 'Howard Snyder', NULL, 'Eugene', 'USA', '(503) 555-7555'),
(33, 'Manuel Pereira', NULL, 'Caracas', 'Venezuela', '(2) 283-2951'),
(34, 'Mario Pontes', NULL, 'Rio de Janeiro', 'Brazil', '(21) 555-0091'),
(35, 'Carlos Hernandez', NULL, 'San Cristobal', 'Venezuela', '(5) 555-1340'),
(36, 'Yoshi Latimer', NULL, 'Elgin', 'USA', '(503) 555-6874'),
(37, 'Patricia McKenna', NULL, 'Cork', 'Ireland', '2967 542'),
(38, 'Helen Bennett', NULL, 'Cowes', 'UK', '(198) 555-8888'),
(39, 'Philip Cramer', NULL, 'Brandenburg', 'Germany', '0555-09876'),
(40, 'Daniel Tonini', NULL, 'Versailles', 'France', '30.59.84.10');

INSERT INTO DONDATHANG VALUES
(1, '2012-07-04 00:00:00', 15, 440.0),
(2, '2012-07-05 00:00:00', 9, 1863.4),
(3, '2012-07-08 00:00:00', 34, 1813.0),
(4, '2012-07-08 00:00:00', 14, 670.8),
(5, '2012-07-09 00:00:00', 26, 3730.0),
(6, '2012-07-10 00:00:00', 34, 1444.8),
(7, '2012-07-11 00:00:00', 14, 625.2),
(8, '2012-07-12 00:00:00', 38, 2490.5),
(9, '2012-07-15 00:00:00', 28, 517.8),
(10, '2012-07-16 00:00:00', 35, 1119.9);

INSERT INTO CHITIETDDH VALUES
(1.0, 1.0, 11.0, 14.0, 12.0),
(2.0, 1.0, 42.0, 9.8, 10.0),
(3.0, 1.0, 72.0, 34.8, 5.0),
(4.0, 2.0, 14.0, 18.6, 9.0),
(5.0, 2.0, 51.0, 42.4, 40.0),
(6.0, 3.0, 31.0, 7.7, 10.0),
(7.0, 3.0, 51.0, 42.4, 35.0),
(8.0, 3.0, 65.0, 16.8, 15.0),
(9.0, 4.0, 22.0, 16.8, 6.0),
(10.0, 4.0, 57.0, 15.6, 15.0),
(11.0, 4.0, 65.0, 16.8, 20.0),
(12.0, 5.0, 20.0, 64.8, 40.0),
(13.0, 5.0, 33.0, 2.0, 25.0),
(14.0, 5.0, 60.0, 27.2, 40.0),
(15.0, 6.0, 31.0, 10.0, 20.0),
(16.0, 6.0, 39.0, 14.4, 42.0),
(17.0, 6.0, 49.0, 16.0, 40.0),
(18.0, 7.0, 24.0, 3.6, 15.0),
(19.0, 7.0, 55.0, 19.2, 21.0),
(20.0, 7.0, 74.0, 8.0, 21.0),
(21.0, 8.0, 2.0, 15.2, 20.0),
(22.0, 8.0, 16.0, 13.9, 35.0),
(23.0, 8.0, 36.0, 15.2, 25.0),
(24.0, 8.0, 59.0, 44.0, 30.0),
(25.0, 9.0, 53.0, 26.2, 15.0),
(26.0, 9.0, 77.0, 10.4, 12.0),
(27.0, 10.0, 27.0, 35.1, 25.0),
(28.0, 10.0, 39.0, 14.4, 6.0),
(29.0, 10.0, 77.0, 10.4, 15.0);