#include<stdio.h>

void output(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    // printf('\n');
}

void insertSort(int a[], int n, int *comps, int *shifts) {
    int i, key, j;
    int total_comps = 0, total_shifts = 0;
    for(int i = 1; i < n; i++) {
        *comps = 0, *shifts = 0;
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key) {
            (*comps)++;
            (*shifts)++;
            a[j + 1] = a[j];
            j--;
        }
        if(j >= 0)
            (*comps)++; // so sanh them ca indesx

        a[j + 1] = key;
        printf("Step %d with key = %d: ", i, key);
        output(a, n);
        printf("Comps = %d, Shifts = %d \n", *comps, *shifts);
        total_comps += *comps;
        total_shifts += *shifts;
    }
    printf("Total_comps = %d, total_shift = %d", total_comps, total_shifts);
}


int main() {
    int n = 5;
    int arr[10] = {12, 11, 13, 5, 6};

    int comps = 0, shifts = 0;
    insertSort(arr, n, &comps, &shifts);
    return 0;
}