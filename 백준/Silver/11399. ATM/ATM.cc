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
        int result = 0;
        int tmp = 0;
        for (int i=0;i<n;i++) {
                result += tmp + v[i];
                tmp += v[i];
        }
        std::cout << result;
        return 0;
}