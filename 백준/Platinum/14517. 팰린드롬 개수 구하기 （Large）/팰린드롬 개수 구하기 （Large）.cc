#include <iostream>
#include <string>
#include <vector>

#define MOD 10007

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        std::string str;        std::cin >> str;
        size_t n = str.size();

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));    // dp[i][j] means number of pelindromes subsequences in range str[i~j];

        for (size_t i=0;i<n;++i) {
                dp[i][i] = 1;
        }
        for (size_t len=2;len<=n;++len) {
                for (size_t i=0;i<=n-len;++i) {
                        size_t j = i+len-1;
                        if (str[i]==str[j]) {
                                dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1)%MOD;
                        } else {
                                dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + MOD)%MOD;
                        }
                }
        }
        std::cout << dp[0][n-1];
        return 0;
}