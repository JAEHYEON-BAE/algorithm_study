#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> L;
        for (int i=0;i<n;++i) {
                int x;
                std::cin >> x;
                if (i==0 || x>L[L.size()-1]) L.push_back(x);
                else {
                        *(std::lower_bound(L.begin(), L.end(), x)) = x;
                }
        }
        std::cout << n - L.size();
        return 0;
}