#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> v(n);
        std::vector<int> sum;
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
                for (int j=0;j<=i;++j) {
                        sum.push_back(v[i]+v[j]);
                }
        }
        std::sort(v.begin(), v.end());
        std::sort(sum.begin(), sum.end());
        for (int i=n-1;i>=0;--i) {
                for (int j=i-1;j>=0;--j) {
                        if (std::binary_search(sum.begin(), sum.end(), v[i]-v[j])) {
                                std::cout << v[i];
                                return 0;
                        }
                }
        }
        return 0;
}