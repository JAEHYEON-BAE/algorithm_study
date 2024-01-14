#include <ios>
#include <algorithm>
int main()
{
        int n; scanf("%d", &n);
        int s[1001], dp[1001];
        std::fill(dp, dp+1001, 0);
        int result = 0;
        for (int i=0;i<n;i++) {
                scanf("%d", &s[i]);
                for (int j=0;j<i;j++) {
                        if (s[i] > s[j]) {dp[i] = std::max(dp[i], dp[j]);}
                }
                dp[i] += 1;
                result = std::max(result, dp[i]);
        }
        printf("%d", result);
}