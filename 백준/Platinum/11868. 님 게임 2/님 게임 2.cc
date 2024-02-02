#include <iostream>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        int grundy = 0;
        while (n--) {
                int p;  std::cin >> p;
                grundy ^= p;
        }
        if (grundy) std::cout << "koosaga";
        else std::cout << "cubelover";
        return 0;
}