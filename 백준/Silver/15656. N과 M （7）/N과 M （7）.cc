#include <iostream>
#include <vector>
#include <algorithm>
void dfs(const int& cnt, const int& n, const int& m, const std::vector<int>& v, std::vector<int>& tmp)
{
        if (cnt==m) {
                for (int x: tmp) {
                        std::cout << x << ' ';
                }
                std::cout << '\n';
                return;
        }
        for (int i=0;i<n;++i) {
                tmp[cnt] = v[i];
                dfs(cnt+1, n, m, v, tmp);
        }
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<int> v(n);
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        std::vector<int> tmp(m);
        dfs(0, n, m, v, tmp);
        return 0;
}