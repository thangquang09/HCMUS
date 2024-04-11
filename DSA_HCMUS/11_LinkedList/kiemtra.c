//LY QUANG THANG
//22110202

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// so sanh va gan

void f(int a[], int n, int *comps, int *assigns) {

    int even = 0;

    int odd = 1;


    for (int i = 0; i < n; i++) {
        *comps += 1;
        if (a[i] % 2 == 0) {
            *assigns += 1;
            int temp = a[even];
            *assigns += 1;
            a[even] = a[i];
            *assigns += 1;
            a[i] = temp;
            even += 2;

        }

    }


    for (int i = 0; i < n; i++) {
        *comps += 1;
        if (a[i] % 2 != 0) {
            *assigns += 1;
            int temp = a[odd];
            *assigns += 1;
            a[odd] = a[i];
            *assigns += 1;
            a[i] = temp;

            odd += 2;

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
    int fre_comps[1000] = {};
    int fre_assigns[1000] = {};
    // tong so lan comps va assigns
    int total_comps = 0, total_assigns = 0;
    for(int i = 0; i < loop; i++) {
        innitialArray(a, n, -100, 100);
        int comps = 0, assigns = 0;
        f(a, n, &comps, &assigns);
        fre_comps[comps] += 1; fre_assigns[assigns] += 1;
        total_comps += comps; total_assigns += assigns;
    }
    int max_times = 0;
    // ham tim tan suat lon nhat ma ca 2 bien' co' duoc.
    for(int i = 0; i < 100; i++) {
        if(fre_comps[i] != 0 || fre_assigns[i] != 0) {
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
    printf("Assigns   | ");
    for(int i = 0; i <= max_times + 3; i++) {
        printf("%5d ", fre_assigns[i]);
    }
    printf("\n\nAverage_comps = %.2f | Average_assigns = %.2f", 1.0*total_comps/loop, 1.0*total_assigns/loop);
    printf("\n-------------------------\n");
}


int main() {
    time_t t;
    srand((unsigned)time(&t));

    int loop[3] = {100, 1000, 10000};
    int a[100] = {};
    int n = 10;

    for(int i = 0; i < 3; i++) {
        solve(a, n, loop[i]);
    }

    return 0;

}


// OUTPUT cua code
/*
Loop : 100

Times     |     0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31    32    33    34    35    36    37    38    39    40    41    42    43    44    45    46    47    48    49    50    51
Comps     |     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0   100     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
Assigns   |     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0    59     0     0    17     0     0     7     0     0     2     0     0     8     0     0     6     0     0     1     0     0     0

Average_comps = 20.00 | Average_assigns = 33.15
-------------------------
Loop : 1000

Times     |     0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31    32    33    34    35    36    37    38    39    40    41    42    43    44    45    46    47    48    49    50    51
Comps     |     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0  1000     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0 
Assigns   |     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0   587     0     0   172     0     0    77     0     0    53     0     0    67     0     0    28     0     0    16     0     0     0

Average_comps = 20.00 | Average_assigns = 32.97
-------------------------
Loop : 10000

Times     |     0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31    32    33    34    35    36    37    38    39    40    41    42    43    44    45    46    47    48    49    50    51    52    53    54 
Comps     |     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0 10000     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0
Assigns   |     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0     0  5672     0     0  1773     0     0   819     0     0   537     0     0   635     0     0   403     0     0   135     0     0    26     0     0     0

Average_comps = 20.00 | Average_assigns = 33.17

*/