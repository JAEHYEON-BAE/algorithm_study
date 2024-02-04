#include <iostream>
#define p 1000000007
// a*(a+1)* ... *(b-1)*b
long long int factorial(int a, int b)
{
        if (b==a) return a;
        return ((long long int)b * (long long int)factorial(a, b-1)%p)%p;
}
long long int power(long long int a, int n)
{
        if (n==0) return 1;
        if (n==1) return a;
        long long int tmp = power(a, n/2)%p;
        if (n%2==0)     return (tmp*tmp)%p;
        else return (((tmp*tmp)%p)*a)%p;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, k;       std::cin >> n >> k;
        if (n==k || k==0) {
                std::cout << "1";
                return 0;
        }
        long long int numer, denom;

        if (n-k>=k) {
                numer = factorial(n-k+1, n);
                denom = factorial(1, k);
        }
        else {
                numer = factorial(k+1, n);
                denom = factorial(1, n-k);
        }

        std::cout << ((numer%p)*(power(denom, p-2)%p))%p;
        return 0;
}