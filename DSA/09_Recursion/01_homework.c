#include<stdio.h>

int f(int n)
{
    if (n == 1)
        return 1;
    return f(n-1)*2;
}
//------------------------
float g(int n)
{
    if (n == 1)
        return 1.0;
    return 1.0 * n * n + g(n - 1);
}
//------------------------
int F(int n)
{
    if (n == 1) return 1;
if (n == 2) return 1;
    return F(n-1)+F(n-2);
}
//------------------------
int P(int n)
{
    if (n == 0) return 1;
	if (n == 2) return 2;
    return P(n-1)*P(n-3);
}

int main() {
    printf("b3: %d, b4: %d\n", F(3), F(4));
    return 0;
}