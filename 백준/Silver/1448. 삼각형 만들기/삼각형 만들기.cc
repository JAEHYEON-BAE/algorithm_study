#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n; std::cin >> n;
        std::vector<int> v(n);
        for (int i=0;i<n;i++) {
                std::cin >> v[i];
        }
        std::sort(v.begin(), v.end(), std::greater<int>());

        for (int i=0;i<n-2;i++) {
                if (v[i] < v[i+1]+v[i+2]) {
                        std::cout << v[i]+v[i+1]+v[i+2];
                        return 0;}
                else continue;
        }
        std::cout << -1;
        return 0;
}