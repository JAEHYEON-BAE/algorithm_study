#include <iostream>
#include <unordered_map>
#include <queue>
#define INF 1987654321
int prim(const std::unordered_map<int, std::unordered_map<int, int>>& map, const int& v) 
{
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, 1});
        std::vector<int> distance(v+1, INF);
        std::vector<bool> visited(v+1, false);
        distance[1] = 0;
        int result=0;
        while (!pq.empty()) {
                std::pair<int, int> pii = pq.top();
                pq.pop();
                int curr = pii.second;
                int cost = pii.first;
                if (visited[curr]) {continue;}
                visited[curr] = true;
                result += cost;
                for (const auto& neighbor: map.at(curr)) {
                        int next = neighbor.first;
                        int dist = neighbor.second;
                        if (dist < distance[next]) {
                                distance[next] = dist;
                                pq.push({dist, next});
                        }
                }
        }
        return result;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int v, e;       std::cin >> v >> e;
        std::unordered_map<int, std::unordered_map<int, int>> map;
        for (int i=0;i<e;i++) {
                int a, b, c;
                std::cin >> a >> b >> c;
                if (map.find(a)==map.end()) map[a] = {};
                if (map.find(b)==map.end()) map[b] = {};
                map[a][b] = c;  map[b][a] = c;
        }
        std::cout << prim(map, v);
        return 0;
}