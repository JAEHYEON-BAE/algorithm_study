#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<long long int> v(n);
        for (int i=0;i<n;i++) {
                std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());

        int l=0, r=n-1;
        long long int sum = v[l]+v[r];
        int result_l=l, result_r=r;
        while (l<r) {
                long long int tmp = v[l]+v[r];
                if (std::abs(tmp) < std::abs(sum))      {
                        sum = tmp;
                        result_l=l;
                        result_r=r;
                }
                if (tmp == 0) break;
                if (tmp < 0) ++l;
                if (tmp > 0) --r;
        }

        std::cout << v[result_l] << " " << v[result_r];
        return 0;
}