#include<stdio.h>

int recursion(int a[], int k, int n, int value) {
    if(k == n) {
        return -1;
    }
    if(a[k] == value) {
        return k;
    }
    return recursion(a, k + 1, n, value);
}

int main() {
    int a[] = {1, 2, 3};
    int n = 3;
    printf("%d",recursion(a, 0, n, 2));
    return 0;
}