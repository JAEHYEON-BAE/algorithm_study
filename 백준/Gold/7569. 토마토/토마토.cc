#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int m, n, h;
        std::cin >> m >> n >> h;
        int cnt=h*n*m;
        std::queue<std::tuple<int, int, int>> q;
        std::vector<std::vector<std::vector<int>>> tmt(h, std::vector<std::vector<int>>(n, std::vector<int>(m)));
        std::vector<std::vector<std::vector<bool>>> visited(h, std::vector<std::vector<bool>>(n, std::vector<bool>(m, false)));
        std::vector<std::vector<std::vector<int>>> distances(h, std::vector<std::vector<int>>(n, std::vector<int>(m, 0)));
        for (int i=0;i<h;++i) for (int j=0;j<n;++j)     for (int k=0;k<m;++k) {
                std::cin >> tmt[i][j][k];
                if (tmt[i][j][k]==1) {
                        q.push({i, j, k});
                        visited[i][j][k] = true;
                        distances[i][j][k] = 0;
                }
                else if (tmt[i][j][k]==-1) --cnt;
        }
        int result = 0;
        while (!q.empty()) {
                std::tuple<int, int, int> curr = q.front();
                auto [a, b, c] = curr;
                q.pop();
                --cnt;
                visited[a][b][c] = true;
                std::vector<std::tuple<int, int, int>> neighbors;
                if (a>0 && tmt[a-1][b][c]!=-1)  neighbors.push_back({a-1, b, c});
                if (b>0 && tmt[a][b-1][c]!=-1)  neighbors.push_back({a, b-1, c});
                if (c>0 && tmt[a][b][c-1]!=-1)  neighbors.push_back({a, b, c-1});
                if (a<h-1 && tmt[a+1][b][c]!=-1)neighbors.push_back({a+1, b, c});
                if (b<n-1 && tmt[a][b+1][c]!=-1)neighbors.push_back({a, b+1, c});
                if (c<m-1 && tmt[a][b][c+1]!=-1)neighbors.push_back({a, b, c+1});
                for (const auto& tp: neighbors) {
                        auto [i, j, k] = tp;
                        if (!visited[i][j][k]) {
                                visited[i][j][k]=true;
                                q.push(tp);
                                distances[i][j][k]=1+distances[a][b][c];
                                result = std::max(result, distances[i][j][k]);
                        }
                }
        }
        if (cnt==0)     std::cout << result;
        else std::cout << -1;
        return 0;
}