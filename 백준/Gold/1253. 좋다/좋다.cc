#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        size_t n;       std::cin >> n;
        std::vector<int> v(n);
        for (size_t i=0;i<n;++i) {
                std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());

        int count = 0;
        for (size_t i=0;i<n;++i) {
                int x = v[i];
                size_t l = 0;
                size_t r = n-1;
                if (l==i) ++l;
                if (r==i) --r;
                while (l<r) {
                        if (v[l]+v[r]==x) {
                                ++count;
                                break;
                        }
                        else if (v[l]+v[r]<x) ++l;
                        else if (v[l]+v[r]>x) --r;

                        if (l==i) ++l;
                        if (r==i) --r;
                }
        }
        std::cout << count;
        return 0;
}