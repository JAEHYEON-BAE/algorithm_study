#include <iostream>
#include <vector>
#include <queue>
#include <set>
int dfs(int start, const std::vector<std::set<int>>& map, const int& n, std::vector<int>& taller_than)
{
        std::queue<int> q;
        q.push(start);
        int cnt = 1;
        std::vector<bool> visited(n+1, false);
        visited[start] = true;
        while (!q.empty()) {
                int curr = q.front();
                q.pop();
                visited[curr] = true;
                for (int next: map[curr]) {
                        if (!visited[next]) {
                                q.push(next);
                                ++cnt;
                                visited[next] = true;
                                ++taller_than[next];
                        }
                }
        }
        return cnt;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;
        std::cin >> n >> m;
        std::vector<std::set<int>> map(n+1);
        for (int i=0;i<m;++i) {
                int a, b;
                std::cin >> a >> b;
                map[a].insert(b);
        }
        int cnt=0;
        std::vector<int> result(n+1, 0);
        for (int i=1;i<=n;++i) {
                result[i] += dfs(i, map, n, result);
        }
        for (int i=1;i<=n;++i) {
                if (result[i]==n) ++cnt;
        }
        std::cout << cnt;
        return 0;
}