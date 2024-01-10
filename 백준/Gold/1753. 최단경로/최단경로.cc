#include <cstdio>
#include <queue>
#include <unordered_map>
#include <algorithm>
#define MAX 2000000000
using namespace std;
int main()
{
        int v, e, k;
        unordered_map<int, unordered_map<int, int>> graph;
        scanf("%d %d", &v, &e);
        scanf("%d", &k);
        for (int i=1;i<=e;i++) {
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                if (graph.find(a) == graph.end()) {graph[a] = {};}
                else if (graph[a].find(b) != graph[a].end()) {
                        if (graph[a][b] > c) {graph[a].erase(b); graph[a][b] = c; continue;}
                        else {continue;}
                }
                graph[a][b] = c;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int distances[20010];
        fill(distances, distances + 20010, MAX);
        bool visited[20010];
        fill(visited, visited + 20010, false);
        pq.push({0, k});
        distances[k] = 0;
        while (!pq.empty()) {
                int c = pq.top().second;
                int d = pq.top().first;
                pq.pop();

                if (visited[c]) continue;
                visited[c] = true;

                for (const auto& neighbor : graph[c]) {
                        int next_n = neighbor.first;
                        int next_d = d + neighbor.second;
                        if (next_d < distances[next_n]) {
                                distances[next_n] = next_d;
                                pq.push({next_d, next_n});
                        }
                }
        }
        for (int i=1;i<=v;i++) {
                if (distances[i] < MAX) {
                        printf("%d\n", distances[i]);
                } else {
                        printf("INF\n");
                }
        }
        return 0;
}