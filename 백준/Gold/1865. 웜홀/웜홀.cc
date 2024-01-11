#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1987654321
vector<vector<int>> graph;
int n;
void input_parsing()
{
        n = 0;
        int m, w;
        graph.clear();
        scanf("%d %d %d", &n, &m, &w);
        for (int j=0;j<m;j++) {
                int s, e, t;
                scanf("%d %d %d", &s, &e, &t);
                graph.push_back({s, e, t});
                graph.push_back({e, s, t});
        }
        for (int j=0;j<w;j++) {
                int s, e, t;
                scanf("%d %d %d", &s, &e, &t);
                t *= -1;
                graph.push_back({s, e, t});
        }
}
void algorithm()
{
        int distance[510];
        fill(distance, distance+510, INF);;
        distance[1] = 0;
        for (int i=1;i<n+1;i++) {
                for (const auto& v : graph) {
                        int from = v[0]; int to = v[1]; int cost = v[2];
                        if (from == to && cost < 0) {printf("YES\n"); return;}
                        if (distance[from] + cost < distance[to]) {
                                distance[to] = distance[from] + cost;
                        }
                }
        }
        for (int i=0;i<n;i++) {
                for (const auto& v : graph) {
                        int from = v[0]; int to = v[1]; int cost = v[2];
                        if (distance[from] + cost < distance[to]) {
                                printf("YES\n"); return;
                        }
                }
        }
        printf("NO\n"); return;
}
int main()
{
        int t; scanf("%d", &t);
        for (int i=0;i<t;i++) {
                input_parsing();
                algorithm();
        }
        return 0;
}