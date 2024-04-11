#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void cls() {
    for(int i = 0; i < 20; i++)
        printf("\n");
}

void innitialAray(int a[], int n, int min, int max) {
    for(int i = 0; i < n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min_idx])
                min_idx = j;
        }
        swap(&a[i], &a[min_idx]);
    }
}

void input(int a[], int *n) {
    scanf("%d, n");
    for(int i = 0; i < *n; i++) {
        scanf("%d ", &a[i]);
    }
}

void output(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    cls();
    time_t t;
    srand((unsigned)time(&t));
    int a[100], n;
    n = 10;
    innitialAray(a, n, -100, 100);
    output(a, n);
    printf("\n");
    selectionSort(a, n);
    output(a, n);
    return 0;
}