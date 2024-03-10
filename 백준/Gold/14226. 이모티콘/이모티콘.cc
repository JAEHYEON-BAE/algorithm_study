#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1987654321
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<std::vector<bool>> visited(2*n+1, std::vector<bool>(2*n+1, false));
        visited[1][0] = true;
        std::vector<std::vector<int>> dist(2*n+1, std::vector<int>(2*n+1, INF));
        dist[1][0] = 0;
        std::queue<std::pair<int, int>> q;
        q.push({1, 0});
        while (!q.empty()) {
                auto [curr, clip] = q.front();
                q.pop();
                visited[curr][clip] = true;
                if (curr-1>0 && !visited[curr-1][clip]) {
                        dist[curr-1][clip] = dist[curr][clip]+1;
                        visited[curr-1][clip] = true;
                        q.push({curr-1, clip});
                }
                if (curr+clip<2*n+1 && !visited[curr+clip][clip]) {
                        dist[curr+clip][clip] = dist[curr][clip]+1;
                        visited[curr+clip][clip] = true;
                        q.push({curr+clip, clip});
                }
                if (!visited[curr][curr]) {
                        dist[curr][curr] = dist[curr][clip]+1;
                        visited[curr][curr] = true;
                        q.push({curr, curr});
                }
        }
        std::cout << *std::min_element(dist[n].begin(), dist[n].end());
        return 0;
}