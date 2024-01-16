#include <ios>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;
int main()
{
        int n, m; scanf("%d%d", &n, &m);
        int x;
        vector<vector<int>> v(m);
        unordered_map<int, set<int>> pre;
        unordered_map<int, set<int>> graph;
        for (int i=0;i<n;i++) {
                pre[i] = {};
        }

        for (int i=0;i<m;i++) {
                scanf("%d", &x);
                vector<int> s(x);
                for (int j=0;j<x;j++) {
                        scanf("%d", &s[j]);
                        if (graph.find(s[j]) == graph.end()) {graph[s[j]] = {};}
                        if (j>0) {
                                pre[s[j]].insert(s[j-1]);
                                graph[s[j-1]].insert(s[j]);
                        }
                }
        }

        queue<int> q;
        vector<int> result;

        for (int i=1;i<=n;i++) {
                if (pre[i].size() == 0) {q.push(i);}
        }

        while (!q.empty()) {
                int curr = q.front();
                q.pop();
                result.push_back(curr);
                for (int next: graph[curr]) {
                        pre[next].erase(curr);
                        if (pre[next].size() == 0) {q.push(next);}
                }
        }

        if (result.size() < n) {printf("0"); return 0;}
        else {
                for (int i=0;i<result.size();i++) {
                        printf("%d\n", result[i]);
                }
                return 0;
        }
}