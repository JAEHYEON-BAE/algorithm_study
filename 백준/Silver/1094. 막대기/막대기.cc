#include <cstdio>
int algorithm(int x)
{
    int a = 0;
    while (x > 0) {
        a += x&1;
        x >>= 1;   
    }   
    return a;
}
int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", algorithm(x));
}