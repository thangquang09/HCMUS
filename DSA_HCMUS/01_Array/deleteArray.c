#include<stdio.h>

void deleteArray(int a[], int *n, int index) {
    for(int i = index; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    a[*n - 1] = 0;
    (*n)--;
}

int main() {
    int n;
    int arr[10];
    int index;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &index);
    deleteArray(arr, &n, index);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}