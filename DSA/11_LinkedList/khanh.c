#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int a[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % (max - min + 1) + min;
    }
}

void f(int a[], int n, int *ganh, int *ssanh) {
    int even = 0;
    int odd = 1;

    for (int i = 0; i < n; i++) {
        (*ssanh)+=1; 
        if (a[i] % 2 == 0) {
            int temp = a[even];
            a[even] = a[i];
            a[i] = temp;
            even += 2;
            (*ganh) += 3; 
        }
    }

    for (int i = 0; i < n; i++) {
        (*ssanh)+=1; 
        if (a[i] % 2 != 0) {
            int temp = a[odd];
            a[odd] = a[i];
            a[i] = temp;
            odd += 2;
            (*ganh) += 3; 
        }
    }
}
void solve(int a[], int n, int loop) {
    printf("\nLoop : %d\n", loop);
    time_t t;
    srand((unsigned)time(&t));
    int fre1[60] = {0};
    int fre2[60] = {0};
    int total_fre1 = 0, total_fre2 = 0;
    for(int i = 0; i < loop; i++) {
        initializeArray(a, n, -100, 100);
        int cond1 = 0, cond2 = 0;
        f(a, n, &cond1, &cond2);
        fre1[cond1] += 1; fre2[cond2] += 1;
        total_fre1 += cond1; total_fre2 += cond2;
    }
    int k1 = sizeof fre1 / sizeof(int);
    int k2 = sizeof fre2 / sizeof(int);
    printf("\ngan:\t");
    for(int i = 0; i < k1; i++) {
        printf("%3d ", i);
    }
    printf("\nFre:\t");
    for(int i = 0; i < k1; i++) {
        printf("%3d ", fre1[i]);
    }
    printf("\n");
    printf("so sanh:");
    for(int i = 0; i < k2; i++) {
        printf("%3d ", i);
    }
    printf("\nFre:\t");
    for(int i = 0; i < k2; i++) {
        printf("%3d ", fre2[i]);
    }
    printf("\n\nAverage_gan = %.2f | Average_sosanh = %.2f", 1.0*total_fre1/loop, 1.0*total_fre2/loop);
}
int main() {
    int a[100];
    solve(a, 10, 100);
    solve(a, 10, 1000);
    solve(a, 10, 10000);
    
    
    return 0;
}

// Loop : 100

// gan:      0   1   2   3   4   5   6   7   8   9 
// Fre:      0   0   0   0   0   0   0   0   1   0 
// so sanh:  0   1   2   3   4   5   6   7   8   9 
// Fre:      0   0   0   0   0   0   0   0   0   0 

// Average_gan = 36.75 | Average_sosanh = 21.98
// Loop : 1000

// gan:      0   1   2   3   4   5   6   7   8   9
// Fre:      0   0   0   0   0   0   0   0   1   0
// so sanh:  0   1   2   3   4   5   6   7   8   9
// Fre:      0   0   0   0   0   0   0   0   0   0

// Average_gan = 36.67 | Average_sosanh = 22.00
// Loop : 10000

// gan:      0   1   2   3   4   5   6   7   8   9
// Fre:      0   0   0   0   0   0   0   0   1   0
// so sanh:  0   1   2   3   4   5   6   7   8   9
// Fre:      0   0   0   0   0   0   0   0   0   0

// Average_gan = 37.05 | Average_sosanh = 22.00