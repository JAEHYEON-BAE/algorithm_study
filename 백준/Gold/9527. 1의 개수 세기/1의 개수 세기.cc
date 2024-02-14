#include <iostream>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        long long int a, b;
        std::cin >> a >> b;
        long long int cnt_b=0, cnt_a=0;
        int i=0;
        while (1LL<<i <= b) {
                long long int tmp = 1LL<<(i+1);
                cnt_b += (b/tmp)*(tmp/2) + (b%tmp)/(tmp/2)*((b%tmp)%(tmp/2)+1);
                ++i;
        }
        i=0;
        --a;
        while (1LL<<i <= a) {
                long long int tmp = 1LL<<(i+1);
                cnt_a += (a/tmp)*(tmp/2) + (a%tmp)/(tmp/2)*((a%tmp)%(tmp/2)+1);
                ++i;
        }
        std::cout << cnt_b - cnt_a;
        return 0;
}