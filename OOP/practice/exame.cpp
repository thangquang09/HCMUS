#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

/*
Xây dựng một chương trình C++ để quản lý thông tin của một bệnh viện.


Một bệnh viện bao gồm nhiều khoa. Mỗi khoa có một tên riêng.

Mỗi khoa có nhiều bệnh nhân. Bệnh nhân có các thông tin về tên, ngày sinh. Bệnh nhân chỉ ở trong một khoa duy nhất.

Các bác sĩ trong bệnh viện được tổ chức theo nhóm. Mỗi bác sĩ chỉ ở trong một nhóm. Mỗi nhóm có một mã nhóm duy nhất. Mỗi nhóm được lãnh đạo bởi một bác sĩ (cố vấn) duy nhất. Bác sĩ có các thông tin về tên, địa chỉ.

Mỗi bệnh nhân khi nhập bệnh viện được điều trị bởi một nhóm bác sĩ duy nhất. Bác sĩ cố vấn của nhóm đó chịu trách nhiệm về bệnh nhân.

Chương trình cần quản lý các thông tin sau:

   -Các khoa.

   -Các bác sĩ, và nhóm của bác sĩ đó.

   -Bệnh nhân và phòng bệnh của bệnh nhân khi nhập viện. Hiển thị thông tin bác sĩ tư vấn chịu trách nhiệm cho bệnh nhân đó. Hiển thị nhóm bác sĩ đang điều trị cho bệnh nhân.
*/

class Khoa;
class BenhNhan;
class BacSi;
class Nhom;

class Person {
    private:
    string ten;
    string maSo;
    public:
    // getter and setter
    string getTen() {
        return this->ten;
    }
    string getMaSo() {
        return this->maSo;
    }
    void setTen(string ten) {
        this->ten = ten;
    }
    void setMaSo(string maSo) {
        this->maSo = maSo;
    }
    // constructor
    Person(string ten, string maSo) {
        this->setTen(ten);
        this->setMaSo(maSo);
    }
    virtual void display() = 0;
};


class BenhNhan : public Person{
    private:
    string ngaySinh;
    string phongBenh = "";
    Khoa* khoa = NULL;
    Nhom* nhom = NULL; // nhom dieu tri
    public:
    //getter and setter
    string getNgaySinh() {
        return this->ngaySinh;
    }
    string getPhongBenh() {
        return this->phongBenh;
    }
    void setNgaySinh(string ngaySinh) {
        this->ngaySinh = ngaySinh;
    }
    void setPhongBenh(string phongBenh) {
        this->phongBenh = phongBenh;
    }
    Nhom* getNhom() {
        return this->nhom;
    }
    void setNhom(Nhom* nhom) {
        this->nhom = nhom;
    }
    void setKhoa(Khoa* khoa) {
        this->khoa = khoa;
    }
    Khoa* getKhoa() {
        return this->khoa;
    }
    // constructor
    BenhNhan (string ten, string maSo, string ngaySinh) : Person(ten, maSo) {
        this->setNgaySinh(ngaySinh);
    }
    //display
    void display() override;
};

class BacSi : public Person{
    string diaChi;
    Nhom* nhom = NULL;
    public:
    //getter and setter
    string getDiaChi() {
        return this->diaChi;
    }
    void setDiaChi(string diaChi) {
        this->diaChi = diaChi;
    }
    Nhom* getNhom() {
        return this->nhom;
    }
    void setNhom(Nhom* nhom) {
        this->nhom = nhom;
    }
    // constructor
    BacSi(string ten, string maSo, string diaChi) : Person(ten, maSo) {
        this->setDiaChi(diaChi);
    }
    // display
    void display() override;
};

class BacSiCoVan : public BacSi {
    vector<BenhNhan*> dsBenhNhan;
    public:
    //getter and setter
    vector<BenhNhan*> getDsBenhNhan() {
        return this->dsBenhNhan;
    }
    // constructor
    BacSiCoVan(string ten, string maSo, string diaChi) : BacSi(ten, maSo, diaChi) {}
};

