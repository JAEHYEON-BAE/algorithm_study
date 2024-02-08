#include <iostream>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int w, h, x, y, p;
        std::cin >> w >> h >> x >> y >> p;
        int cnt=0;
        while (p--) {
                int a, b;       std::cin >> a >> b;
                if (a>=x && a<=x+w && b>=y && b<=y+h) ++cnt;
                else if (((a-x)*(a-x)+(b-y-h/2)*(b-y-h/2) <= (h/2)*(h/2)) || ((a-x-w)*(a-x-w)+(b-y-h/2)*(b-y-h/2) <= (h/2)*(h/2))) 
                        ++cnt;
        }
        std::cout << cnt;
        return 0;
}