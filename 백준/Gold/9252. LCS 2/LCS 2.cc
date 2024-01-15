#include <ios>
#include <cstring>
using namespace std;
int main()
{
        char x[1000], y[1000], lcs[1000];
        scanf("%s%s", x, y);
        int xlen = strlen(x);
        int ylen = strlen(y);
        int dp[1001][1001];
        int len = 0;
        for (int i=0;i<=xlen;i++) {
                for (int j=0;j<=ylen;j++) {
                        if (i==0 || j==0) {dp[i][j] = 0; continue;}
                        if (x[i-1] == y[j-1]) {
                                dp[i][j] = dp[i-1][j-1] + 1; 
                                continue;}
                        else {dp[i][j] = max(dp[i-1][j], dp[i][j-1]); continue;}
                }
        }

        printf("%d\n", dp[xlen][ylen]);

        while (xlen > 0 && ylen > 0) {
                if (x[xlen-1] == y[ylen-1]) {
                        lcs[len++] = x[xlen-1];
                        --xlen; --ylen;
                }
                else if (dp[xlen-1][ylen] > dp[xlen][ylen-1]) {
                        --xlen;
                }
                else {--ylen;}
        }


        --len;
        for(;len>=0;len--) {
                printf("%c", lcs[len]);
        }

        return 0;
}