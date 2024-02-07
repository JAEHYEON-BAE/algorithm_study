#include <iostream>
#include <vector>
#include <set>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> v(n);
        std::set<int> s;
        for (int i=0;i<n;i++) {
                std::cin >> v[i];
                s.insert(v[i]);
        }
        std::vector<int> tmp;
        for (int x: s) {
                tmp.push_back(x);
        }
        for (int x: v) {
                std::cout << (int)(std::lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin()) << " ";
        }
        return 0;
}