class Nhom {
    string maNhom;
    BacSiCoVan* coVan = NULL;
    vector<BacSi*> dsBacSi;
    public:
    //getter and setter
    string getMaNhom() {
        return this->maNhom;
    }
    BacSiCoVan* getCoVan() {
        return this->coVan;
    }
    void setMaNhom(string maNhom) {
        this->maNhom = maNhom;
    }
    void setCoVan(BacSiCoVan* coVan) {
        this->coVan = coVan;
    }
    // constructor
    Nhom(string maNhom, BacSiCoVan* coVan) {
        this->setMaNhom(maNhom);
        this->setCoVan(coVan);
        coVan->setNhom(this);
    }
    // method
    void addBacSi(BacSi* bacSi) {
        this->dsBacSi.push_back(bacSi);
        bacSi->setNhom(this);
    }
    // display
    void display() {
        cout << "Ma Nhom: " << this->getMaNhom() << endl;
        cout << "Bac Si Co Van: " << this->getCoVan()->getTen() << endl;
        cout << "Danh Sach Bac Si: " << endl;
        for (int i = 0; i < this->dsBacSi.size(); i++) {
            cout << this->dsBacSi[i]->getTen() << endl;
        }
    }
};

class Khoa {
    private:
    string tenKhoa;
    map<string, BenhNhan*> dsBenhNhan;
    public:
    //getter and setter
    string getTenKhoa() {
        return this->tenKhoa;
    }
    void setTenKhoa(string tenKhoa) {
        this->tenKhoa = tenKhoa;
    }
    // constructor
    Khoa(string tenKhoa) {
        this->setTenKhoa(tenKhoa);
    }
    // method
    void addBenhNhan(BenhNhan* benhNhan) {
        this->dsBenhNhan[benhNhan->getMaSo()] = benhNhan;
        benhNhan->setKhoa(this);
    }
};


void BacSi::display() {
    cout << "Ten: " << this->getTen() << endl;
    cout << "Ma So: " << this->getMaSo() << endl;
    cout << "Dia Chi: " << this->getDiaChi() << endl;
    cout << "Nhom: " << this->getNhom()->getMaNhom() << endl;
}

void BenhNhan::display() {
    cout << "Ten: " << this->getTen() << endl;
    cout << "Ma So: " << this->getMaSo() << endl;
    cout << "Ngay Sinh: " << this->getNgaySinh() << endl;
    cout << "Phong Benh: " << this->getPhongBenh() << endl;
    if (this->nhom != NULL) {
        cout << "Nhom: " << this->nhom->getMaNhom() << endl;
        cout << "Bac si co van: " << this->nhom->getCoVan()->getTen() << endl;
    }
}


class BenhVien {
    private:
    string tenBenhVien;
    map<string, Khoa*> dsKhoa;
    map<string, BacSi*> dsBacSi;
    map<string, Nhom*> dsNhom;
    map<string, BenhNhan*> dsBenhNhan;
    map<string, BenhNhan*> dsPhongBenh;
    public:
    //getter and setter
    string getTenBenhVien() {
        return this->tenBenhVien;
    }
    map<string, Khoa*> getDsKhoa() {
        return this->dsKhoa;
    }
    map<string, BacSi*> getDsBacSi() {
        return this->dsBacSi;
    }
    map<string, Nhom*> getDsNhom() {
        return this->dsNhom;
    }
    map<string, BenhNhan*> getDsBenhNhan() {
        return this->dsBenhNhan;
    }
    void setTenBenhVien(string tenBenhVien) {
        this->tenBenhVien = tenBenhVien;
    }
    // method
    void addKhoa(Khoa* khoa) {
        this->dsKhoa[khoa->getTenKhoa()] = khoa;
    }
    void addBacSi(BacSi* bacSi) {
        this->dsBacSi[bacSi->getMaSo()] = bacSi;
    }
    void addNhom(Nhom* nhom) {
        this->dsNhom[nhom->getMaNhom()] = nhom;
    }
    // set phong benh
    void setPhongBenh(BenhNhan* benhNhan, string phongBenh) {
        dsPhongBenh[phongBenh] = benhNhan;
        benhNhan->setPhongBenh(phongBenh);
    }
    // constructor
    BenhVien(string tenBenhVien) {
        this->setTenBenhVien(tenBenhVien);
    }
    void addBenhNhan(BenhNhan* benhNhan) {
        this->dsBenhNhan[benhNhan->getMaSo()] = benhNhan;
    }
    void themBacSiVaoNhom(BacSi* bacSi, Nhom* nhom) {
        nhom->addBacSi(bacSi);
    }
    void themBenhNhanVaoKhoa(BenhNhan* benhNhan, Khoa* khoa) {
        khoa->addBenhNhan(benhNhan);
        benhNhan->setKhoa(khoa);
    }
    void themBenhNhanVaoNhom(BenhNhan* benhNhan, Nhom* nhom) {
        nhom->getCoVan()->getDsBenhNhan().push_back(benhNhan);
        benhNhan->setNhom(nhom);
    }

