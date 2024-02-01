#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n, m;       std::cin >> n >> m;
        std::vector<long long int> sum(n+1, 0);
        for (int i=1;i<=n;i++) {
                int x;  std::cin >> x;
                sum[i] = sum[i-1] + x;
        }
        while (m--) {
                int a, b;       std::cin >> a >> b;
                std::cout << sum[b] - sum[a-1] << "\n";
        }
        return 0;
}