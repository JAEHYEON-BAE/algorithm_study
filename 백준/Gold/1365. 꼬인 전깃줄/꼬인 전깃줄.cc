#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> v(n);
        std::vector<int> lis;
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
                if (lis.empty()) lis.push_back(v[i]);
                else {
                        if (*(lis.end()-1) < v[i])      lis.push_back(v[i]);
                        else {
                                *std::lower_bound(lis.begin(), lis.end(), v[i]) = v[i];
                        }
                }
        }
        std::cout << n - lis.size();
        return 0;
}