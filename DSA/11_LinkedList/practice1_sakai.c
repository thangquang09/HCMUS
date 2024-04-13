#include <stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertZero(int a[], int *n, int position){
    (*n)++;
    for(int i = (*n) - 1; i > position; i--)
        a[i] = a[i-1];
    a[position] = 0;
}

void printArray(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%5d",a[i]);
    printf("\n");
}

void f(int a[], int n, int *comps, int *swaps) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
            *comps += 1;
			if(a[j] > a[j + 1]) {
                *swaps += 1;
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void innitialArray(int a[], int n, int min, int max) {
    for(int i = 0; i < n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
}

void solve(int a[], int n, int loop) {
    printf("Loop : %d\n\n", loop);
    innitialArray(a, n, -100, 100);
    // mang tan so
    int fre_swaps[1000] = {};
    int fre_comps[1000] = {};
    // tong so lan k1 va k2
    int total_fre1 = 0, total_fre2 = 0;
    for(int i = 0; i < loop; i++) {
        innitialArray(a, n, -100, 100);
        int swaps = 0, comps = 0;
        f(a, n, &comps, &swaps);
        fre_comps[comps] += 1; fre_swaps[swaps] += 1;
        total_fre1 += comps; total_fre2 += swaps;
    }
    int max_times = 0;
    // ham tim tan suat lon nhat ma ca 2 bien' co' duoc.
    for(int i = 0; i < 100; i++) {
        if(fre_comps[i] != 0 || fre_swaps[i] != 0) {
            max_times = i;
        }
    }
    // in bang tan suat
    printf("Times     | ");
    for(int i = 0; i <= max_times + 3; i++) {
        printf("%5d ", i);
    }
    printf("\n");
    printf("Comps     | ");
    for(int i = 0; i <= max_times + 3; i++) {
        printf("%5d ", fre_comps[i]);
    }
    printf("\n");
    printf("Swaps     | ");
    for(int i = 0; i <= max_times + 3; i++) {
        printf("%5d ", fre_swaps[i]);
    }
    printf("\n\nAverage_comps = %.2f | Average_swaps = %.2f", 1.0*total_fre1/loop, 1.0*total_fre2/loop);
    printf("\n-------------------------\n");
}


int main() {
    time_t t;
    srand((unsigned)time(&t));
    int a[10] = {};
    int n = 5;
    int loop[] = {10, 25, 25, 50, 100, 1000, 10000};
    int k = sizeof loop/ sizeof(int);
    for(int i = 0; i < k; i++) {
        solve(a, n, loop[i]);
    }
    return 0;
}


/*Noi dung: Test 2: 30% co 2 cau
Cung cap 1 chuong trinh code hoan thien (sua lai loi sai neu co): yeu cau de bai nhu la dem so luong swap comp,...
-> chen` code -> thong ke 'k' lan thi nghiem
nhung lenh tac dong len phan tu cua mang thi` dem', con lai thi khong
*/
