#include<stdio.h>

void insertArray(float a[], int *n, float value, int index) {
    (*n)++;
    for(int i = *n - 1; i > index; i--) {
        a[i] = a[i - 1];
    }
    a[index] = value;
}

int main() {
    int n;
    float arr[100];
    float value;
    int index;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    int m; scanf("%d", &m);
    while(m--) {
        scanf("%f", &value);
        scanf("%d", &index);
        insertArray(arr, &n, value, index);
    }
    for(int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
}