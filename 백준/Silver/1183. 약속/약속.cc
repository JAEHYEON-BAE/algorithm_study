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
                int a, b; std::cin >> a >> b;
                v[i] = a-b;
        }
        if (n%2==1) {std::cout << "1"; return 0;}
        std::sort(v.begin(), v.end());
        std::cout << v[n/2] - v[n/2-1] + 1;
        return 0;
}