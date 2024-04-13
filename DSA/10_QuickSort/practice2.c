#include<stdio.h>

void output(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void swap(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
}

int partition(int a[], int left, int right) {
    int pivot = right;
    right--;
    while(1) {
        while(a[left] <= a[pivot] && left <= right) left++;
        while(a[right] >= a[pivot] && right >= left) right--;
        if(left < right) {
            swap(&a[left], &a[right]);
        }else {
            break;
        }
    }
    swap(&a[left], &a[pivot]);
    return left;
}

void quick_sort(int a[],int left, int right) {
    if(right - left <= 0){
        return;
    }
    int pivot = partition(a, left, right);
    for(int i = left; i <= right; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    quick_sort(a, left, pivot - 1);
    quick_sort(a, pivot + 1, right);
}

int main() {
    int n = 11;
    int a[100] = {3, 1, 2, -4, 5, 10, 6, -4, 11, 9, -2};
    // scanf("%d", &n);
    // for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    quick_sort(a, 0, n - 1);
    printf("Mang sau khi sap xep:\n");
    output(a, n);

    /*
    Phan tich ham de quy:
    Buoc 1: Base case
        Khi left > right. Ham de quy dung hoat dong.
    Buoc 2: Ket qua cua base case:
        La mot phan hoach cua mang da duoc sap xep
    Buoc 3: Truong hop truoc base case:
        mang A: [9 10 11]
    Buoc 4: Truong hop truoc buoc 3:
        mang A: [6 11 9 10]
    */
    return 0;
}