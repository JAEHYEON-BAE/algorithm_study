#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> wine(n+1);
        for (int i=1;i<=n;++i) {
                std::cin >> wine[i];
        }
        std::vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = wine[1];
        dp[2] = wine[1] + wine[2];
        for (int i=3;i<=n;i++) {
                dp[i] = std::max(dp[i-1], std::max(dp[i-3]+wine[i-1]+wine[i], dp[i-2]+wine[i]));
        }
        std::cout << dp[n];
        return 0;
}