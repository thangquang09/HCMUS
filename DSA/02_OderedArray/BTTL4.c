#include<stdio.h>

int stepBinary = 0, stepLinear = 0;

int binarySearch(int a[100], int value, int left, int right) {
    if(left <= right) {
        stepBinary++;
        int mid = (left + right) / 2;
        if(a[mid] == value) return mid;
        else if(a[mid] > value) {
            return binarySearch(a, value, left, mid - 1);
        }else return binarySearch(a, value, mid + 1, right);
    }else {
        return -1;
    };
}

int linearSearch(int a[100], int value, int n) {
    int flag = 0;
    for(int i = 0; i < n; i++) {
        stepLinear++;
        if(a[i] == value){
            return i;
        }
    }
    return -1;
}

int main() {
    int n; scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int value; scanf("%d", &value);
    int Binary = binarySearch(a, value, 0, n - 1);
    int Linear = linearSearch(a, value, n);
    printf("BinaryStep : %d  LinearStep : %d\n", stepBinary, stepLinear);
}