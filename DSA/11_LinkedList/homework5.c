#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node{
    int soPhong, soTang;
    char ten;
    struct Node* next;
};
typedef struct Node Node;

struct LinkedList {
    Node* head;
};
typedef struct LinkedList LinkedList;

void init(LinkedList *list) {
    list->head = NULL;
}
// khai bao thong tin //
int khachSan[1000][1000];// 17 tang va moi tang 12 phong
int soPhongKhachSan, soTangKhachSan;
int isFull[1000]; // check xem tang thu i co full chua
LinkedList doan[11]; // 10 doan
int sodoan = 10;
// --------------------//

void initKhachSan() {
    scanf("%d %d", &soTangKhachSan, &soPhongKhachSan);
    for(int i = soTangKhachSan; i >= 1; i--) {
        for(int j = 1; j <= soPhongKhachSan; j++) {
            scanf("%d", &khachSan[i][j]);
        }
    }
    printf("DA NHAP XONG THONG TIN PHONG KHACH SAN!\n");
}

Node* makeNode(int phong, int tang, char Ten) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->soPhong = phong;
    newNode->soTang = tang;
    newNode->ten = Ten;
    newNode->next = NULL;
    return newNode;
}

int size(LinkedList *list) {
    int cnt = 0;
    Node* tmp = list->head;
    while(tmp) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

void insCus(LinkedList *list, int phong, int tang, char Ten) {
    Node* newNode = makeNode(phong, tang, Ten);
    if(list->head == NULL) {
        list->head = newNode;
    }else {
        Node* tmp = list->head;
        while(tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void deleteFirst(LinkedList* list) {
    if(list->head == NULL)
        return;
    Node* tmp = list->head;
    list->head = list->head->next;
    free(tmp);
}

void deleteCus(LinkedList *list, int pos) {
    int n = size(list);
    if(pos < 1 || pos > n) {
        printf("So thu tu nay khong hop le\n");
        return;
    }
    if(pos == 1) deleteFirst(list);
    else {
        Node* tmp = list->head;
        for(int i = 1; i <= pos - 2; i++) {
            tmp = tmp->next;
        }
        // tmp = pos - 1
        Node* kth = tmp->next; //node thu pos
        printf("Thong tin:\nTen: %c, tang %d, phong %d\nDa xoa!\n", kth->ten, kth->soTang, kth->soPhong);
        int phong = kth->soPhong, tang = kth->soTang;
        khachSan[tang][phong] = 0; isFull[tang] = 0;
        // cho pos - 1 ket noi voi node thu pos + 1
        tmp->next = kth->next;
        free(kth);
    }
}

void timPhongTrong(int *soTangTraVe, int*soPhongTraVe) {
    // bat dau tu tang 2
    // tim tang` chua full
    int i = 2;
    while(isFull[i]) {
        i++;
    }

    for(i; i <= soTangKhachSan; i++) {
        for(int j = 1; j <= soPhongKhachSan; j++) {
            if(khachSan[i][j] == 0) {
                khachSan[i][j] = 2;
                *soTangTraVe = i; *soPhongTraVe = j;
                return;
            }
        }
        isFull[i] = 1;
    }
}

void nhapThongTin(LinkedList *list) {
    printf("Nhap so luong thanh vien: ");
    int soluong; scanf("%d", &soluong);
    char danhSachTen[100] = {};
    // nhap danh sach ten doan
    char tmp; // dau cach
    scanf("%c", &tmp);
    for(int i = 1; i <= soluong; i++) {
        scanf("%c", &danhSachTen[i]);
        scanf("%c", &tmp);
    }
    // tim phong cho doan truong
    int phongCuaDoanTruong = -1;
    for(int i = 1; i <= soPhongKhachSan; i++) {
        if(!khachSan[1][i]) {
            khachSan[1][i] = 3;
            phongCuaDoanTruong = i;
            break;
        }
    }
    insCus(list, phongCuaDoanTruong, 1, danhSachTen[1]);
    // khoi tao danh sach thanh vien
    for(int i = 2; i <= soluong; i++) {
        int SOPHONG, SOTANG;
        timPhongTrong(&SOTANG, &SOPHONG);
        insCus(list, SOPHONG, SOTANG, danhSachTen[i]);
    }

}

void xuatThongTinDoan(LinkedList *list) {
    if(list->head == NULL) {
        // printf("Khong ton tai doan nay`\n");
        return;
    }
    Node* tmp = list->head;
    printf("DOAN TRUONG: %c  - tang: %d  - phong: %d\n", tmp->ten, tmp->soTang, tmp->soPhong);
    tmp = tmp->next;
    int stt = 1;
    while(tmp) {
        printf("THANH VIEN %d:  %c  - tang: %d  - phong: %d\n", stt, tmp->ten, tmp->soTang, tmp->soPhong);
        tmp = tmp->next;
        stt++;
    }
    printf("----------------------\n");
}



void VANDE2() {
    int phong;
    printf("Nhap so phong cua doan truong ban muon tim: "); scanf("%d", &phong);
    xuatThongTinDoan(&doan[phong]);
}

void VANDE3() {
    int soLuongKhachCheckOut;
    printf("Nhap so luong khach check out: "); scanf("%d", &soLuongKhachCheckOut);
    int phongTrong[1000] = {}, tangTrong[1000] = {}; // muc dich luu lai nhung phong da check out
    int idx = 1;
    while(soLuongKhachCheckOut--) {
        int tang, phong;
        printf("Nhap so tang va so phong khach le check-out: "); scanf("%d %d", &tang, &phong);
        phongTrong[idx] = phong; tangTrong[idx] = tang; idx ++;
        khachSan[tang][phong] = 0; // danh dau phong luc nay da trong
        isFull[tang] = 0; // danh dau tang luc nay k con full
    }
    int soLuongCheckIn; printf("Nhap so luong khach checkin: "); scanf("%d", &soLuongCheckIn);
    idx--;
    while(soLuongCheckIn--) {
        if(idx == 0) {
            printf("DA HET PHONG!\n"); return;
        }
        printf("Khach hang moi thuoc doan so may: "); int so_doan; scanf("%d", &so_doan);
        char tmp; // dau cach
        scanf("%c", &tmp);
        printf("Ten khach hang: "); char ten_khach; scanf("%c", &ten_khach);
        insCus(&doan[so_doan], phongTrong[idx], tangTrong[idx], ten_khach);
        idx--;
    }
}

void VANDE4() {
    printf("Nhap so doan co khach check-out: "); int so_doan; scanf("%d", &so_doan);
    printf("Nhap so thu tu cua nguoi trong doan: "); int so_thu_tu; scanf("%d", &so_thu_tu);
    deleteCus(&doan[so_doan], so_thu_tu + 1); // k tinh doan truong
}

void VANDE5() {
    printf("Nhap so thu tu cua doan muon check out: "); int so_doan; scanf("%d", &so_doan);
    if(doan[so_doan].head == NULL) {
        printf("Doan khong ton tai!\n"); return;
    }else {
        Node* tmp = doan[so_doan].head;
        int phong = tmp->soPhong, tang = tmp->soTang;
        khachSan[tang][phong] = 0; isFull[tang] = 0;
        tmp = tmp->next;
        while(tmp) {
            Node* xoa = tmp;
            int phong = tmp->soPhong, tang = tmp->soTang;
            khachSan[tang][phong] = 0; isFull[tang] = 0;
            tmp = tmp->next;
            free(xoa);
        }
        doan[so_doan].head = NULL;
        printf("DA XOA!\n");
    }
}

void baoCaoTrangThaiPhong() {
    for(int i = soTangKhachSan; i >= 1; i--) {
        for(int j = 1; j <= soPhongKhachSan; j++) {
            printf("%d ", khachSan[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    while(1) {
        printf("--------------QUAN LY KHACH SAN--------------\n");
        printf("1. Khoi tao khach san va nhap thong tin doan\n");
        printf("2. Tim phong cua doan truong\n");
        printf("3. Khach le check out, bo sung khach moi check in\n");
        printf("4. Khach trong doan check out\n");
        printf("5. Ca doan check out va bao cao trang thai phong\n");
        printf("6. Xuat thong tin tat ca\n");
        printf("7. Bao cao trang thai phong\n");
        printf("0. Thoat\n");
        int lc; scanf("%d", &lc);
        if(lc == 1) {
            initKhachSan();
            // printf("Nhap so doan`: "); scanf("%d", &sodoan);
            for(int i = 1; i <= sodoan; i++) {
                init(&doan[i]);
                printf("Nhap thong tin doan %d:\n", i);
                nhapThongTin(&doan[i]);
            }
        }else if(lc == 2){
            VANDE2();
        }else if(lc == 3) {
            VANDE3();
        }else if(lc == 4) {
            VANDE4();
        }else if(lc == 5) {
            VANDE5();
            for(int i = 1; i <= soTangKhachSan; i++) {
                for(int j = 1; j <= soPhongKhachSan; j++) {
                    printf("%d ", khachSan[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }else if(lc == 6) {
            for(int i = 1; i <= sodoan; i++) {
                printf("DOAN THU %d\n", i);
                xuatThongTinDoan(&doan[i]);
            }
        }else if(lc == 7) {
            baoCaoTrangThaiPhong();
        }else continue;
    }
    return 0;
}