#include <ios>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
        int t, n, m; scanf("%d%d", &t, &n);
        vector<int> a(n);
        for (int i=0;i<n;i++) {
                scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        vector<int> b(m);
        for (int i=0;i<m;i++) {
                scanf("%d", &b[i]);
        }

        vector<vector<int>> dp_a(n, vector<int>(n, 0)), dp_b(m, vector<int>(m, 0));
        vector<int> subsum_a, subsum_b;

        for (int i=0;i<n;i++) {
                dp_a[i][i] = a[i];
                subsum_a.push_back(dp_a[i][i]);
                for (int j=i+1;j<n;j++) {
                        dp_a[i][j] = dp_a[i][j-1] + a[j];
                        subsum_a.push_back(dp_a[i][j]);
                }
        }

        for (int i=0;i<m;i++) {
                dp_b[i][i] = b[i];
                subsum_b.push_back(dp_b[i][i]);
                for (int j=i+1;j<m;j++) {
                        dp_b[i][j] = dp_b[i][j-1] + b[j];
                        subsum_b.push_back(dp_b[i][j]);
                }
        }

        sort(subsum_a.begin(), subsum_a.end());
        sort(subsum_b.begin(), subsum_b.end());

        unordered_map<int, int> dp;

        long long int result = 0;
        for (int x: subsum_a) {

                int k = 0;
                if (x + subsum_b[0] > t) {break;}
                if (dp.find(x) != dp.end()) {result += dp[x]; continue;}
                auto iter = lower_bound(subsum_b.begin(), subsum_b.end(), t-x);
                if (iter == subsum_b.end()) {continue;}

                for (;iter<subsum_b.end();iter++) {
                        if (*iter > t-x) {break;}
                        if (*iter == t-x) {
                                ++k;
                        }
                }
                dp[x] = k;
                result += k;
        }
        printf("%lld", result);
}