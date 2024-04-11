#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

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

void selectionSort(int a[], int n, int *comps, int *swaps) {
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            (*comps)++;
            if(a[j] < a[min_idx])
                min_idx = j;
        }
        if(min_idx != i) {
            (*swaps)++;
            swap(&a[i], &a[min_idx]);
        }
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

void Solve(int a[], int n, int loop) {
    printf("\n--------------------------");
    printf("\nK = %d\n", loop);
    int swaps_fre[21] = {};
    float comps_mean = 0;
    float swaps_mean = 0;
    for(int i = 0; i < loop; i++) {
        innitialAray(a, n, -100, 100);
        int comps = 0, swaps = 0;
        selectionSort(a, n, &comps, &swaps);
        swaps_fre[swaps]++;
        comps_mean += (float)comps;
        swaps_mean += (float)swaps;
    }
    printf("Swaps    | ");
    for(int i = 0; i < n + 1; i++) printf("%5d", i);
    printf("\nSwapsFre | ");
    for(int i = 0; i < n + 1; i++) printf("%5d", swaps_fre[i]);
    printf("\nComps_Mean = %.1f", comps_mean / (float)loop);
    printf("\nSwaps_Mean = %.1f", swaps_mean / (float)loop);
}

int main() {
    cls();
    time_t t;
    srand((unsigned)time(&t));
    int a[100], n;
    n = 10;
    // Xu ly
    int k[6] = {20, 30, 50, 100, 1000, 10000};
    for(int i = 0; i < 7; i++) {
        Solve(a, n, k[i]);
    }

    return 0;
}