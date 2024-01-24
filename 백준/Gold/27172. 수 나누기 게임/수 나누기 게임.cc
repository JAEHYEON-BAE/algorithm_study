#include <ios>
#include <vector>
#include <algorithm>
int main()
{
        int n; scanf("%d", &n);
        std::vector<int> v(n);
        int score[1000001] = {};
        bool exist[1000001] = {};
        for (int i=0;i<n;i++) {
                scanf("%d", &v[i]);
                exist[v[i]] = true;
        }

        for (int x: v) {
                for (int y = x*2; y < 1000001; y += x) {
                        if (exist[y]) {
                                ++score[x];
                                --score[y];
                        }
                }
        }

        for (int x: v) {
                printf("%d ", score[x]);
        }
}