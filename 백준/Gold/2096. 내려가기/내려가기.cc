#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
        int n; scanf("%d", &n);
        vector<int> dp(3, 0), rdp(3, 0), temp(3, 0);
        for (int i=0;i<n;i++) {
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                if (i>0) {
                        temp[0] = a + max(dp[0], dp[1]);
                        temp[1] = b + max({dp[0], dp[1], dp[2]});
                        temp[2] = c + max(dp[1], dp[2]);
                        dp = temp;
                        temp[0] = a + min(rdp[0], rdp[1]);
                        temp[1] = b + min({rdp[0], rdp[1], rdp[2]});
                        temp[2] = c + min(rdp[1], rdp[2]);
                        rdp = temp;
                }
                else {
                        dp[0] = rdp[0] = a;
                        dp[1] = rdp[1] = b;
                        dp[2] = rdp[2] = c;
                }

        }
        printf("%d %d", max({dp[0], dp[1], dp[2]}), min({rdp[0], rdp[1], rdp[2]}));
        return 0;
}