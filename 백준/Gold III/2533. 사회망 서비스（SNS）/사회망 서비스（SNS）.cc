#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
void algorithm(const int x, const std::vector<std::set<int>>& map, std::vector<std::vector<int>>& dp, std::vector<bool>& visited)
{
        visited[x] = true;
        dp[x][0] = 1;
        for (int child: map[x]) {
                if (visited[child]) continue;
                algorithm(child, map, dp, visited);
                dp[x][0] += std::min(dp[child][0], dp[child][1]);
                dp[x][1] += dp[child][0];
        }
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<std::set<int>> map(n+1);
        for (int i=0;i<n;++i) {
                int a, b;
                std::cin >> a >> b;
                map[a].insert(b);
                map[b].insert(a);
        }
        std::vector<bool> visited(n+1, false);
        // early adaptor = 0; not = 1;
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(2));
        algorithm(1, map, dp, visited);
        std::cout << std::min(dp[1][0], dp[1][1]);
        return 0;
}