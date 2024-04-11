#include<stdio.h>

int searchArray(int a[], int n, int value) {
    for(int i = 0; i < n; i++) {
        if(a[i] == value) // nếu tìm thấy a[i] bằng value hàm trả về giá trị i là chỉ số
            return i;
    }
    return -1; // không tìm thấy trả về -1
}

int main() {
    int n;
    int arr[10];
    int value;
    // nhập dữ liệu
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &value);
    // solve
    int index = searchArray(arr, n, value);
    if(index == -1) {
        printf("Not found!\n");
    }else {
        printf("Found %d at %d\n", value, index);
    }
}