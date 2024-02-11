#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> v(n+1);
        for (int i=1;i<=n;++i) {
                std::cin >> v[i];
        }
        std::vector<int> dp(1000001, 0);
        int result = 0;
        for (int i=1;i<=n;++i) {
                dp[v[i]] = std::max(1, dp[v[i]-1] + 1);
                result = std::max(result, dp[v[i]]);
        }
        std::cout << result;
        return 0;
}