#include<stdio.h>
#include<math.h>

float S1(int n) {
    if(n == 1) return 1;
    return 1.0/n + S1(n - 1);
}

float S2(int n) {
    if(n == 1) return 0.5;
    return 1.0/pow(2, n) + S2(n - 1);
}

float S3(int n) {
    if(n == 1) return 0.5;
    return 1.0*n/(n + 1) + S3(n - 1);
}

float f(int n) {
    if(n == 0) return 2;
    if(n == 1) return 3;
    return 6*f(n - 1) - 9*f(n - 2);
}

int main() {
    printf("%f %f", f(2), f(3));
    return 0;
}