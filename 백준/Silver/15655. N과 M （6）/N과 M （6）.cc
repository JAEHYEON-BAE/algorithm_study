#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<int> v(n);
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        std::vector<bool> p(n, false);
        std::fill(p.begin(), p.end()-n+m, true);
        do {
                for (int i=0;i<n;++i) {
                        if (p[i]) std::cout << v[i] << ' ';
                }
                std::cout << '\n';
        } while (std::prev_permutation(p.begin(), p.end()));
        return 0;
}