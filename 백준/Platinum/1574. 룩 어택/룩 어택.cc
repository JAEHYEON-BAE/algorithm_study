#include <iostream>
#include <vector>
#include <set>

bool bipartite_matching(int r, std::vector<int>& match, std::vector<bool>& done, const std::vector<std::set<int>>& graph)
{
        for (int c: graph[r]) {
                if (!done[c]) {
                        done[c] = true;
                        if (match[c]==-1 || bipartite_matching(match[c], match, done, graph)) {
                                match[c] = r;
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

        int r, c, n;    std::cin >> r >> c >> n;
        std::vector<std::set<int>> graph(r);
        for (int i=0;i<r;++i) for (int j=0;j<c;++j)     graph[i].insert(j);

        for (int i=0;i<n;++i) {
                int a, b;       std::cin >> a >> b;
                graph[a-1].erase(b-1);
        }


        std::vector<int> match(c, -1);
        for (int i=0;i<r;++i) {
                std::vector<bool> done(c, false);
                bipartite_matching(i, match, done, graph);
        }
        int result = 0;
        for (int x: match)      if (x!=-1)      ++result;
        std::cout << result;
        return 0;
}