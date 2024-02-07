#include <iostream>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int a, b;
        std::cin >> a >> b;
        int cnt = 1;
        while (a<b) {
                if (b%2==1 && b%10!=1) {
                        std::cout << "-1";
                        return 0;
                }
                else if (b%10==1) {
                        b /= 10;
                        ++cnt;
                        continue;
                }
                else {
                        b /= 2;
                        ++cnt;
                        continue;
                }
        }
        if (a==b) {std::cout << cnt;}
        else std::cout << "-1";
        return 0;
}