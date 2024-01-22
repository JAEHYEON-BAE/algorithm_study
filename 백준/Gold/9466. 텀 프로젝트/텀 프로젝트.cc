#include <ios>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool visited[100010];
bool done[100010];
vector<int> graph;
int result;
void dfs(const int& start) 
{
        stack<int> stk;
        stk.push(start);
        visited[start] = true;
        int curr, next;
        while (!stk.empty()) {

                curr = stk.top();
                next = graph[curr];

                if (done[next]) {
                        result += stk.size();

                        while (!stk.empty()) {
                                done[stk.top()] = true;
                                stk.pop();
                        }
                        return;
                }

                if (!visited[next]) {
                        stk.push(next);
                        visited[next] = true;
                }
                else {
                        int k;
                        while (true) {
                                k = stk.top();
                                stk.pop();
                                done[k] = true;
                                if (k==next) {break;}
                        }

                        result += stk.size();

                        while (!stk.empty()) {
                                done[stk.top()] = true;
                                stk.pop();
                        }
                        return ;
                }
        }

}
int main()
{
        int t, n, x; scanf("%d", &t);
        for (;t>0;t--) {
                scanf("%d", &n);
                graph.clear();
                graph.resize(n+1);
                for (int i=1;i<=n;i++) {
                        scanf("%d", &graph[i]);
                }
                memset(visited, 0, sizeof(visited));
                memset(done, 0, sizeof(done));
                result = 0;

                for (int i=1;i<=n;i++) {
                        if (!visited[i]) {
                                dfs(i);
                        }
                }
                printf("%d\n", result);
        }
}