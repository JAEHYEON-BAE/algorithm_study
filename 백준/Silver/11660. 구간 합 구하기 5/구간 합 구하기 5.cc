#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<std::vector<int>> sum(n, std::vector<int>(n+1, 0));
        for (int i=0;i<n;i++) {
                for (int j=1;j<=n;j++) {
                        int x;  std::cin >> x;
                        sum[i][j] = x + sum[i][j-1];
                }
        }
        while (m--) {
                int x1, y1, x2, y2;
                std::cin >> x1 >> y1 >> x2 >> y2;
                int result = 0;
                for (int i=x1-1;i<x2;i++) {
                        result += sum[i][y2] - sum[i][y1-1];
                }
                std::cout << result << "\n";
        }
        return 0;
}