#include <iostream>
#include <tuple>
std::tuple<long long int, __int128, __int128> e_gcd(const long long int a, const long long int b) {
        if (b==0) return {a, 1, 0};
        auto [gcd, x, y] = e_gcd(b, a%b);
        return {gcd, y, x-(a/b)*y};
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        while (true) {
                long long int foom, foob, twob;
                std::cin >> foom >> foob >> twob;
                if (foom==0&&foob==0&&twob==0) break;
                auto [gcd, x, y] = e_gcd(foom, foob);
                if (twob%gcd!=0) {
                        std::cout << "Unquibable!\n";
                        continue;
                }
                x *= twob/gcd;
                y *= twob/gcd;
                if (x==0) {
                        std::cout << "0 fooms and " << (long long int)y << " foobs for a twob!\n";
                        continue;
                }
                __int128 dx = foob/gcd;
                __int128 dy = foom/gcd;

                if (x>=0) {
                        __int128 r = x/dx;
                        x -= r*dx;
                        y += r*dy;
                }
                else if (x<0) {
                        __int128 r = (0-x)/dx;
                        x += r*dx;
                        y -= r*dy;
                }

                if (x==0) {
                        if (y==1) 
                                std::cout << "0 fooms and 1 foob for a twob!\n";
                        else 
                                std::cout << "0 fooms and " << (long long int)y << " foobs for a twob!\n";
                        continue;
                }
                if (x<0) {
                        x += dx;
                        y -= dy;
                }
              
                if (x>=0 && y>=0) {
                        if (x==1 && y==1) 
                                std::cout << "1 foom and 1 foob for a twob!\n";
                        if (x==1 && y!=1) 
                                std::cout << "1 foom and " << (long long int)y << " foobs for a twob!\n";
                        if (x!=1 && y==1) 
                                std::cout << (long long int)x << " fooms and 1 foob for a twob!\n";
                        if (x!=1 && y!=1)
                                std::cout << (long long int)x << " fooms and " << (long long int)y << " foobs for a twob!\n";
                        continue;
                }
                else {
                        std::cout << "Unquibable!\n";
                        continue;
                }
        }
        return 0;
}