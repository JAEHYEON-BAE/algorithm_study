#include <iostream>
#include <vector>
#include <queue>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<std::vector<int>> map(n, std::vector<int>(m));
        std::pair<int, int> start;
        for (int i=0;i<n;++i) {
                for (int j=0;j<m;++j) {
                        std::cin >> map[i][j];
                        if (map[i][j]==2) {
                                start.first = i;
                                start.second = j;
                        }
                }
        }
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<int>> visited(n, std::vector<int>(m, false));
        std::vector<std::vector<int>> distances(n, std::vector<int>(m, -1));
        distances[start.first][start.second] = 0;
        q.push(start);
        while (!q.empty()) {
                std::pair<int, int> curr = q.front();
                q.pop();
                visited[curr.first][curr.second] = true;
                std::vector<std::pair<int, int>> neighbors;
                if (curr.first>0) neighbors.push_back({curr.first-1, curr.second});
                if (curr.second>0) neighbors.push_back({curr.first, curr.second-1});
                if (curr.first<n-1) neighbors.push_back({curr.first+1, curr.second});
                if (curr.second<m-1) neighbors.push_back({curr.first, curr.second+1});
                for (const auto& x: neighbors) {
                        if (!visited[x.first][x.second] && map[x.first][x.second]!=0) {
                                q.push(x);
                                visited[x.first][x.second] = true;
                                distances[x.first][x.second] = 1+distances[curr.first][curr.second];
                        }
                }
        }
        for (int i=0;i<n;++i) {
                for (int j=0;j<m;++j) {
                        if (distances[i][j]==-1 && map[i][j]==0)
                                std::cout << "0 ";
                        else std::cout << distances[i][j] << " ";
                }
                std::cout << "\n";
        }
        return 0;
}