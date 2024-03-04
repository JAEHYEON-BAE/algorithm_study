#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int t;  std::cin >> t;
        while (t--) {
                int n;  std::cin >> n;
                std::vector<int> parent(n+1, 0);
                for (int i=0;i<n-1;++i) {
                        int a, b;
                        std::cin >> a >> b;
                        parent[b] = a;
                }
                int x, y;
                std::cin >> x >> y;

                std::vector<bool> x_parents(n+1, false);
                while (x!=0) {
                        x_parents[x]=true;
                        x = parent[x];
                }
                while (x_parents[y]==false) {
                        y = parent[y];
                }
                std::cout << y << '\n';
        }
        return 0;
}