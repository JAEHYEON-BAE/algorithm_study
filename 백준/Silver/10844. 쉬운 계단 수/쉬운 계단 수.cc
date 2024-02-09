#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n;  std::cin >> n;
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(10, 0));
        for (int i=1;i<10;++i) {
                dp[1][i] = 1;
        }
        for (int i=2;i<=n;++i) {
                for (int j=0;j<10;++j) {
                        if (j>0)        dp[i][j] = (dp[i][j]+dp[i-1][j-1])%1000000000;
                        if (j<9)        dp[i][j] = (dp[i][j]+dp[i-1][j+1])%1000000000;
                }
        }
        int result=0;
        for (int i=0;i<10;++i) {
                result = (result+dp[n][i])%1000000000;
        }
        std::cout << result;
        return 0;
}