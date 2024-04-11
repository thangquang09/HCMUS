#include<stdio.h>

void insert(int a[100], int *n, int value) {
    int idx = -1;
    for(int i = 0; i < *n; i++) {
        if(a[i] >= value) {
            idx = i;
            break;
        }
    }
    if(a[*n - 1] <= value) {
        idx = *n - 1;
    }
    (*n) ++;

    for(int i = *n - 1; i > idx; i--) {
        a[i] = a[i - 1];
    }
    a[idx] = value;
}

int main() {
    int n;
    int a[100];
    int value;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &value);
    insert(a, &n, value);
    for(int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
}