#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#define INF 1987654321
int prim(const std::vector<std::unordered_map<int, int>>& map, const int& m)
{
        std::vector<int> distance(m, INF);
        std::vector<bool> visited(m, false);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, 0});
        distance[0] = 0;

        int result = 0;
        while (!pq.empty()) {
                auto [curr_dist, curr_node] = pq.top();
                pq.pop();
                if (visited[curr_node]) continue;
                visited[curr_node]=true;
                result += curr_dist;
                for (const std::pair<int, int>& pii: map.at(curr_node)) {
                        auto [next_node, next_dist] = pii;
                        if (visited[next_node]) continue;
                        if (next_dist < distance[next_node]) {
                                distance[next_node] = next_dist;
                                pq.push({next_dist, next_node});
                        }
                }
        }
        return result;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        while (true) {
                int m, n;
                std::cin >> m >> n;
                if (m==0&&n==0) break;
                std::vector<std::unordered_map<int, int>> map(m);
                int total = 0;
                while (n--) {
                        int x, y, z;
                        std::cin >> x >> y >> z;
                        map[x][y] = z;
                        map[y][x] = z;
                        total += z;
                }
                std::cout << total - prim(map, m) << '\n';
        }
        return 0;
}