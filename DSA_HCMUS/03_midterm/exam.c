#include<stdio.h>

void f(int a[], int n, int b[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                b[a[i]]++;
            }
        }
    }
}


int main() {
    int a[6]= {3, 5, 0, 3, 0, 2};
    int n = sizeof a/sizeof(int);
    int b[100] = {};
    f(a, n , b);
    return 0;
}