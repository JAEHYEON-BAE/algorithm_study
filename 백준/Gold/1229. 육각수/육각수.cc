#include <ios>
#include <array>
#include <algorithm>
constexpr std::array<int, 710> h() {
        std::array<int, 710> hex = {};
        for (int i=0;i<710;i++) {
                hex[i] = 2*i*i + 3*i + 1;
        }
        return hex;
}
int main()
{
        constexpr std::array<int, 710> hex = h();
        static_assert(hex[499] == 499500);
        int n; scanf("%d", &n);
        int dp[1000000];
        std::fill(dp, dp+1000000, 10);
        dp[0] = 0;
        for (int i=1;hex[i]<=n;i++) {
                if (n==hex[i]) {printf("1"); return 0;}
        }
        for (int i=1;i<=n;i++) {
                for (int j=0;hex[j]<=i;j++) {
                        dp[i] = std::min(dp[i], dp[i-hex[j]] + 1);
                }
        }
        printf("%d", dp[n]);


        return 0;
}