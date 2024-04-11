#include<stdio.h>
#include<string.h>

#define MAX 1001

typedef struct
{
    char a[MAX];
    int top;
} Stack;

void init(Stack *s){
    s->top = -1;
}

int isEmpty(Stack* s) {
    if(s->top == -1) {
        return 1;
    }else return 0;
}
int isFull(Stack* s) {
    if(s->top == MAX - 1) {
        return 1;
    }
    return 0;
}
void push(Stack* s, char value) {
    s->a[++s->top] = value;
}
char pop(Stack* s) {
    char value = s->a[s->top];
    --s->top;
    return value;
}
void displayStack(Stack* s) {
    printf("\nStack: ");
    for(int i = 0; i <= s->top; i++) {
        printf("%c", s->a[i]);
    }
    printf("\n");
}


int main() {
    char str1[1001];
    char str2[1001];
    scanf("%s", str1);
    for(int i = 0; i < strlen(str1); i++) {
        str2[i] = str1[i];
    }
    // Method 1:
    int i = 0;
    int j = strlen(str1) - 1;
    while(i < j) {
        char tmp = str1[i];
        str1[i] = str1[j];
        str1[j] = tmp;
        i++; j--;
    }
    printf("Method 1: %s\n",str1);

    Stack st;
    init(&st);

    for(int i = 0; i < strlen(str2); i++) {
        push(&st, str2[i]);
    }
    printf("Method 2: ");
    for(int i = 0; i < strlen(str2); i++) {
        printf("%c", pop(&st));
    }
    return 0;
}