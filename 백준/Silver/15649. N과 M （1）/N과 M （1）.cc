#include <iostream>
#include <vector>
#include <algorithm>
void dfs(const int& cnt, const int& n, const int& m, std::vector<int>& v, std::vector<bool>& visited) 
{
        if (cnt == m) {
                for (int x: v) 
                        std::cout << x << " ";
                std::cout << "\n";
                return;
        }
        for (int i=1;i<=n;++i) {
                if (!visited[i]) {
                        visited[i] = true;
                        v[cnt] = i;
                        dfs(cnt+1, n, m, v, visited);
                        visited[i] = false;
                }
        }
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<int> v(m);
        std::vector<bool> visited(n+1, false);
        dfs(0, n, m, v, visited);
        return 0;
}