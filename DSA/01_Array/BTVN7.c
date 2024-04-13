#include<stdio.h>
#include<string.h>
int number(char a[]) {
    int res = 0;
    for(int i = 0; i < 2; i++) {
        res = res * 10 + (a[i] - '0');
    }
    return res;
}

void insert(char str[][80], char value[80], int *n) {
    int number1 = number(value);
    int idx = 0;
    for(int i = 0; i < *n; i++) {
        if(number(str[i]) > number1) {
            idx = i;
            break;
        }
    }
    if(number1 > number(str[*n - 1])){
        idx = *n;
    }
    (*n)++;
    for(int i = *n - 1; i > idx; i--) {
        strcpy(str[i], str[i - 1]);
    }
    strcpy(str[idx], value);
}


int main() {
    char str[100][80];
    char value[80];
    int n;
    int q;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++) {
        scanf("%s", str[i]);
    }
    scanf("%d", &q);
    while(q--) {
        scanf("%s", value);
        insert(str, value, &n);
    }
    printf("OUTPUT:\n");
    for(int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }
}