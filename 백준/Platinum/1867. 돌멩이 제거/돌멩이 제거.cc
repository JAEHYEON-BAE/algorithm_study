#include <iostream>
#include <vector>

// minimum vertex cover == maximum bipartite matching (konig's theorem)

bool bp_m(int node, const std::vector<std::vector<int>>& graph, std::vector<int>& match, std::vector<bool>& done)
{
        for (int neighbor: graph[node]) {
                if (!done[neighbor]) {
                        done[neighbor] = true;
                        if (match[neighbor]==-1 || bp_m(match[neighbor], graph, match, done)) {
                                match[neighbor] = node;
                                return true;
                        }
                }
        }
        return false;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n, k;       std::cin >> n >> k;
        std::vector<std::vector<int>> graph(n+1);
        while (k--) {
                int a, b;       std::cin >> a >> b;
                graph[a].push_back(b);
        }
        int result = n+1;
        std::vector<int> match(n+1, -1);
        for (int i=0;i<=n;++i) {
                std::vector<bool> done(n+1, false);
                bp_m(i, graph, match, done);
        }
        for (int x: match) if (x==-1) --result;
        std::cout << result;
        return 0;
}