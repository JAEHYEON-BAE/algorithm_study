#include <iostream>
inline int distance(int x1, int y1, int a, int b)
{
        return (x1-a)*(x1-a) + (y1-b)*(y1-b);
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);

        int t;  std::cin >> t;
        while (t--) {
                int x1, y1, x2, y2;
                std::cin >> x1 >> y1 >> x2 >> y2;
                int result=0;
                int n;  std::cin >> n;
                for (int i=0;i<n;i++) {
                        int p, q, r;
                        std::cin >> p >> q >> r;
                        if ((distance(x1, y1, p, q) < r*r) ^ (distance(x2, y2, p, q) < r*r)) {
                                ++result;
                        }
                }
                std::cout << result << "\n";
        }
        return 0;
}