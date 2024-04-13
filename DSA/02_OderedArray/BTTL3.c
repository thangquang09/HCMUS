#include<stdio.h>


int binarySearch(int a[100], int value, int n) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] == value) {
            return mid;
        }else if(a[mid] > value) {
            left = mid + 1;
        }else right = mid - 1;
    }
    return n;
}

int lower_bound(int arr[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    int n; scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int value; scanf("%d", &value);
    int Binary = binarySearch(a, value, n);
    printf("%d", Binary);
}