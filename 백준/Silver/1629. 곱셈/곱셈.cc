#include <cstdio>
long long a, b, c, x;
long long algorithm(long long b)
{
        if (b==0) {return 1;}
        if (b==1) {return a%c;}
        x = algorithm(b/2) %c;
        if (b%2) return x*x%c*a%c;
        else return x*x%c;
}
int main()
{
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("%lld", algorithm(b));
        return 0;
}