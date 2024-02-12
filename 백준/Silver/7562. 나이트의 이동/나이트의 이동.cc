#include <iostream>
#include <vector>
#include <queue>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int t;  std::cin >> t;
        while (t--) {
                int l;  std::cin >> l;
                std::pair<int, int> start, dest;
                std::cin >> start.first >> start.second >> dest.first >> dest.second;
                std::queue<std::pair<int, int>> q;
                std::vector<std::vector<int>> visited(l, std::vector<int>(l, false));
                std::vector<std::vector<int>> distances(l, std::vector<int>(l, 1987654321));
                q.push(start);
                distances[start.first][start.second] = 0;
                while (!q.empty()) {
                        std::pair<int, int> curr = q.front();
                        q.pop();
                        if (curr==dest) break;
                        int r = curr.first;
                        int c = curr.second;
                        visited[r][c] = true;
                        std::vector<std::pair<int, int>> neighbors;

                        if (r>0 && c>1)         neighbors.push_back({r-1, c-2});
                        if (r>1 && c>0)         neighbors.push_back({r-2, c-1});
                        if (r>1 && c<l-1)       neighbors.push_back({r-2, c+1});
                        if (r>0 && c<l-2)       neighbors.push_back({r-1, c+2});
                        if (r<l-1 && c<l-2)     neighbors.push_back({r+1, c+2});
                        if (r<l-2 && c<l-1) neighbors.push_back({r+2, c+1});
                        if (r<l-2 && c>0)       neighbors.push_back({r+2, c-1});
                        if (r<l-1 && c>1)       neighbors.push_back({r+1, c-2});

                        for (const auto& neighbor: neighbors) {
                                if (!visited[neighbor.first][neighbor.second]) {
                                        q.push(neighbor);
                                        visited[neighbor.first][neighbor.second] = true;
                                        distances[neighbor.first][neighbor.second] = 1+distances[curr.first][curr.second];
                                }
                        }
                }
                std::cout << distances[dest.first][dest.second] << "\n";
        }
        return 0;
}