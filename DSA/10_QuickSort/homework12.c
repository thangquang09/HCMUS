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

void solve(int a[], int n, int loop) {
    int leftFre[70] = {};
    int rightFre[70] = {};
    int avgle = 0, avgri=0;
    for(int i = 0; i < loop; i++) {
        innitialArray(a, n, -100, 100);
        int shiftLeft = 0, shiftRight = 0;
        quick_sort(a, 0, n - 1, &shiftLeft, &shiftRight);
        leftFre[shiftLeft]++;
        rightFre[shiftRight]++;
        avgle += shiftLeft; avgri += shiftRight;
    }
    for(int i = 0; i < 70; i++) printf("%2d ",i); printf("\n");
    for(int i = 0; i < 70; i++) {
        printf("%2d ", leftFre[i]);
    }
    printf("\n");
    for(int i = 0; i < 70; i++) printf("%2d ",i); printf("\n");
    for(int i = 0; i < 70; i++) {
        printf("%2d ", rightFre[i]);
    }
    printf("\nAVGLe = %.2f, AVGRi = %.2f\n", 1.0*avgle/loop, 1.0*avgri/loop);
    printf("\n-----------------------\n");
}

int main() {
    int a[100];
    time_t t;
    srand((unsigned)time(&t));
    int n = 10;
    int k[]={10, 100, 1000, 10000};
    for(int q = 0; q < 4; q++) {
        solve(a, n, k[q]);
    }

}