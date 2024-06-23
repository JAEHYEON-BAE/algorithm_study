#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
long double sqrt(const long long int& number, double precision)
{
        double low = 0;
        double high = number;
        double mid;
        while (high-low>precision) {
                mid = (high+low)/2;
                if (mid*mid > number) {
                        high = mid;
                } else {
                        low = mid;
                }
        }
        return (high+low)/2;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int t;  std::cin >> t;
        while (t--) {
                int n;  std::cin >> n;
                std::vector<std::pair<int, int>> pairs(n);
                for (int i=0;i<n;++i) {
                        std::cin >> pairs[i].first >> pairs[i].second;
                }
                std::vector<bool> v(n);
                std::fill(v.begin(), v.begin() + n / 2, true);
                long long int result = (1LL<<62);
                do {
                        long long dx=0, dy=0;
                        for (int i=0;i<n;++i) {
                                std::pair<int, int> p = pairs[i];
                                if (v[i]) {
                                        dx += p.first;
                                        dy += p.second;
                                } else {
                                        dx -= p.first;
                                        dy -= p.second;
                                }
                        }
                        result = std::min(result, dx*dx + dy*dy);
                } while (std::prev_permutation(v.begin(), v.end()));

                std::cout << std::fixed << std::setprecision(8) << sqrt(result, 1e-7) << '\n';
        }
        return 0;
}