#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1000000
int n; int x;
map<int, map<int, int>> graph;
map<int, map<int, int>> rgraph;
void input_parsing()
{
        int m;
        scanf("%d %d %d", &n, &m, &x);
        for (int i=0;i<m;i++) {
                int a; int b; int c;
                scanf("%d %d %d", &a, &b, &c);
                if (graph.find(a) == graph.end()) {graph[a] = {};}
                graph[a][b] = c;
                if (rgraph.find(b) == rgraph.end()) {rgraph[b] = {};}
                rgraph[b][a] = c;
        }
}
vector<int> dijkstra(bool reverse)
{
        map<int, map<int, int>> g = (reverse) ? rgraph : graph;
        vector<int> distances(n+1, INF);
        distances[x] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({x, 0});
        while (!pq.empty()) {
                int current = pq.top().first;
                int distance = pq.top().second;
                pq.pop();
                for (const auto& neighbor: g[current]) {
                        int next_node = neighbor.first;
                        int next_distance = distance + neighbor.second;
                        if (next_distance < distances[next_node]) {
                                distances[next_node] = next_distance;
                                pq.push({next_node, next_distance});
                        }
                }
        }
        return distances;
}
int main()
{
        input_parsing();
        vector<int> from = dijkstra(false);
        vector<int> to = dijkstra(true);
        int result = 0;
        for (int i=1;i<=n;i++) {
                if (i==x) {continue;}
                result = max(result, from[i] + to[i]);
        }
        printf("%d", result);
        return 0;
}