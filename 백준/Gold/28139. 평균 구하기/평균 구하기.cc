#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
inline long double distance(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
        long double tmp = (long double)(a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
        return std::sqrt(tmp);
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<std::pair<int, int>> map(n);
        for (int i=0;i<n;++i) {
                std::cin >> map[i].first >> map[i].second;
        }
        int comb = n*(n-1)/2;
        long double result = 0;
        for (int i=0;i<n-1;++i) for (int j=i+1;j<n;++j) {
                result += distance(map[i], map[j]) * (n-1) / comb;
        }
        std::cout << std::fixed << std::setprecision(10) << result;
        return 0;
}