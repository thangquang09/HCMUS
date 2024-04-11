#include<stdio.h>
#include<string.h>

void insert(char str[][80], char value[80], int idx, int *n, int m) {
    (*n)++;
    for(int i = *n - 1; i > idx; i--) {
        strcpy(str[i], str[i-1]);
    }
    strcpy(str[idx], value);
}

int main() {
    int n, m, idx;
    scanf("%d%d", &n, &m);
    char str[10][80], value[80];
    for(int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }
    scanf("%d", &idx);
    scanf("%s", value);
    insert(str, value, idx, &n, m);
    for(int i = 0; i < n; i++) {
        printf("%s ",str[i]);
    }
}