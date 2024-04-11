#include<stdio.h>

void output(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
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
    if(right - left <= 0) return;
    int pivot = partition(a, left, right);
    quick_sort(a, left, pivot - 1);
    quick_sort(a, pivot + 1, right);
}

int main() {
    int n; scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, n - 1);
    output(a, n);
    return 0;
}