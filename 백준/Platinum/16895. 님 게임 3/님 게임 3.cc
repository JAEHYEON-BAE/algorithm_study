#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> v(n);
        int x = 0;
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
                x ^= v[i];
        }
        if (x==0) {
                std::cout << "0";
                return 0;
        }
        int cnt=0;
        for (int p: v) {
                if ((p^x) < p) ++cnt;
        }
        std::cout << cnt;
        return 0;
}