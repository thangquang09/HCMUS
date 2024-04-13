#include <stdio.h>

void f(int a[], int n, int b[])
{
    int total_comps = 0, total_assigns = 0;
    for (int i = 0; i < n; i++)
    {
        int Comps = 0, Assigns = 0; //Biến dùng để thể hiện số phép so sánh (cmps) và gán (assigns)
        for (int j = 0; j < n; j++)
        {
            ++Comps;
            if (a[i] == a[j])
            {
                ++Assigns;
                b[a[i]]++;
            }
        }
        total_comps += Comps;
        total_assigns += Assigns;

        //Tổng kết số phép so sánh và gán theo từng vòng lặp bên ngoài
        printf("- Pass-through %d: Comps = %d, Assigns = %d\n", i + 1, Comps, Assigns);
    }

    //In ra kết quả phép so sánh và gán
    printf("Total Comps = %d, Total Assigns = %d", total_comps, total_assigns);
}

int main() {
    int a[] = {2, 0, 4, 3, 4, 0};
    int b[10000] = {};
    int n = sizeof a / sizeof a[0];

    f(a, n, b);

    return 0;
}

// {2, 0, 4, 3, 4, 0}
// {3, 5, 0, 3, 0, 2}