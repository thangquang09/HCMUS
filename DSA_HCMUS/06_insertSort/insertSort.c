#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertSort(int a[], int n) {
    int i, key, j;
    for(int i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n; scanf("%d", &n);
    int a[10];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    insertSort(a, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}