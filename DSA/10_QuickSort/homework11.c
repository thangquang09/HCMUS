#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
    int tmp=*a; *a = *b; *b = tmp;
}

int partition(int a[], int left, int right, int* shiftLeft, int*shiftRight) {
    int pivot = right;
    right--;
    while(1) {
        while(a[left] <= a[pivot] && left <= right) {
            left++;
            *shiftLeft += 1;
        }
        while(a[right] >= a[pivot] && left <= right) {
            right--;
            *shiftRight += 1;
        }
        if(left < right) {
            swap(&a[left], &a[right]);
        }else{
            break;
        }
    }
    if(left != pivot) {
        swap(&a[left], &a[pivot]);
    }
    return left;
}

void quick_sort(int a[], int left, int right, int *shiftLeft, int* shiftRight) {
    if(left >= right) return;
    int pivot = partition(a, left, right, shiftLeft, shiftRight);
    quick_sort(a, 0, pivot - 1, shiftLeft, shiftRight);
    quick_sort(a, pivot + 1, right, shiftLeft, shiftRight);
}

void innitialArray(int a[], int n, int min, int max) {
    for(int i = 0; i < n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
}


int main() {
    time_t t;
    srand((unsigned)time(&t));
    int a[100];
    int n = 10;
    innitialArray(a, n, -100, 100);
    int shiftLeft = 0, shiftRight = 0;
    quick_sort(a, 0, n - 1, &shiftLeft, &shiftRight);
    printf("shift left = %d, shift right = %d\n", shiftLeft, shiftRight);
    return 0;
}