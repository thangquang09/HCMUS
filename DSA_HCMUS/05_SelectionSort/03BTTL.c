#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void cls() {
    for (int i = 0; i < 20; i++) {
    printf("\n");
}
}

void innitialArray(int a[], int n, int min, int max) {
    for(int i = 0; i < n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
}


/* Hàm sắp xếp sử dụng thuật toán sắp xếp chèn */
void insertSort(int a[], int n, int *comps, int *shifts) {
    int i, key, j;
    for(int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {
            (*comps)++;
            (*shifts)++;
            a[j + 1] = a[j];
            j--;
        }
        if(j >= 0)
            (*comps)++;
        a[j + 1] = key;
    }
}

void output(int a[], int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void solve(int a[], int n, int loop) {
    innitialArray(a, n, -100, 100);
    int comps_total = 0;
    int shifts_total = 0;
    int comps = 0;
    int shifts = 0;
    insertSort(a, n, &comps, &shifts);
    
}

int main() {
    cls();
    time_t t;
    srand((unsigned)time(&t));
    int a[100];
    int n = 20;
    int k[6] = {20, 30, 50, 100, 1000, 10000};
    for(int i = 0; i < 6 ;i++) {
        solve(a, n, k[i]);
    }
    return 0;
}
