#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
struct Compare
{
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
                if (a.first == b.first) return a.second > b.second;
                return a.first < b.first;
        }
};

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, k;       std::cin >> n >> k;
        std::vector<std::pair<int, int>> gem;
        std::vector<int> knap(k);
        for (int i=0;i<n;i++) {
                int m, v;       std::cin >> m >> v;
                gem.push_back({m, v});
        }
        for (int i=0;i<k;i++) {
                std::cin >> knap[i];
        }
        std::sort(gem.begin(), gem.end(), Compare());
        std::sort(knap.begin(), knap.end());

        long long int result=0;
        int index = 0;
        std::priority_queue<int> pq;
        for (int i=0;i<k;i++) {
                while (index<n && knap[i]>=gem[index].first) {
                        pq.push(gem[index].second);
                        ++index;
                }
                if (!pq.empty()) {
                        result += pq.top();
                        pq.pop();
                }
        }

        std::cout << result ;
        return 0;
}