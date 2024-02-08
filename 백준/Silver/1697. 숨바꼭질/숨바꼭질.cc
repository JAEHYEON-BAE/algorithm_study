#include <iostream>
#include <queue>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, k;
        std::cin >> n >> k;
        std::queue<int> q;
        std::vector<int> distance(200000, false);
        std::vector<bool> visited(200000, false);
        q.push(n);
        while (!q.empty()) {
                int curr = q.front();
                q.pop();
                if (curr==k) break;
                visited[curr] = true;
                if (curr-1>=0 && visited[curr-1]==false) {
                        q.push(curr-1);
                        visited[curr-1] = true;
                        distance[curr-1] = 1 + distance[curr];
                }
                if (curr+1<200000 && visited[curr+1]==false) {
                        q.push(curr+1);
                        visited[curr+1] = true;
                        distance[curr+1] = 1 + distance[curr];
                }
                if (curr*2<200000 && visited[curr*2]==false) {
                        q.push(curr*2);
                        visited[curr*2] = true;
                        distance[curr*2] = 1 + distance[curr];
                }
        }
        std::cout << distance[k];
        return 0;
}