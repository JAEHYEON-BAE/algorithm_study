#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
        int n, k;
        scanf("%d %d", &n, &k);
        int items[101][2];
        for (int i=1;i<=n;i++) {
                int w, v;
                scanf("%d %d", &w, &v);
                items[i][0] = w;
                items[i][1] = v;
        }

        vector<vector<int>> kns(n+1, vector<int>(k+1, 0));

        for (int i=1;i<=n;i++) {
                for (int j=1;j<=k;j++) {
                        kns[i][j] = kns[i-1][j];
                        int w = items[i][0];
                        int v = items[i][1];
                        if (w <= j) {
                                kns[i][j] = max(kns[i][j], kns[i-1][j-w] + v);
                        }
                }
        }

        printf("%d", kns[n][k]);
        return 0;
}
