#include <iostream>
#include <map>
#include <string>

using namespace std;

class Tang;
class Phong;
class PhongNghi;
class PhongHoiNghi;
class PhongHoc;
class KhachHang;

class Phong {
    string soPhong;
    Tang* tang;
    KhachHang* khachHang;
    string batDau; // thoi gian dat
    string ketThuc; // thoi gian se tra
    public:
    string getBatDau() {
        return this->batDau;
    }
    string getKetThuc() {
        return this->ketThuc;
    }
    string getSoPhong() {
        return this->soPhong;
    }
    KhachHang* getKhachHang() {
        return this->khachHang;
    }
    void setBatDau(string batDau) {
        this->batDau = batDau;
    }
    void setKetThuc(string ketThuc) {
        this->ketThuc = ketThuc;
    }
    void setSoPhong(string soPhong) {
        this->soPhong = soPhong;
    }
    void setKhachHang(KhachHang* khachHang) {
        this->khachHang = khachHang;
    }
    Tang* getTang() {
        return this->tang;
    }
    void setTang(Tang* tang) {
        this->tang = tang;
    }
    Phong(string soPhong) {
        this->setSoPhong(soPhong);
        this->setBatDau("");
        this->setKetThuc("");
        this->setKhachHang(NULL); // phong chua duoc dat
        this->setTang(NULL); 
    }

    virtual void display() = 0;
};

class PhongNghi : public Phong {
    public:
    PhongNghi (string soPhong) : Phong(soPhong) {}
    void display() override {
        cout << "Phong nghi: " << this->getSoPhong() << endl;
    }
};

class PhongHoc : public Phong {
    PhongHoiNghi* phongHoiNghi;
    public:
    PhongHoiNghi* getPhongHoiNghi() {
        return this->phongHoiNghi;
    }
    void setPhongHoiNghi(PhongHoiNghi* phongHoiNghi) {
        this->phongHoiNghi = phongHoiNghi;
    }
    void xoaPhongHoiNghi() {
        this->phongHoiNghi = NULL;
    }
    PhongHoc (string soPhong) : Phong(soPhong) {
        this->setPhongHoiNghi(NULL);
    }
    void display() override {
        cout << "Phong hoc: " << this->getSoPhong() << endl;
    }
};

class PhongHoiNghi : public Phong {
    string Ten;
    map<string, PhongHoc*> dsPhongHoc;
    public:
    string getTen() {
        return Ten;
    }
    void setTen(string Ten) {
        this->Ten = Ten;
    }
    PhongHoiNghi (string soPhong, string Ten) : Phong(soPhong) {
        this->setTen(Ten);
    }
    void addPhongHoc (PhongHoc* phongHoc) {
        dsPhongHoc[phongHoc->getSoPhong()] = phongHoc;
    }
    void xoaPhongHoc (PhongHoc* phongHoc) {
        dsPhongHoc.erase(phongHoc->getSoPhong());
        phongHoc->xoaPhongHoiNghi();
    }

    void display () override {
        cout << "Phong hoi nghi: " << this->getSoPhong() << " - " << this->getTen() << endl;
        if (dsPhongHoc.size() != 0) {
            cout << "\tDanh sach phong hoc:\n";
            for (auto it : dsPhongHoc) {
                cout << it.first << "\n";
            }
        } 
    }
};
 
class Tang {
    string soTang;
    map<string, Phong*> dsPhong;
    public:
    string getSoTang() {
        return soTang;
    }
    void setSoTang(string soTang) {
        this->soTang = soTang;
    }
    Tang(string soTang) {
        this->setSoTang(soTang);
    }
    void addPhong(Phong* phong) {
        dsPhong[phong->getSoPhong()] = phong;
        phong->setTang(this);
    }
    void display() {
        cout << "Tang: " << this->getSoTang() << endl;
        for (auto it : dsPhong) {
            it.second->display();
        }
    }
};

