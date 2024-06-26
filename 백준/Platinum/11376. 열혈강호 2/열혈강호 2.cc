#include <iostream>
#include <vector>
bool bipartite_matching(int n, std::vector<int>& match, std::vector<bool>& done, const std::vector<std::vector<int>>& graph)
{
        for (int m: graph[n]) {
                if (!done[m]) {
                        done[m] = true;
                        if (match[m]==-1 || bipartite_matching(match[m], match, done, graph)) {
                                match[m] = n;
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

        int n, m;       std::cin >> n >> m;
        std::vector<std::vector<int>> graph(n*2);
        for (int i=0;i<n;++i) {
                int a;  std::cin >> a;
                for (int j=0;j<a;++j) {
                        int work;       std::cin >> work;
                        graph[i].push_back(work-1);
                        graph[i+n].push_back(work-1);
                }
        }
        std::vector<int> match(m, -1);
        for (int i=0;i<2*n;++i) {
                std::vector<bool> done(m, false);
                bipartite_matching(i, match, done, graph);
        }
        int result = 0;
        for (int x: match)      if (x!=-1)      ++result;
        std::cout << result;
        return 0;
}