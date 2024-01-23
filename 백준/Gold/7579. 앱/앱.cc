#include <ios>
#include <vector>
#include <algorithm>
#define INF 1987654321

int main()
{
        int n, m; scanf("%d%d", &n, &m);
        int memory[101];
        int cost[101];
        int total_c=0;
        for (int i=1;i<=n;i++) {
                scanf("%d", &memory[i]);
        }
        for (int i=1;i<=n;i++) {
                scanf("%d", &cost[i]);
                total_c += cost[i];
        }

        std::vector<std::vector<int>> dp(n+1, std::vector<int>(total_c+1, 0));

        for (int i=0;i<=n;i++) {
                dp[i][0] = 0;
        }
        for (int i=0;i<=total_c;i++) {
                dp[0][i] = 0;
        }

        std::vector<int> result;

        for (int i=1;i<=n;i++) {
                for (int j=0;j<=total_c;j++) {
                        dp[i][j] = dp[i-1][j];
                        if (j>=cost[i]) {
                                dp[i][j] = std::max(dp[i][j], dp[i-1][j-cost[i]] + memory[i]);
                        }

                        if (dp[i][j] >= m) {
                                result.push_back(j);
                        }
                }
        }

        auto iter = std::min_element(result.begin(), result.end());
        if (iter==result.end()) {
                printf("-1"); return 0;
        }

        printf("%d", *iter);
        return 0;
}