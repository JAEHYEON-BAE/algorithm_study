#include <iostream>
#include <queue>
#include <algorithm>
struct Compare {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
                if (a.first == b.first) return a.second > b.second;
                return a.first < b.first;
        }
};
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int t;  std::cin >> t;
        while (t--) {
                int n, m;       std::cin >> n >> m;
                std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;
                for (int i=0;i<m;i++) {
                        int a, b;       std::cin >> a >> b;
                        pq.push({a, b});
                }
                int l=pq.top().second;
                int r=l;
                int cnt=1;
                pq.pop();
                while (!pq.empty()) {
                        std::pair<int, int> pii = pq.top();
                        pq.pop();
                        if (pii.second > r) {++r; ++cnt;}
                        else if (pii.first < l) {--l; ++cnt;}
                }
                std::cout << cnt << "\n";
        }
        return 0;
}