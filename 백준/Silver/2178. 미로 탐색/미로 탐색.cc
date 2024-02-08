#include <iostream>
#include <string>
#include <vector>
#include <queue>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;
        std::cin >> n >> m;
        std::vector<std::string> map(n);
        for (int i=0;i<n;i++) {
                std::cin >> map[i];
        }

        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        q.push({0, 0});
        std::vector<std::vector<int>> distance(n, std::vector<int>(m, 1));
        while (!q.empty()) {
                std::pair<int, int> curr = q.front();
                q.pop();
                int a = curr.first, b = curr.second;
                visited[a][b] = true;
                std::vector<std::pair<int, int>> neighbors;
                if (a>0 && map[a-1][b]=='1') neighbors.push_back({a-1, b});
                if (a<n-1 && map[a+1][b]=='1') neighbors.push_back({a+1, b});
                if (b>0 && map[a][b-1]=='1') neighbors.push_back({a, b-1});
                if (b<m-1 && map[a][b+1]=='1') neighbors.push_back({a, b+1});
                for (const std::pair<int, int>& pii: neighbors) {
                        if (visited[pii.first][pii.second] == false) {
                                q.push(pii);
                                visited[pii.first][pii.second] = true;
                                distance[pii.first][pii.second] = 1+distance[a][b];
                        }
                }
        }
        std::cout << distance[n-1][m-1];
        return 0;
}