#include <ios>
#include <vector>
#include <algorithm>
#define INF 987654321
int main()
{
        int n; scanf("%d", &n);
        std::vector<std::vector<int>> v(n+1, std::vector<int>(3));
        for (int i=1;i<=n;i++) {
                scanf("%d%d%d", &v[i][0], &v[i][1], &v[i][2]);
        }
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(3, 0));
        int result = INF;
        for (int i=0;i<3;i++) {
                // case 0: house 1 is red
                if (i==0) {
                        dp[1][0] = v[1][0]; dp[1][1] = INF; dp[1][2] = INF;
                }
                else if (i==1) {
                        dp[1][0] = INF; dp[1][1] = v[1][1]; dp[1][2] = INF;
                }
                else {
                        dp[1][0] = INF; dp[1][1] = INF; dp[1][2] = v[1][2];
                }

                for (int j=2;j<=n;j++) {
                        dp[j][0] = v[j][0] + std::min(dp[j-1][1], dp[j-1][2]);
                        dp[j][1] = v[j][1] + std::min(dp[j-1][0], dp[j-1][2]);
                        dp[j][2] = v[j][2] + std::min(dp[j-1][0], dp[j-1][1]);
                }
                int tmp;
                if (i==0) {tmp = std::min(dp[n][1], dp[n][2]);}
                else if (i==1) {tmp = std::min(dp[n][0], dp[n][2]);}
                else {tmp = std::min(dp[n][0], dp[n][1]);}

                result = std::min(result, tmp);
        }
        printf("%d", result);
}