#include<stdio.h>

void insert(char *str, char value, int idx) {
    char *tmp = str;
    int n = 0;
    while(*tmp != '\0'){
        n++;
        tmp++;
    }
    n++;
    *(str + n + 1) = '\0';
    for(int i = n; i > idx; i--) {
        *(str + i) = *(str + i - 1);
    }
    *(str + idx) = value;
}

int main() {
    char str[80];
    char value;
    int idx;
    scanf("%s %c %d", str, &value, &idx);
    insert(str, value, idx);
    printf("%s", str);
}