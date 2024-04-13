#include <stdio.h>

void f(int a[], int n)
{
    int i, j;
    int total_comps = 0, total_swaps = 0;
    for(int i = 0; i <  n - 1; i++) {
        int comps = 0, swaps = 0;
        for(int j = 1; j < n; j++) {
            comps++;
            if(a[j - 1] >= a[j]) {
                swaps++;
                int tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
        }
        printf("Pass-through %d: [", i + 1);
        for(int k = 0; k < n; k++) {
            printf("%d", a[k]);
            if(k < n - 1)
                printf(", ");
        }
        printf("] => comps = %d, swaps = %d\n", comps, swaps);
        total_comps+=comps;
        total_swaps+=swaps;
    }
    printf("Total comps = %d, total swaps = %d", total_comps, total_swaps);
}


int main() {
    int a[7] = {1, 10, 1, 1, 7, 10, 4};
    int n = sizeof a / sizeof(int);
    f(a, n);
    return 0;
}

// - Pass-through 1: [1 1 1 7 10 4 10] => Comps = 6, Swaps = 5
// - Pass-through 2: [1 1 1 7 4 10 10] => Comps = 6, Swaps = 4
// - Pass-through 3: [1 1 1 4 7 10 10] => Comps = 6, Swaps = 4
// - Pass-through 4: [1 1 1 4 7 10 10] => Comps = 6, Swaps = 3
// - Pass-through 5: [1 1 1 4 7 10 10] => Comps = 6, Swaps = 3
// - Pass-through 6: [1 1 1 4 7 10 10] => Comps = 6, Swaps = 3
// Total Comps = 36, Total Swaps = 22