    // display
    void display() {
        cout << "\nTen Benh Vien:\n" << this->getTenBenhVien() << endl;
        cout << "\nDanh Sach Khoa: \n" << endl;
        for (auto it = this->dsKhoa.begin(); it != this->dsKhoa.end(); it++) {
            cout << it->first << endl;
        }
        cout << "\nDanh Sach Bac Si:\n" << endl;
        for (auto it = this->dsBacSi.begin(); it != this->dsBacSi.end(); it++) {
            it->second->display();
        }
        cout << "\nDanh Sach Nhom: \n" << endl;
        for (auto it = this->dsNhom.begin(); it != this->dsNhom.end(); it++) {
            cout << it->first << endl;
        }
        /*
        Bệnh nhân và phòng bệnh của bệnh nhân khi nhập viện. Hiển thị thông tin bác sĩ tư vấn chịu trách nhiệm cho bệnh nhân đó. Hiển thị nhóm bác sĩ đang điều trị cho bệnh nhân.
        */
        cout << "\nDanh Sach Benh Nhan: \n" << endl;
        for (auto it = this->dsBenhNhan.begin(); it != this->dsBenhNhan.end(); it++) {
            it->second->display();
        }
    }
};


int main() {
    // khai bao
    BenhVien benhVien("Benh Vien A");

    Khoa khoa("Khoa A");
    Khoa khoa1("Khoa B");


    BacSi bacSi("Bac Si A", "BS001", "Dia Chi A");
    BacSiCoVan coVan("Bac Si Co Van A", "BS002", "Dia Chi Co Van A");
    BacSi bacSi1("Bac Si B", "BS003", "Dia Chi B");

    BacSiCoVan coVan1("Bac Si Co Van B", "BS004", "Dia Chi Co Van B");
    BacSi bacSi2("Bac Si C", "BS005", "Dia Chi C");
    BacSi bacSi3("Bac Si D", "BS006", "Dia Chi D");

    Nhom nhom1("Nhom B", &coVan1);
    Nhom nhom("Nhom A", &coVan);
    BenhNhan benhNhan("nguyen van a", "BN001", "01/01/2000");
    BenhNhan benhNhan1("nguyen van b", "BN002", "02/02/2000");
    // chay chuong trinh
    benhVien.addKhoa(&khoa);
    benhVien.addKhoa(&khoa1);


    benhVien.addBacSi(&bacSi);
    benhVien.addBacSi(&bacSi1);
    benhVien.addBacSi(&coVan);
    benhVien.addBacSi(&coVan1);
    benhVien.addBacSi(&bacSi2);
    benhVien.addBacSi(&bacSi3);


    benhVien.addNhom(&nhom);
    benhVien.addNhom(&nhom1);

    benhVien.themBacSiVaoNhom(&bacSi, &nhom);
    benhVien.themBacSiVaoNhom(&bacSi1, &nhom);

    benhVien.themBacSiVaoNhom(&bacSi2, &nhom1);
    benhVien.themBacSiVaoNhom(&bacSi3, &nhom1);
    
    
    benhVien.addBenhNhan(&benhNhan);
    benhVien.addBenhNhan(&benhNhan1);
    benhVien.setPhongBenh(&benhNhan, "Phong 1");
    benhVien.setPhongBenh(&benhNhan1, "Phong 2");
    benhVien.themBenhNhanVaoKhoa(&benhNhan, &khoa);
    benhVien.themBenhNhanVaoNhom(&benhNhan, &nhom);
    benhVien.themBenhNhanVaoKhoa(&benhNhan1, &khoa1);
    benhVien.themBenhNhanVaoNhom(&benhNhan1, &nhom1);
    benhVien.display();
    
    return 0;
}