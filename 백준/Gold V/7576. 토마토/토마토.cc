#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int m, n;
        std::cin >> m >> n;
        int cnt = m*n;
        std::vector<std::vector<int>> tmt(n, std::vector<int>(m));
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        std::vector<std::vector<int>> distances(n, std::vector<int>(m));
        for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
                std::cin >> tmt[i][j];
                if (tmt[i][j]==1) {
                        q.push({i, j});
                        visited[i][j]=true;
                        distances[i][j]=0;
                }
                else if (tmt[i][j]==-1) {
                        --cnt;
                }
        }
        int result=0;
        while (!q.empty()) {
                const auto [a, b] = q.front();
                q.pop();
                visited[a][b]=true;
                --cnt;
                std::vector<std::pair<int, int>> neighbors;
                if (a>0 && tmt[a-1][b]!=-1)             neighbors.push_back({a-1, b});
                if (b>0 && tmt[a][b-1]!=-1)             neighbors.push_back({a, b-1});
                if (a<n-1 && tmt[a+1][b]!=-1)   neighbors.push_back({a+1, b});
                if (b<m-1 && tmt[a][b+1]!=-1)   neighbors.push_back({a, b+1});
                for (const std::pair<int, int>& pii: neighbors) {
                        const auto [c, d] = pii;
                        if (!visited[c][d]) {
                                visited[c][d]=true;
                                q.push(pii);
                                distances[c][d] = 1+distances[a][b];
                                result = std::max(result, distances[c][d]);
                        }
                }
        }
        if (cnt>0) std::cout << "-1";
        else std::cout << result;
        return 0;
}