#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
void dfs(std::unordered_map<int, std::set<int>>& graph, const int& v, const int& n)
{
        std::vector<bool> visited(n+1, false);
        std::stack<int> stk;
        stk.push(v);
        while (!stk.empty()) {
                int curr = stk.top();
                stk.pop();
                if (visited[curr]) continue;
                visited[curr] = true;
                std::cout << curr << " ";
                for (std::set<int>::reverse_iterator neighbor = graph[curr].rbegin(); neighbor != graph[curr].rend(); ++neighbor) {
                        if (visited[*neighbor] == false) {
                                stk.push(*neighbor);
                        }
                }
        }
        std::cout << "\n";
        return;
}
void bfs(std::unordered_map<int, std::set<int>>& graph, const int& v, const int& n)
{
        std::vector<bool> visited(n+1, false);
        std::queue<int> q;
        q.push(v);
        while (!q.empty()) {
                int curr = q.front();
                q.pop();
                if (visited[curr]) continue;
                visited[curr] = true;
                std::cout << curr << " ";
                for (int neighbor: graph[curr]) {
                        if (visited[neighbor] == false) {
                                q.push(neighbor);
                        }
                }
        }
        std::cout << "\n";
        return;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m, v;    std::cin >> n >> m >> v;
        std::unordered_map<int, std::set<int>> graph;
        for (int i=0;i<m;i++) {
                int a, b;
                std::cin >> a >> b;
                graph[a].insert(b);
                graph[b].insert(a);
        }
        dfs(graph, v, n);
        bfs(graph, v, n);
        return 0;
}