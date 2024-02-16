#include <iostream>
#include <string>
#include <vector>
#include <stack>
void dfs(const std::pair<int, int>& start, const std::vector<std::string>& map, std::vector<std::vector<bool>>& visited, const int& n)
{
        std::stack<std::pair<int, int>> stk;
        stk.push(start);
        while (!stk.empty()) {
                const auto [a, b] = stk.top();
                stk.pop();
                visited[a][b] = true;
                std::vector<std::pair<int, int>> neighbors;
                if (a>0)        neighbors.push_back({a-1, b});
                if (b>0)        neighbors.push_back({a, b-1});
                if (a<n-1)      neighbors.push_back({a+1, b});
                if (b<n-1)      neighbors.push_back({a, b+1});
                for (const std::pair<int, int>& next: neighbors) {
                        const auto [r, c] = next;
                        if (!visited[r][c] && map[r][c]==map[a][b]) {
                                visited[r][c] = true;
                                stk.push({r, c});
                        }
                }
        }
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<std::string> map(n);
        for (int i=0;i<n;++i) {
                std::cin >> map[i];
        }
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        int cnt=0;
        for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
                if (!visited[i][j]) {
                        dfs(std::make_pair(i, j), map, visited, n);
                        ++cnt;
                }
        }
        for (std::string& x: map) for (int i=0;i<n;++i) {
                if (x[i]=='G') x[i]='R';
        }
        std::vector<std::vector<bool>> x_visited(n, std::vector<bool>(n, false));
        int x_cnt=0;
        for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
                if (!x_visited[i][j]) {
                        dfs(std::make_pair(i, j), map, x_visited, n);
                        ++x_cnt;
                }
        }
        std::cout << cnt << ' ' << x_cnt;
        return 0;
}
