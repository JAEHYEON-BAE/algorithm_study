#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
        int n; scanf("%d", &n);
        vector<int> dp(n, 0);
        for (int i=0;i<n;i++) {
                if (i==0) {
                        int x; scanf("%d", &x);
                        dp[0] = x;
                        continue;
                }
                vector<int> num(i+1, 0);
                for (int j=0;j<i+1;j++) {
                        int x;
                        scanf("%d ", &x);
                        num[j] = x;
                }
                vector<int> temp(n, 0);
                for (int j=0;j<i+1;j++) {
                        if (j==0) {
                                temp[0] = dp[0] + num[0];}
                        else if (j==i) {
                                temp[j] = dp[j-1] + num[j];}
                        else {
                                temp[j] = max(dp[j-1], dp[j]) + num[j];}
                }
                dp = temp;
        }
        printf("%d", *max_element(dp.begin(), dp.end()));
}