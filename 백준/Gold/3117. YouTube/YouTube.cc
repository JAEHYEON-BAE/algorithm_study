#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n, k, m;    std::cin >> n >> k >> m;
        std::vector<int> start(n);
        std::vector<std::vector<int>> map(31, std::vector<int>(k+1, 0));
        for (int i=0;i<n;i++) {
                std::cin >> start[i];
        }
        for (int i=1;i<=k;i++) {
                std::cin >> map[0][i];
        }
        for (int i=1;i<31;i++) {
                for (int j=1;j<=k;j++) {
                        map[i][j] = map[i-1][map[i-1][j]];
                }
                if ((1 << i) >= m-1) {
                        for (int student=0;student<n;student++) {
                                int curr = start[student];
                                for (int j=i;j>=0;j--) {
                                        if ((m-1) & (1 << j)) {
                                                curr = map[j][curr];
                                        }
                                }
                                std::cout << curr << " ";
                        }
                        return 0;
                }
        }
        return 0;
}