#include <iostream>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, k;       std::cin >> n >> k;
        int l=1, r=k;
        int result=0;
        while (l <= r) {
                int mid = (l+r)/2;
                int cnt = 0;
                for (int i=1;i<=std::min(n, k);i++) {
                        cnt += std::min(mid/i, n);
                }
                if (cnt >= k) {
                        result = mid;
                        r=mid-1;
                }
                else l=mid+1;
        }
        std::cout << result;
        return 0;
}