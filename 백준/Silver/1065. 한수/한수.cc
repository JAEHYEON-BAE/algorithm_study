#include <cstdio> 
int n;
int algorithm(int n)
{
        if (n<100) return n;
        if (n==1000) return algorithm(999);
        int count=99;
        for (int i=100;i<=n;i++) if ((i/100)%10 - (i/10)%10 == (i/10)%10 - i%10) count++;
        return count;
}
int main()
{
        scanf("%d", &n);
        printf("%d", algorithm(n));
}