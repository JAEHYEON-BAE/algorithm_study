#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
struct hash_f
{
        std::size_t operator()(const std::pair<int, int>& a) const {
                return a.first*53+a.second;
        }
};
int find(int x, std::vector<int>& root) 
{
        if (root[x] == x)       return x;
        return root[x] = find(root[x], root);
}
void uni(int x, int y, std::vector<int>& root)
{
        x = find(x, root);
        y = find(y, root);
        root[y] = x;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int t;  std::cin >> t;
        while (t--) {
                int m, n, k;    std::cin >> m >> n >> k;
                std::unordered_map<std::pair<int, int>, int, hash_f> map;
                std::vector<int> root(k);
                for (int i=0;i<k;i++) {
                        root[i] = i;
                        int x, y;       std::cin >> x >> y;
                        map[std::make_pair(x, y)] = i;
                        std::vector<std::pair<int, int>> neighbor;
                        if (x>0) neighbor.push_back({x-1, y});
                        if (y>0) neighbor.push_back({x, y-1});
                        if (x<n-1) neighbor.push_back({x+1, y});
                        if (y<n-1) neighbor.push_back({x, y+1});

                        for (const std::pair<int, int>& pii: neighbor) {
                                if (map.find(pii) != map.end()) {
                                        uni(i, map[pii], root);
                                }
                        }

                }
                std::set<int> tmp;
                for (int i=0;i<k;i++) {
                        tmp.insert(find(i, root));
                }
                std::cout << tmp.size() << "\n";
        }
        return 0;
}