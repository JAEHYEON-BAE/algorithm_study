#include <iostream>
#include <tuple>
#include <algorithm>
std::tuple<long long int, long long int, long long int> e_gcd(const long long int a, const long long int b) {
        if (b==0) return {a, 1, 0};
        auto [gcd, x1, y1] = e_gcd(b, a%b);
        return {gcd, y1, x1-(a/b)*y1};
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        while (true) {
                int a, b, c, k;
                std::cin >> a >> b >> c >> k;
                if (a==0&&b==0&&c==0&&k==0) break;
                if (a==b) {
                        std::cout << "0\n";
                        continue;
                }
                auto [gcd, x, y] = e_gcd((long long int)c, 1LL<<k);
                if ((b-a)%gcd!=0) {
                        std::cout << "FOREVER\n";
                        continue;
                }
                x *= (b-a)/gcd;
                y *= (b-a)/gcd;
                if (y==0 && x>=0) {
                        std::cout << x << "\n";
                        continue;
                }

                long long int dx = (1LL<<k)/gcd;
                long long int dy = c/gcd;
                if (x>0 && y<=0) {
                        long long int r = std::min(x/dx, (0-y)/dy);
                        x -= r*dx;
                        y += r+dy;
                }

                long long int r = std::max((0-x)/dx, y/dy);
                x += r*dx;
                y -= r*dy;
                if (x<=0 || y>0) {
                        x += dx;
                        y -= dy;
                }

                std::cout << x << "\n";
        }
        return 0;
}