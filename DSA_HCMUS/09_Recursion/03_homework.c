#include<stdio.h>

#define MAX 30

typedef struct
{
    int a[MAX];
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
void push(Stack* s, int value) {
    s->a[++s->top] = value;
}
int pop(Stack* s) {
    int value = s->a[s->top];
    --s->top;
    return value;
}
void displayStack(Stack* s) {
    printf("\nStack: ");
    for(int i = 0; i <= s->top; i++) {
        printf("%3d ", s->a[i]);
    }
    printf("\n");
}

//---------------------------------------
Stack s;

void recursion1(int *a) {
    if(*a == 1) {
        push(&s, 1);
        printf("STOPED\n");
        return;
    }
    push(&s, *a);
    recursion1(++a);
}

int recursion2(Stack *s) {
    if(isEmpty(s)) {
        return 0;
    }
    return pop(s) + recursion2(s);
}

int main() {

    init(&s);
    int a[20] = {10, 9, 8, 5, 6, 2, 3, 1, 6, 7, 1, 5, 6, 7, 5, 4, 2, 1, 10, 8};
    recursion1(a);
    int sum = 0;
    for(int i = 0; i < 8; i++) {
        sum += a[i];
    }
    printf("Sum use for loop is %d\n", sum);
    printf("Sum use recursion is %d\n", recursion2(&s));
    return 0;
}
