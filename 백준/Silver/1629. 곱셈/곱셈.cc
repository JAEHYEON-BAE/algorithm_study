#include <cstdio>
long long int a, b, c;
int main()
{
        scanf("%lld %lld %lld", &a, &b, &c);
        long long int result = 1;
        while (b > 0) {
                if (b%2==1) {result=result*a%c;}
                a=a*a%c;
                b/=2;
        }
        printf("%lld", result);
}