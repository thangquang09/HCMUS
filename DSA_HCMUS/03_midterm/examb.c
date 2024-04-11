#include<stdio.h>

void f(int a[], int n)
{
    int i, j;
    int total_comps = 0, total_swaps = 0; // Tao bien tong phep so sanh va phep hoan vi
    for (int i = 0; i < n-1; i++)
    {
        int comps = 0, swaps = 0; // Tao phep so sanh va hoan vi trong tung vong
        for (int j = 1; j < n; j++)
        {
            comps++; // Do dong code tiep theo co phep so sanh
            if (a[j - 1] >= a[j])
            {
                //Sau khi phep so sanh dung thi tien hanh hoan vi
                swaps++;
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
        //--------In ra qua trinh------------
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
    int a[7] = {1, 2, 6, 1, 9, 2, 9};
    int n = sizeof a / sizeof(int);
    f(a, n);
    return 0;
}

// {8, 6, 4, 8, 8, 12, 10}
// {1, 2, 6, 1, 9, 2, 9}