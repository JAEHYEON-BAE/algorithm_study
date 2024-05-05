#include <iostream>
#include <algorithm>
#include <vector>
namespace jaehyeon 
{
        int max(const std::vector<int>& v)
        {
                int tmp = 0;
                for (const int& x: v) {
                        tmp = std::max(tmp, x);
                }
                return tmp;
        }
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<int> v(n, 0);
        std::vector<int> result(n, 0);
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
                std::pair<long int, long int> tmp = {0, 1};
                for (int j=i-1;j>=0;--j) {
                        if (j==i-1) {
                                ++result[i];
                                ++result[j];
                                tmp.first = v[i]-v[j];
                                tmp.second = 1;
                        }
                        else if (((v[i]-v[j])*(tmp.second)) < (i-j)*(tmp.first)) {
                                ++result[i];
                                ++result[j];
                                tmp.first = v[i]-v[j];
                                tmp.second = i-j;
                        }
                }
        }
        std::cout << jaehyeon::max(result);
        return 0;
}