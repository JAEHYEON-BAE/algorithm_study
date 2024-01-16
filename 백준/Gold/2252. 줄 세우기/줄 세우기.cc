#include <ios>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
int main()
{
        int n, m, a, b;
        unordered_map<int, set<int>> post;
        unordered_map<int, set<int>> pre;
        queue<int> q;
        scanf("%d%d", &n, &m);

        for (int i=1;i<=n;i++) {
                post[i] = {}; pre[i] = {};
        }

        for (;m>0;m--) {
                scanf("%d%d", &a, &b);
                post[a].insert(b); pre[b].insert(a);
        }

        for (int i=1;i<=n;i++) {
                if (pre[i].size() == 0) {q.push(i);}
        }

        while (!q.empty()) {
                int curr = q.front();
                printf("%d ", curr);
                q.pop();
                for (int next: post[curr]) {
                        pre[next].erase(curr);
                        if (pre[next].size() == 0) {
                                q.push(next);
                        }
                }
        }
        return 0;
}