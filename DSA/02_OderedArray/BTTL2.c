#include<stdio.h>


void linearSearch(int a[100], int value, int n) {
    int flag = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == value || a[i] > value){
            printf("%d", i);
            flag = 1;
            break;
        }

    }
    if(!flag) printf("Not found!");
}

int main() {
    int n; scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int value; scanf("%d", &value);
    linearSearch(a, value, n);
}