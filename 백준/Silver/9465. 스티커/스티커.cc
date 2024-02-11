#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int t; std::cin >> t;
        while (t--) {
                int n;  std::cin >> n;
                std::vector<std::vector<int>> v(2, std::vector<int>(n));
                for (int i=0;i<2;++i) {
                        for (int j=0;j<n;++j) {
                                std::cin >> v[i][j];
                        }
                }
                std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));
                dp[0][0] = v[0][0];
                dp[0][1] = v[1][0];
                dp[0][2] = 0;
                // 2 means don't select
                for (int i=1;i<n;++i) {
                        dp[i][0] = v[0][i] + std::max(dp[i-1][2], dp[i-1][1]);
                        dp[i][1] = v[1][i] + std::max(dp[i-1][2], dp[i-1][0]);
                        dp[i][2] = std::max(dp[i-1][2], std::max(dp[i-1][0], dp[i-1][1]));
                }
                std::cout << std::max(dp[n-1][0], std::max(dp[n-1][1], dp[n-1][2])) << "\n";
        }
        return 0;
}