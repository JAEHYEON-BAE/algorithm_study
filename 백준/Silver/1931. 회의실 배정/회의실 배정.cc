#include <iostream>
#include <queue>
struct Compare
{
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
                if (a.second == b.second)       return a.first > b.first;
                return a.second > b.second;
        }
};

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;
        int cnt = 0;
        int end = 0;
        while (n--) {
                int s, e;
                std::cin >> s >> e;
                pq.push({s, e});
        }
        while (!pq.empty()) {
                std::pair<int, int> c = pq.top();
                if (c.first >= end) {
                        ++cnt;
                        end = c.second;
                }
                pq.pop();
        }
        std::cout << cnt;
        return 0;
}