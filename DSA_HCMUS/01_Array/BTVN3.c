#include<stdio.h>
#include<string.h>

void nhap(char str[][80], int n, char value[]) {
    for(int i = 0; i< n; i++) {
        scanf("%s", str[i]);
    }
    scanf("%s", value);
}

int check(char a[], char b[], int m) {
    for(int i = 0; i < m; i++) {
        if(*(a + i) != *(b + i))
            return 0;
    }
    return 1;
}

int search(char str[][80], char value[], int n, int m) {
    for(int i = 0; i < n; i++) {
        if(check(str[i], value, m)){
            return i;
        }

    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char str[10][80];
    char value[80];
    nhap(str, n, value);
    int idx = search(str, value, n, m);
    if(idx == -1)
        printf("Not Found!\n");
    else
        printf("Found %s at %d", value, idx);
}