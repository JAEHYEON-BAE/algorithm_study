#include <ios>
#include <set>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
int candies[30001];
bool visited[30001];
std::unordered_map<int, std::set<int>> map;
std::vector<int> v;
std::vector<int> w;
void dfs(const int& start)
{
        std::stack<int> stk;
        stk.push(start);
        visited[start] = true;
        int x=0, y=0;
        while (!stk.empty()) {
                int curr = stk.top();
                stk.pop();
                x += candies[curr];
                ++y;
                for (int next: map[curr]) {
                        if (!visited[next]) {
                                stk.push(next);
                                visited[next] = true;
                        }
                }
        }
        v.push_back(x);
        w.push_back(y);
}

int main()
{
        int n, m, k; scanf("%d%d%d", &n, &m, &k);
        for (int i=1;i<=n;i++) {
                scanf("%d", &candies[i]);
        }
        for (int i=0;i<m;i++) {
                int x, y;
                scanf("%d%d", &x, &y);
                if (map.find(x) == map.end()) {map[x] = {};}
                if (map.find(y) == map.end()) {map[y] = {};}
                map[x].insert(y); map[y].insert(x);
        }

        for (int i=1;i<=n;i++) {
                if (visited[i]) {continue;}
                dfs(i);
        }

        std::vector<std::vector<long long int>> dp(v.size() + 1, std::vector<long long int>(k, 0));
        for (int i=0;i<k;i++) {
                dp[0][i] = 0;
        }
        for (int i=1;i<=(int)v.size();i++) {
                for (int j=0;j<k;j++) {
                        dp[i][j] = dp[i-1][j];
                        if (j >= w[i-1]) {
                                dp[i][j] = std::max(dp[i][j], dp[i-1][j-w[i-1]] + v[i-1]);
                        }
                }
        }
        printf("%lld", dp[v.size()][k-1]);
        return 0;
}