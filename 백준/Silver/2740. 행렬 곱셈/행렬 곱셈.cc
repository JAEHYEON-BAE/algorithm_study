#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m, k;    std::cin >> n >> m;
        std::vector<std::vector<int>> nm(n, std::vector<int>(m));
        for (int i=0;i<n;i++) {
                for (int j=0;j<m;j++) {
                        std::cin >> nm[i][j];
                }
        }
        std::cin >> m >> k;
        std::vector<std::vector<int>> mk(m, std::vector<int>(k));
        for (int i=0;i<m;i++) {
                for (int j=0;j<k;j++) {
                        std::cin >> mk[i][j];
                }
        }
        for (int i=0;i<n;i++) {
                for (int j=0;j<k;j++) {
                        int x=0;
                        for (int l=0;l<m;l++) {
                                x += nm[i][l] * mk[l][j];
                        }
                        std::cout << x << " ";
                }
                std::cout << "\n";
        }
        return 0;
}