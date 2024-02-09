#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
int find(const int x, std::unordered_map<int, int>& roots)
{
        if (roots[x] == x) return x;
        return roots[x] = find(roots[x], roots);
}
void uni(int x, int y, std::unordered_map<int, int>& roots)
{
        x = find(x, roots);
        y = find(y, roots);
        roots[y] = x;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<std::vector<int>> map(n, std::vector<int>(n));
        std::unordered_map<int, int> roots;
        int max=0;
        for (int i=0;i<n;++i) {
                for (int j=0;j<n;++j) {
                        std::cin >> map[i][j];
                        max = std::max(max, map[i][j]);
                }
        }

        int cnt=0;

        for (int h=max;h>=0;--h) {
                for (int i=0;i<n;++i) {
                        for (int j=0;j<n;++j) {
                                if (map[i][j] > h && roots.find(i*n+j)==roots.end()) {
                                        roots[i*n+j] = i*n+j;
                                        if (i>0 && roots.find((i-1)*n+j)!=roots.end())  uni(i*n+j, (i-1)*n+j, roots);
                                        if (i<n-1&& roots.find((i+1)*n+j)!=roots.end()) uni(i*n+j, (i+1)*n+j, roots);
                                        if (j>0 && roots.find(i*n+j-1)!=roots.end())    uni(i*n+j, i*n+j-1, roots);
                                        if (j<n-1&& roots.find(i*n+j+1)!=roots.end())   uni(i*n+j, i*n+j+1, roots);
                                }
                        }
                }
                std::set<int> s;
                for (std::pair<int, int> x: roots) {
                        s.insert(find(x.first, roots));
                }

                cnt = std::max(cnt, (int)s.size());
        }
        std::cout << cnt;
        return 0;
}