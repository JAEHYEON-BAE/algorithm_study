#include <cstdio>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define INF 1987654321
unordered_map<int, unordered_map<int, int>> graph;
int n;
void dijkstra(int start, int end)
{
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int distances[1010];
        fill(distances, distances+1010, INF);
        distances[start] = 0;
        pq.push({0, start});
        while (!pq.empty()) {
                int curr = pq.top().second;
                int dist = pq.top().first;
                pq.pop();
                for (const auto& neighbor : graph[curr]) {
                        int next = neighbor.first;
                        int next_dist = neighbor.second + dist;
                        if (next_dist < distances[next]) {
                                distances[next] = next_dist;
                                pq.push({next_dist, next});
                        }
                }
        }
        printf("%d", distances[end]);
        return;
}

int main()
{
        scanf("%d", &n);
        int m; scanf("%d", &m);
        for (int i=0;i<m;i++) {
                int s, e, c;
                scanf("%d %d %d", &s, &e, &c);
                if (graph.find(s) == graph.end()) {graph[s] = {};}
                else if (graph[s].find(e) != graph[s].end() && graph[s][e] < c) {continue;}
                graph[s][e] = c;
        }
        int start, end;
        scanf("%d %d", &start, &end);
        dijkstra(start, end);
        return 0;
}