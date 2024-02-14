#include <iostream>
#include <string>
#include <vector>
void dfs(const int& cnt, const int& n, const int& m, std::vector<int>& v, std::vector<bool>& visited, std::string& result)
{
        if (cnt == m) {
                for (int x: v) {
                        result += std::to_string(x) + " ";
                }
                result += '\n';
                return;
        }
        for (int i=1;i<=n;++i) {
                if (!visited[i] && (cnt==0 || i>=v[cnt-1])) {
                        v[cnt] = i;
                        dfs(cnt+1, n, m, v, visited, result);
                }
        }
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<int> v(m);
        std::vector<bool> visited(n+1);
        std::string result;
        dfs(0, n, m, v, visited, result);
        std::cout << result;
        return 0;
}