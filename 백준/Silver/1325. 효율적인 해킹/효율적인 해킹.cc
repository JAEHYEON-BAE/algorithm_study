#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
int dfs(const int start, std::vector<std::vector<int>>& graph, const int& n)
{
        std::stack<int> stk;
        std::vector<bool> visited(n+1, false);
        stk.push(start);
        int cnt = 1;
        while (!stk.empty()) {
                int curr = stk.top();
                stk.pop();
                visited[curr] = true;
                ++cnt;
                for (int neighbor: graph[curr]) {
                        if (!visited[neighbor]) {
                                visited[neighbor] = true;
                                stk.push(neighbor);
                        }
                }
        }
        return cnt;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<std::vector<int>> graph(n+1, std::vector<int>());
        while (m--) {
                int a, b;
                std::cin >> a >> b;
                graph[b].push_back(a);
        }
        int max = 0;
        std::vector<int> result;
        for (int i=1;i<=n;++i) {
                int cnt = dfs(i, graph, n);
                if (cnt > max) {
                        max = cnt;
                        result = std::vector<int>();
                        result.push_back(i);
                }
                else if (cnt==max) {
                        result.push_back(i);
                }
                else continue;
        }
        for (int x: result) {
                std::cout << x << " ";
        }
        return 0;
}