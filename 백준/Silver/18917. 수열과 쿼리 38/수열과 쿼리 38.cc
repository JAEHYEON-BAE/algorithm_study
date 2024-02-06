#include <iostream>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int m;  std::cin >> m;
        long long int q3=0;
        int q4=0;
        while (m--) {
                int q;  std::cin >> q;
                if (q==1) {
                        int x;  std::cin >> x;
                        q3 += x;
                        q4 ^= x;
                }
                if (q==2) {
                        int x;  std::cin >> x;
                        q3 -= x;
                        q4 ^= x;
                }
                if (q==3) {
                        std::cout << q3 << "\n";
                }
                if (q==4) {
                        std::cout << q4 << "\n";
                }
        }
        return 0;
}