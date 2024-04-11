#include<stdio.h>

void insertArray(int a[], int *n, int value, int index) {
    (*n)++; // chèn nên tăng độ dài mảng thêm 1

    for(int i = *n - 1; i > index; i--) {
        a[i] = a[i - 1]; // dời mảng qua phải 1 đơn vị tính từ idx + 1
    }
    a[index] = value;
}

int main() {
    int n;
    int arr[10];
    int value;
    int index;
    // nhập dữ liệu
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &value);
    scanf("%d", &index);
    // solve
    insertArray(arr, &n, value, index);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}