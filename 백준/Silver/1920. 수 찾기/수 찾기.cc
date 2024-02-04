#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> v(n);
        for (int i=0;i<n;i++) {
                std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        int m;  std::cin >> m;
        while (m--) {
                int x;  std::cin >> x;
                std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), x);
                if (it!=v.end() && *it==x)      std::cout << "1\n";
                else std::cout << "0\n";
        }
        return 0;
}