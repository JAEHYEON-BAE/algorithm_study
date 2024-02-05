#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, s;       std::cin >> n >> s;
        std::vector<int> sum(n+1);
        sum[0]=0;
        for (int i=1;i<=n;i++) {
                int x;  std::cin >> x;
                sum[i] = sum[i-1]+x;
        }
        if (sum[n] < s) {std::cout << "0"; return 0;}
        int l=1, r=1;
        int result = n+1;
        while (r<=n) {
                int tmp = sum[r] - sum[l-1];
                if (tmp >= s) {
                        result = std::min(result, r-l+1);
                        ++l;
                }
                else {
                        ++r;
                }
        }
        std::cout << result;
        return 0;
}