#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, c;       std::cin >> n >> c;
        std::vector<int> v(n);
        for (int i=0;i<n;i++) {
                std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        int start = 1;
        int end = v[n-1] - v[0];
        if (c==2) {
                std::cout << end;
                return 0;
        }
        int result=0;
        while (start <= end) {
                int cnt = 1;
                int mid = (start+end+1)/2;
                int curr = v[0];
                for (int i=0;i<n;i++) {
                        if (v[i]-curr >= mid) {
                                ++cnt;
                                curr = v[i];
                        }
                }
                if (cnt>=c) {
                        result = std::max(result, mid);
                        start = mid+1;
                }
                else end = mid-1;
        }
        std::cout << result;
        return 0;
}