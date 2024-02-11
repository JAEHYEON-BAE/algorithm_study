#include <iostream>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, k;
        std::cin >> n >> k;
        if (n<=k) {
                std::cout << "A and B win";
        }
        else if (n>=k+3 && n<=2*k+1) {
                std::cout << "A and B win";
        }
        else {
                std::cout << "C win";
        }
        return 0;
}