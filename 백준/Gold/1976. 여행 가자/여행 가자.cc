#include <iostream>
#include <vector>
#include <set>
int find(const int& x, std::vector<int>& roots)
{
        if (x==roots[x]) return x;
        return roots[x] = find(roots[x], roots);
}
void uni(int x, int y, std::vector<int>& roots) 
{
        x = find(x, roots);
        y = find(y, roots);
        if (x!=y) roots[x]=y;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<int> roots(n);
        for (int i=0;i<n;++i) roots[i]=i;
        for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
                int x;  std::cin >> x;
                if (x) uni(i, j, roots);
        }
        std::vector<int> path(m);
        int tmp;
        for (int i=0;i<m;++i) {
                std::cin >> path[i];
                --path[i];
                if (i==0) {
                        tmp = find(path[i], roots);
                }
                else {
                        if (tmp==find(path[i], roots)) continue;
                        else {
                                std::cout << "NO";
                                return 0;
                        }
                }
        }
        std::cout << "YES";
        return 0;
}