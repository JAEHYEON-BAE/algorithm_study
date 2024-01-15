#include <ios>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
        int t, n, k, d, x, y, w;
        int times[1001], par[1001], result[1001];
        scanf("%d", &t);
        for (;t>0;t--) {
                fill(times, times+1001, 0);
                fill(par, par+1001, 0);
                fill(result, result+1001, 0);
                queue<int> q;

                scanf("%d%d", &n, &k);
                for (int i=1;i<=n;i++) {
                        scanf("%d", &times[i]);
                }
                unordered_map<int, vector<int>> graph;
                for (int i=0;i<k;i++) {
                        scanf("%d%d", &x, &y);
                        if (graph.find(x) == graph.end()) {graph[x] = {};}
                        graph[x].push_back(y);
                        par[y]++;
                }
                scanf("%d", &w);

                for (int i=1;i<=n;i++) {
                        if (par[i] == 0) {q.push(i);}
                }

                while (par[w] > 0) {
                        int curr = q.front();
                        q.pop();
                        for (int next : graph[curr]) {
                                result[next] = max(result[next], result[curr] + times[curr]);
                                par[next]--;
                                if (par[next] == 0) {q.push(next);}
                        }
                }

                printf("%d\n", result[w] + times[w]);
        }
        return 0;
}