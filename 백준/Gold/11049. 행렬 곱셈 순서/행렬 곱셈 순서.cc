#include <ios>
#include <vector>
#define INF 1987654321
int main()
{
        int n; scanf("%d", &n);
        std::vector<std::pair<int, int>> a(n);
        std::vector<std::vector<long long int>> dp(n, std::vector<long long int>(n, INF));
        for (int i=0;i<n;i++) {
                int r, c; scanf("%d%d", &r, &c);
                a[i] = {r, c};
        }

        for (int i=0;i<n;i++) {
                dp[i][i] = 0;
                if (i < n-1) {
                        dp[i][i+1] = a[i].first * a[i].second * a[i+1].second;
                }
        }
        for (int j=2;j<n;j++) {
                for (int i=0;i+j<n;i++) {
                        for (int k=0;k<j;k++) {
                                dp[i][i+j] = std::min(dp[i][i+j], dp[i][i+k] + dp[i+k+1][i+j] + a[i].first * a[i+k].second * a[i+j].second);
                        }
                }
        }


        printf("%lld", dp[0][n-1]);
        return 0;
}