#include <iostream>
#include <string>
#include <vector>
void dfs(const int& cnt, const int& n, const int& m, std::vector<int>& v, std::string& result)
{
        if (cnt == m) {
                for (int x: v) {
                        result += std::to_string(x) + " ";
//                      std::cout << x << " ";
                }
                result += '\n';
//              std::cout << std::endl;
                return;
        }
        for (int i=1;i<=n;++i) {
                v[cnt] = i;
                dfs(cnt+1, n, m, v, result);
        }
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<int> v(m);
        std::string result;
        dfs(0, n, m, v, result);
        std::cout << result;
        return 0;
}