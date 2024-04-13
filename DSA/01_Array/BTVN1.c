#include<stdio.h>
#include<math.h>

float search(float a[], int n, int value, int *idx) {
    float max = 1e9;
    float res;
    for(int i = 0; i < n; i++) {
        if(1.0*abs(value - a[i]) < max) {
            res = a[i];
            max = 1.0*abs(value - a[i]);
            *idx = i;
        }
    }
    return res;
}

int main() {
    int n;
    float a[10];
    int value;
    float res;
    int idx = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }
    scanf("%d", &value);
    res = search(a, n, value, &idx);
    printf("%.2f at index %d nearest to %d", res, idx, value);
}