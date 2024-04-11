#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void innitialArray(int a[], int n, int min, int max) {
    for(int i = 0; i < n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
}
void copyArray(int a[], int b[], int n) {
    for(int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}
void insertSort(int a[], int n, int *shifts, int *steps) {
    int i, key, j;
    int total_comps = 0, total_shifts = 0;
    for(int i = 1; i < n; i++) {
        int comps = 0; *shifts = 0;
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {
            (comps)++;
            (*shifts)++;
            a[j + 1] = a[j];
            j--;
        }
        if(j >= 0)
            (comps)++; // so sanh them ca indesx

        a[j + 1] = key;
        total_comps += comps;
        total_shifts += *shifts;
    }
    *steps += total_comps + total_shifts;
    *shifts = total_shifts;
}
void selectionSort(int a[], int n, int *steps, int *swaps) {
    int comps = 0;
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            (comps)++;
            if(a[j] < a[min_idx])
                min_idx = j;
        }
        if(min_idx != i) {
            (*swaps)++;
            swap(&a[i], &a[min_idx]);
        }
    }
    *steps += comps + *swaps;
}



void solve(int a[], int n, int loop) {
    int swaps_fre[11] = {};
    int shifts_fre[100] = {};
    int steps_insertSort = 0, steps_selectionSort = 0;
    for(int i = 0; i < loop; i++) {
        innitialArray(a, n, -100, 100);
        int b[10] = {};
        copyArray(a, b, n);
        int shifts = 0, swaps = 0;
        selectionSort(a, n, &steps_selectionSort, &swaps);
        insertSort(b, n, &shifts, &steps_insertSort);
        swaps_fre[swaps] ++; shifts_fre[shifts]++;
    }
    printf("K = %d\n", loop);
    printf("Steps insert Sort = %.2f, Steps SelectionSort = %.2f\n", steps_insertSort * 1.0 / loop, steps_selectionSort * 1.0 / loop);

    // printf("Swaps   | ");
    // for(int i = 0; i <= n; i++) {
    //     printf("%5d ", i);
    // }
    // printf("\nFre     | ");
    // for(int i = 0; i <= n; i++) {
    //     printf("%5d ", swaps_fre[i]);
    // }
    // printf("\n---------------------------\n");

    // printf("Shifts  | ");
    // for(int i = 0; i <= n*(n - 1) / 2; i++) {
    //     printf("%5d ", i);
    // }
    // printf("\nFre     | ");
    // for(int i = 0; i <= n*(n - 1) / 2; i++) {
    //     printf("%5d ", shifts_fre[i]);
    // }
    // printf("\n---------------------------\n");
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    int n = 10, a[10] = {};

    int step[3] = {1000, 10000, 100000};
    for(int i = 0; i < 3; i++) {
        solve(a, n, step[i]);
    }
    return 0;
}