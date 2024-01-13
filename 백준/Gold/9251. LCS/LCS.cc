#include <ios>
#include <array>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
        array<array<int, 1001>, 1001> dp;
        char f[1001];
        char s[1001];
        scanf("%[^\n]", f);
        scanf("\n");
        scanf("%[^\n]", s);

        int m = (int) strlen(f);
        int n = (int) strlen(s);

        for (int i=0;i<=m;i++) {
                for (int j=0;j<=n;j++) {
                        if (i==0 || j==0) {dp[i][j] = 0; continue;}
                        if (f[i-1] == s[j-1]) {
                                dp[i][j] = dp[i-1][j-1] + 1;
                        }
                        else {
                                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                        }
                }
        }
        printf("%d", dp[m][n]);
        return 0;
}