#include <cstdio>
int n;
int algorithm(int n) 
{
        if (n%5 == 0) return n/5;
        if (n%5 == 1 and n >= 6) return (n-6)/5 + 2;
        if (n%5 == 2 and n >= 12) return (n-12)/5 + 4;
        if (n%5 == 3 and n >= 3) return (n-3)/5 + 1;
        if (n%5 == 4 and n >= 9) return (n-9)/5 + 3;
        return -1;
}
int main() 
{
        scanf("%d", &n);
        printf("%d", algorithm(n));
}