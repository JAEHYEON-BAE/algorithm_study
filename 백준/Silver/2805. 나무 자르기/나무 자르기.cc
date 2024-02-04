#include <iostream>
#include <vector>
#include <algorithm>
long long int get(const std::vector<int>& v, int height) 
{
        long long int result=0;
        for (int x: v) {
                if (x<height) continue;
                result += (long long int)(x-height);
        }
        return result;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<int> v(n);
        int max=0;
        for (int i=0;i<n;i++) {
                std::cin >> v[i];
                max = std::max(max, v[i]);
        }
        int l=1, r=max;
        int result=0;
        while (l<r) {
                int mid = (int) (((long long int)l + (long long int)r + 1LL)/2);
                if (get(v, mid) >= m) {
                        result = std::max(result, mid);
                        l = mid;
                }
                else r = mid-1;
        }
        std::cout << result;
        return 0;
}