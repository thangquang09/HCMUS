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
char top(Stack *s) {
    return s->a[s->top];
}
int find(char c, char s[]) {
    for(int i = 0; i < strlen(s); i++) {
        if(c == s[i])
            return 1;
    }
    return 0;
}

void deleteArray(char a[], int *n, int index) {
    for(int i = index; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    a[*n - 1] = '\0';
    (*n)--;
}

int main() {
    // Nhap du lieu ------------------------------------
    Stack st;
    init(&st);
    char str[1001] = "}{3+5*(4-1]}";
    // scanf("%s", str);
    int n = strlen(str);
    int error[1001] = {};
    int index_error = -1;
    char values[] = {')', '}', ']'};
    // truc quan hoa------------------------------------
    for(int i = 0; i < n; i++) {
        printf("%2c ", str[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    //--------------------------------------------------
    for(int i = 0; i < n; i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&st, str[i]);
        }
        else if(find(str[i], values)) {
            if(isEmpty(&st)) {
                error[++index_error] = i;
                str[i] = ' ';
            }else {
                char c = str[i];
                if(c == ')') {
                    c -= 1;
                }else c -= 2;
                if(top(&st) != c) {
                    error[++index_error] = i;
                    str[i] = top(&st) == '('?top(&st) + 1:top(&st) + 2;
                    char tmp = pop(&st);
                }else {
                    char tmp = pop(&st);
                }
            }
        }else continue;
    }
    // Xu ly khoang cach----------------------------
    for(int i = 0; i < n; i++) {
        if(str[i] == ' ') {
            deleteArray(str, &n, i);
            i-=1;
        }
    }
    // Xuat ket qua---------------------------------
    if(index_error == -1) {
        printf("No error.\n");
    }else {
        printf("Errors at ");
        for(int i = 0; i <= index_error; i++) {
            printf("%d", error[i]);
            if(i < index_error) printf(", ");
        }
        printf("\n%s", str);
    }

    return 0;
}