#include <iostream>
#include <vector>
#include <algorithm>
int dp(const std::vector<int>& v, const int& n) 
{
        if (n==1) return v[0];
        std::vector<int> dp(n+1, 0);
        dp[1] = v[0];
        for (int i=2;i<=n;i++) {
                dp[i] = std::max(dp[i-1], dp[i-2]+v[i-1]);
        }
        return dp[n];
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        while (true) {
                int n, m; std::cin >> m >> n;
                if (m==0&&n==0) break;
                std::vector<int> row(m);
                for (int i=0;i<m;i++) {
                        std::vector<int> x(n);
                        for (int j=0;j<n;j++) {
                                std::cin >> x[j];
                        }
                        row[i] = dp(x, n);
                }
                std::cout << dp(row, m) << "\n";
        }
        return 0;
}