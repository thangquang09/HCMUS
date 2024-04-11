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

int partition(int a[], int left, int right, int* cnt) {
    *cnt += 1;
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

void quick_sort(int a[],int left, int right, int n, int *cnt) {
    if(right - left <= 0) return;
    int pivot = partition(a, left, right, cnt);
    printf("Mang A sau khi quicksort lan thu %d | phan hoach [%d, %d] |: ", *cnt, left, right);
    output(a, n);
    quick_sort(a, left, pivot - 1, n, cnt);
    quick_sort(a, pivot + 1, right, n, cnt);
}

void cauA() {
    printf("Cau A------------------\n");
    int a[] = {1, 3, 7, 8, 5};
    int n = sizeof a / sizeof (int);
    int cnt = 0;
    quick_sort(a, 0, n - 1, n, &cnt);
    printf("\nVay mang A can chay %d lan partition\n", cnt);
}

void cauB() {
    printf("Cau B------------------\n");
    int a[] = {0, 2, 3, 9, 5, 6, 8, 4};
    int n = sizeof a / sizeof (int);
    int cnt = 0;
    quick_sort(a, 0, n - 1, n, &cnt);
    printf("\nVay mang A can chay %d lan partition\n", cnt);
}

void cauC() {
    printf("Cau C------------------\n");
    int a[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof a / sizeof (int);
    int cnt = 0;
    quick_sort(a, 0, n - 1, n, &cnt);
    printf("\nVay mang A can chay %d lan partition\n", cnt);
}

int main() {
    cauA();
    cauB();
    cauC();
    return 0;
}