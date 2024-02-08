#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
int dfs(const std::vector<std::string>& map, std::vector<std::vector<bool>>& visited, const int& i, const int& j, const int& n)
{
        std::stack<std::pair<int, int>> stk;
        stk.push({i, j});
        int cnt=1;
        while (!stk.empty()) {
                int a = stk.top().first;
                int b = stk.top().second;
                stk.pop();
                visited[a][b] = true;
                std::vector<std::pair<int, int>> neighbors;
                if (a>0 && map[a-1][b]=='1') neighbors.push_back({a-1, b});
                if (a<n-1 && map[a+1][b]=='1') neighbors.push_back({a+1, b});
                if (b>0 && map[a][b-1]=='1') neighbors.push_back({a, b-1});
                if (b<n-1 && map[a][b+1]=='1') neighbors.push_back({a, b+1});
                for (std::pair<int, int> next: neighbors) {
                        if (visited[next.first][next.second]==false) {
                                visited[next.first][next.second]=true;
                                stk.push(next);
                                ++cnt;
                        }
                }
        }
        return cnt;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<std::string> map(n);
        for (int i=0;i<n;i++) {
                std::cin >> map[i];
        }
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        std::vector<int> result;
        for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                        if (map[i][j]=='1' && visited[i][j]==false) {
                                result.push_back(dfs(map, visited, i, j, n));
                        }
                }
        }
        std::cout << result.size() << "\n";
        std::sort(result.begin(), result.end());
        for (int x: result) {
                std::cout << x << "\n";
        }
        return 0;
}