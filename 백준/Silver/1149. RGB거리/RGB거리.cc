#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> houses;
void input_parsing()
{
        scanf("%d", &n);
        houses.resize(n, vector<int>(3));
        for (int i=0;i<n;i++) {
                scanf("%d %d %d", &houses[i][0], &houses[i][1], &houses[i][2]);
        }
}
int main()
{
        input_parsing();
        vector<vector<int>> dp;
        dp.resize(n, vector<int>(3));
        dp[0] = houses[0];
        for (int i=1;i<n;i++) {
                dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + houses[i][0];
                dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + houses[i][1];
                dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + houses[i][2];
        }
        printf("%d", *min_element(dp[n-1].begin(), dp[n-1].end()));
}