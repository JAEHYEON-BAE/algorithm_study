#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1'000'000'007


void print_vector(const std::vector<std::vector<int>>& v, int n)
{
        for (int i=1;i<=n;++i) {
                std::cout << '\t';
                for (int j=1;j<=n;++j) {
                        if (v[i][j]!=MAX)       std::cout << v[i][j] << "\t\t";
                        else std::cout << MAX << '\t';
                }
                std::cout << std::endl;
        }
}

std::vector<std::vector<int>> floyd(const std::vector<std::vector<int>>& graph, int n)
{
        std::vector<std::vector<int>> dp = graph;
        for (int i=1;i<=n;++i) {
                dp[i][i] = 0;
        }
        for (int k=1;k<=n;++k) {
                std::vector<std::vector<int>> pre_dp = dp;
                for (int u=1;u<=n;++u) {
                        for (int v=1;v<=n;++v) {
                                dp[u][v] = std::min(pre_dp[u][v], pre_dp[u][k]+pre_dp[k][v]);
                        }
                }
        }
        return dp;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n, m;       std::cin >> n >> m;
        std::vector<std::vector<int>> graph(n+1, std::vector<int>(n+1, MAX));
        std::vector<std::vector<int>> longest_graph(n+1, std::vector<int>(n+1, MAX));
        while (m--) {
                int s, e, l;
                std::cin >> s >> e >> l;
                if (longest_graph[s][e]==MAX) {
                        longest_graph[s][e] = l*2;
                } else {
                        longest_graph[s][e] = std::max(longest_graph[s][e], l*2);
                }
                longest_graph[e][s] = longest_graph[s][e];

                graph[s][e] = std::min(graph[s][e], l*2);
                graph[e][s] = graph[s][e];
        }

        for (int i=1;i<=n;++i) {
                graph[i][i] = 0;
        }
        std::vector<std::vector<int>> dp = floyd(graph, n);
 
        int result = MAX;
        for (int k=1;k<=n;++k) {
                int remain_length = -1;
                auto iter = std::max_element(dp[k].begin()+1, dp[k].end());
                int time = *iter;
                for (int u=1;u<=n;++u) {
                        for (int v=1;v<=n;++v) {
                                if (longest_graph[u][v]==MAX) continue;
                                remain_length = std::max(remain_length, longest_graph[u][v]+dp[k][u]+dp[k][v]-time*2); 
                        }
                }
                result = std::min(result, time + remain_length/2);
        }

        std::cout << result/2;
        if (result&1) std::cout << ".5";
        else    std::cout << ".0";
        return 0;
}