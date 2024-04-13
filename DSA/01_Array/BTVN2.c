#include<stdio.h>
#include<string.h>

int search(char str[], char value) {
    for(int i = 0; *(str + i) != '\0'; i++) {
        if(*(str + i) == value)
            return i;
    }
    return -1;
}

int main() {
    char str[80];
    scanf("%s", str);
    getchar();
    char value;
    scanf("%c", &value);
    int idx = search(str, value);
    if(idx == -1)
        printf("Not Found!\n");
    else
        printf("Found %c at %d", value, idx);
}