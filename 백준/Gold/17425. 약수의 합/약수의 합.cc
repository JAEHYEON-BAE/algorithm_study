#include <iostream>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        long long int g[1000001] = {};
        for (int i=1;i<=1000000;i++) {
                for (int j=1;i*j<=1000000;j++) {
                        g[i*j] += i;
                }
                g[i] += g[i-1];
        }
        int t;  std::cin >> t;
        while (t--) {
                int x;  std::cin >> x;
                std::cout << g[x] << "\n";
        }
        return 0;
}