class KhachHang {
    string Ten;
    string CCCD;
    map<string, Phong*> dsPhongDaDat;
    public:
    string getTen() {
        if (this == NULL) {
            return "NULL";
        }
        return Ten;
    }
    void setTen(string Ten) {
        this->Ten = Ten;
    }
    string getCCCD() {
        if (this == NULL) {
            return "NULL";
        }
        return CCCD;
    }
    void setCCCD(string CCCD) {
        this->CCCD = CCCD;
    }
    KhachHang(string Ten, string CCCD) {
        this->setTen(Ten);
        this->setCCCD(CCCD);
    }

    void datPhong(Phong* phong, string thoiGianBatDau, string thoiGianKetThuc) {
        if (phong->getKhachHang() != NULL) {
            cout << "Phong da duoc dat\n";
            return;
        }
        dsPhongDaDat[phong->getSoPhong()] = phong;
        phong->setBatDau(thoiGianBatDau);
        phong->setKetThuc(thoiGianKetThuc);
        phong->setKhachHang(this); // sau khi dat thi phong ko trong
    }

    void traPhong(Phong* phong) {
        if (phong->getKhachHang() == NULL) {
            cout << "Phong chua duoc dat\n";
            return;
        }
        dsPhongDaDat.erase(phong->getSoPhong());
        phong->setBatDau("");
        phong->setKetThuc("");
        phong->setKhachHang(NULL); // sau khi tra phong thi phong trong
    }

    void display() {
        cout << "- Khach hang: " << this->getTen() << " CCCD: " << this->getCCCD() << " Ds phong da dat:" << endl;
        for (auto it : dsPhongDaDat) {
            it.second->display();
            cout << " - Vao luc: " << it.second->getBatDau() << " Se tra phong luc: " << it.second->getKetThuc() << endl;
        }
    }
};

int main() {
    // xay dung khach san
    Tang tang1("1");
    Tang tang2("2");

    PhongHoc ph1("101");
    PhongHoc ph2("102");
    PhongHoiNghi phn1("103", "HoangSa");
    PhongNghi pn1("104");

    PhongHoiNghi phn2("203", "TruongSa");
    PhongHoc ph3("201");
    PhongHoc ph4("202");
    PhongHoc ph5("204");

    phn1.addPhongHoc(&ph1);
    phn1.addPhongHoc(&ph2);
    phn2.addPhongHoc(&ph3);
    phn2.addPhongHoc(&ph4);
    phn2.addPhongHoc(&ph5);

    tang1.addPhong(&ph1);
    tang1.addPhong(&ph2);
    tang1.addPhong(&phn1);
    tang1.addPhong(&pn1);

    tang2.addPhong(&ph3);
    tang2.addPhong(&ph4);
    tang2.addPhong(&phn2);
    tang2.addPhong(&ph5);
    
    cout << "Test chuc nang khach san:\n";
    cout << "---Tang1---\n";
    tang1.display();
    cout << "-----------------------\n";
    cout << "---Tang2---\n";
    tang2.display();
    cout << "-----------------------\n";
    cout << "---Phong hoi nghi 1---\n";
    phn1.display();
    cout << "-----------------------\n";
    // Dat phong
    cout << "Test chuc nang dat phong:\n";

    KhachHang kh1("Nguyen Van A", "123456789");
    kh1.datPhong(&pn1, "10:00 18/6/24", "12:00 19/6/24");
    kh1.datPhong(&phn1, "13:00 18/6/24", "15:00 19/6/24");
    cout << "Sau khi khach hang 1 dat 2 phong 104 va 103:\n";
    kh1.display();

    cout << "-----------------------\n"; // sau khi tra phong nghi 104
    cout << "Sau khi khach hang 1 tra phong 104:\n";
    kh1.traPhong(&pn1);
    kh1.display();
    cout << "-----------------------\n";
    KhachHang kh2("Nguyen Van B", "987654321");
    // Neu kh2 muon dat phong ma kh1 da dat
    cout << "Khach hang 2 muon dat phong ma khach hang 1 da dat:\n";
    kh2.datPhong(&phn1, "10:00 18/6/24", "12:00 19/6/24"); // in ra Phong da duoc dat
    return 0;
}