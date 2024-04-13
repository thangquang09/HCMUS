#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void output(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void swap(int *a, int *b) {
    int tmp = *a; *a = *b; *b = tmp;
}

int partition(int a[], int left, int right, int *comps, int *swaps) {
    int pivot = right;
    right--;
    int compstmp = 0, swapstmp = 0;
    while(1) {
        while(a[left] <= a[pivot] && left <= right) {
            compstmp++;
            left++;
        }
        while(a[right] >= a[pivot] && right >= left) {
            right--;
            compstmp++;
        }
        // compstmp++;
        if(left < right) {
            swapstmp++;
            swap(&a[left], &a[right]);
        }else {
            break;
        }
    }
    if(left != pivot) {
        swapstmp++;
        swap(&a[left], &a[pivot]);
    }
    *comps += compstmp; *swaps += swapstmp;
    return left;
}

void quick_sort(int a[],int left, int right, int *comps, int *swaps) {
    if(right - left <= 0) {
        return;
    }
    int pivot = partition(a, left, right, comps, swaps);
    quick_sort(a, left, pivot - 1, comps, swaps);
    quick_sort(a, pivot + 1, right, comps, swaps);
}

// le trc chan sau
void solve(int a[], int n, int *c, int *s) {
    int i = 0, j = n - 1;
    int cnt = 0;
    int comps = 0, swaps = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] % 2) cnt++; // dem so le
    }

    while(i < j) {
        comps++;
        if(a[i] % 2 == 0 && a[j] % 2 != 0) {
            ++swaps;
            swap(&a[i], &a[j]);
            ++i; --j;
        }else if(a[i] % 2 == 0 && a[j] % 2 == 0) {--j;}
        else if(a[i] % 2 != 0 && a[j] % 2 != 0) {++i;}
        else {
            ++i; --j;
        }
    }

    quick_sort(a, 0, cnt - 1, &comps, &swaps);
    quick_sort(a, cnt, n - 1, &comps, &swaps);
    // output(a, n);
    *c = comps;
    *s = swaps;
}

void innitialArray(int a[], int n, int min, int max) {
    for(int i = 0; i < n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
}



int main() {
    int a[100];
    int n = 10;
    int total_comps = 0, total_swaps = 0;
    for(int i = 0; i < 1000; i++) {
        innitialArray(a, n, -100, 100);
        int c = 0, s = 0;
        solve(a, n, &c, &s);
        // int tmp; scanf("%d", &tmp);
        total_comps += c; total_swaps += s;
    }
    printf("Comps average: %.2f\nSwaps average: %.2f\n", 1.0*total_comps/1000, 1.0*total_swaps/1000);
    return 0;
}