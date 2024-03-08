#include <iostream>
#include <cmath>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        long long int a, b;
        std::cin >> a >> b;
        --a;
        long long int cnt_a=0, cnt_b=0;
        int upper = (int)(log(b)/log(2));
        for (int i=0;i<=upper;++i) {
                long long int x = 1LL<<i;
                cnt_b += ((b/x+1)/2) * x;
                cnt_a += ((a/x+1)/2) * x;
        }
        std::cout << cnt_b - cnt_a;
        return 0;
}