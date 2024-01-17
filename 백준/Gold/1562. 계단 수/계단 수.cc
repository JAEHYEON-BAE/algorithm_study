#include <ios>
#include <bitset>
using namespace std;
#define Q 1000000000
int main()
{
        int n; scanf("%d", &n);
        long long int dp[101][10][1024] = {};

        for (int i=1;i<10;i++) {
                dp[1][i][1<<i] = 1;
        }

        for (int i=1;i<n;i++) {
                for (int j=0;j<10;j++) {
                        for (int k=0;k<1024;k++) {
                                if (j>=1) {
                                        dp[i+1][j][k | (1<<j)] += dp[i][j-1][k];
                                }
                                if (j<=8) {
                                        dp[i+1][j][k | (1<<j)] += dp[i][j+1][k];
                                }
                                dp[i][j][k | (1<<j)] %= Q;
                        }
                }
        }

        long long int result = 0;

        for (int i=0;i<10;i++) {
                result += dp[n][i][1023];
                result %= Q;
        }
        printf("%lld", result);
        return 0;
}