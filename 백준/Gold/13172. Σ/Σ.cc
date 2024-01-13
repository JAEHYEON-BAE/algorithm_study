#include <ios>
#define P 1000000007
long long power(long long x, long long y) {
        long long result = 1;
        x = x % P;

        while (y > 0) {
                if (y % 2 == 1)
                        result = (result * x) % P;

                y = y / 2;
                x = (x * x) % P;
        }
        return result;
}
long long gcd(long x, long y) 
{
        while (y) {
                long tmp = x;
                x = y; y = tmp % y;
        }
        return x;
}

int main()
{
        int n; scanf("%d", &n);
        long long k[2] = {1, 0};
        for (int i=0;i<n;i++) {
                long long a, b; scanf("%lld %lld", &a, &b);
                long long g = gcd(a, b);
                a = a/g; b = b/g;
                long long x = k[0]*a;
                long long y = k[0]*b + k[1]*a;
                g = gcd(x, y);
                k[0] = (x/g)%P; k[1] = (y/g)%P;
        }
        long long result = ((power(k[0], P-2) % P) * k[1]) % P;
        printf("%lld", result);
        return 0;
}