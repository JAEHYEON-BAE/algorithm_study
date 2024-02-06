#include <iostream>
int gcd(int a, int b)
{
        if (b==0) {return a;}
        if (b==1) {return 1;}
        return gcd(b, a%b);
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::cout << m-gcd(n, m);
        return 0;
}