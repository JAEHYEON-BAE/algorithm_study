#include <stdio.h>
#include <iostream>
using namespace std;

int 
algorithm(int n, int m)
{
        int dp[n+1][m+1];

        for (int i = 1; i < m+1; i++) {
                dp[1][i] = i;
        }

        for (int i = 1; i < n+1; i++) {
                dp[i][i] = 1;
                dp[i][i + 1] = i + 1;
        }

        for (int i = 2; i < n+1; i++) {
                for (int j = i; j < m+1; j++) {
                        dp[i][j] = 0;
                        for (int k = i-1; k < j; k++) {
                                dp[i][j] += dp[i-1][k];
                        }
                }
        }

        return dp[n][m];
}
int
main()
{
        int T = 0;
        cin >> T;
        for (int i = 0; i < T; ++i) {
                int n; int m;
                cin >> n >> m;
                cout << algorithm(n, m) << endl;
        }
}