#include <ios>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define INF 1000000000

unordered_map<int, unordered_map<int, int>> graph;
vector<vector<int>> path;
int dist;
int n, m, s, d;

void dijkstra() 
{
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distances(n, INF);
        path.resize(n);

        pq.push({0, s});
        distances[s] = 0;

        while (!pq.empty()) {
                int curr = pq.top().second;
                int curr_d = pq.top().first;

                pq.pop();

                for (const auto& neighbor : graph[curr]) {
                        int next = neighbor.first;
                        int next_d = neighbor.second + curr_d;
                        if (next_d < distances[next]) {
                                distances[next] = next_d;
                                pq.push({next_d, next});
                                path[next].clear();
                                path[next].push_back(curr);
                        }
                        else if (next_d == distances[next]) {
//                              pq.push({next_d, next});
                                path[next].push_back(curr);
                        }
                }
        }
        dist = distances[d];
        return;
}
void cut(int i) {
        if (i == s) return;

        vector<bool> visited(n, false);
        stack<int> stack;
        stack.push(i);
        while (!stack.empty()) {
                int current = stack.top();
                stack.pop();

                for (int node : path[current]) {
                        graph[node].erase(current);

                        if (node != s && !visited[node]) {
                                stack.push(node);
                                visited[node] = true;
                        }
                }
        }
}



int main()
{
        while (true) {
                graph.clear();
                path.clear();

                scanf("%d%d", &n, &m);
                if (n==0 && m==0) {break;}
                scanf("%d%d", &s, &d);
                int u, v, p;
                for (int i=0;i<m;i++) {
                        scanf("%d%d%d", &u, &v, &p);
                        if (graph.find(u) == graph.end()) {graph[u] = {};}
                        else if (graph[u].find(v) != graph[u].end() && graph[u][v] < p) {continue;}
                        graph[u][v] = p;
                }
                dijkstra();

                if (dist >= INF) {printf("-1\n"); continue;}

                cut(d);
                dijkstra();
                if (dist >= INF) {printf("-1\n");}
                else {printf("%d\n", dist);}
        }
        return 0;
}