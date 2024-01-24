#include <ios>
#include <vector>
#define INF 987654321
inline int move(int x, int y) 
{
        // move to y from x
        if (y==x) {return 1;}
        if (x==0) {return 2;}
        if (y-x == 2 || y-x == -2) {return 4;}
        return 3;
}
int main()
{
        std::vector<int> v;
        while (true) {
                int x; scanf("%d", &x);
                if (x==0) {break;}
                v.push_back(x);
        }

        int n = (int) v.size();
        std::vector<std::vector<std::vector<int>>> dp(n+1, std::vector<std::vector<int>>(5, std::vector<int>(5, INF)));
        dp[0][0][0] = 0;
        for (int i=1;i<=n;i++) {
                for (int j=0;j<5;j++) {
                        for (int k=0;k<5;k++) {
                                dp[i][v[i-1]][k] = std::min(dp[i][v[i-1]][k], dp[i-1][j][k] + move(j, v[i-1]));
                                dp[i][j][v[i-1]] = std::min(dp[i][j][v[i-1]], dp[i-1][j][k] + move(k, v[i-1]));
                        }
                }
        }

        int result = INF;
        for (int i=0;i<5;i++) {
                for (int j=0;j<5;j++) {
                        result = std::min(result, dp[n][i][j]);
                }
        }
        printf("%d", result);
        return 0;
}