#include <iostream>
#include <vector>
#include <set>
#include <cmath>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int a, b;       std::cin >> a >> b;
        std::vector<bool> is_prime(b+1, true);
        std::set<int> primes;
        for (int i=2;i<=sqrt(b)+1;++i) {
                if (is_prime[i]) {
                        for (int j=2;i*j<=b;++j) {
                                is_prime[i*j]=false;
                        }
                }
        }
        for (int i=2;i<=b;++i) {
                if (is_prime[i]) primes.insert(i);
        }
        std::vector<int> cnt(b+1);
        for (int p: primes) {
                cnt[p] = 1;
                for (int i=2;i*p<=b;++i) {
                        cnt[i*p] = 1 + cnt[i];
                }
        }

        int result = 0;
        for (;a<=b;++a) {
                if (primes.find(cnt[a])!=primes.end()) ++result;
        }
        std::cout << result;

        return 0;
}