#include <stdio.h>
#include <string.h>
#define MAX 30

typedef struct
{
    char a[MAX];
    int top;
} Stack_c;

typedef struct
{
    int a[MAX];
    int top;
} Stack_i;

void init(Stack_c *s) { s->top = -1; }

void init1(Stack_i *s) { s->top = -1; }

int isEmpty(Stack_c *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isEmptyi(Stack_i *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

void pop(Stack_c *s)
{
    if (!isEmpty(s))
    {
        --s->top;
    }
    return;
}

void popi(Stack_i *s)
{
    if (!isEmptyi(s))
    {
        --s->top;
    }
    return;
}

void push(Stack_c *s, char c)
{
    s->top++;
    s->a[s->top] = c;
}

void pushi(Stack_i *s, int v)
{
    s->top++;
    s->a[s->top] = v;
}

char top(Stack_c *s) { return s->a[s->top]; }

char topi(Stack_i *s) { return s->a[s->top]; }

int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

void solve(char s[])
{
    Stack_c st1;
    init(&st1);
    int n = strlen(s);
    char hauto[MAX] = "";
    int idx = 0; // chi so cua hau to
    for (int i = 0; i < n; i++)
    {
        if (is_digit(s[i]))
        {
            hauto[idx++] = s[i];
        }
        else
        {
            while (!isEmpty(&st1) && getPrecedence(top(&st1)) >= getPrecedence(s[i]))
            {
                hauto[idx++] = top(&st1);
                pop(&st1);
            }
            push(&st1, s[i]);
        }
    }
    while (!isEmpty(&st1))
    {
        hauto[idx++] = top(&st1);
        pop(&st1);
    }

    printf("%s\n", hauto);
    // tinh toan -------------
    Stack_i st2;
    init1(&st2);
    for (int i = 0; i < strlen(hauto); i++)
    {
        if (is_digit(hauto[i]))
        {
            pushi(&st2, hauto[i] - '0');
        }
        else
        {
            int t2 = topi(&st2);
            popi(&st2);
            int t1 = topi(&st2);
            popi(&st2);
            if (hauto[i] == '+')
            {
                pushi(&st2, t1 + t2);
            }
            else if (hauto[i] == '-')
            {
                pushi(&st2, t1 - t2);
            }
            else if (hauto[i] == '*')
            {
                pushi(&st2, t1 * t2);
            }
            else
            {
                if (t2 != 0)
                {
                    pushi(&st2, t1 / t2);
                }
                else
                {
                    printf("Lỗi chia cho 0.\n");
                    return;
                }
            }
        }
    }
    printf("%d", topi(&st2));
}

int main()
{
    char s[] = "2+3*4-5";
    solve(s);
    return 0;
}
