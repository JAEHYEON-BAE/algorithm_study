#include <iostream>
#include <algorithm>
#include <cstdio>
__int128 GCD(__int128 a, __int128 b)
{
        if (b==0) {return a;}
        if (a==1 || b==1) {return 1;}
        return GCD(b, a%b);
}
__int128 eGCD(__int128 a, __int128 b, __int128& x, __int128& y)
{
        if (b==0) {x=1; y=0; return a;}
        __int128 x1, y1;
        __int128 result = eGCD(b, a%b, x1, y1);
        x = y1; y = x1-(a/b)*y1;
        return result;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        long long int lla, llb, lls;
        std::cin >> lla >> llb >> lls;

        if (lla > llb) std::swap(lla, llb);

        __int128 a = static_cast<__int128>(lla);
        __int128 b = static_cast<__int128>(llb);
        __int128 s = static_cast<__int128>(lls);

        if (s<a && s<b) {std::cout << "NO"; return 0;}
        if (s==a || s==b) {std::cout << "YES"; return 0;}
        if (a==0 && b==0) {std::cout << "NO"; return 0;}
        if (a+b > s) {std::cout << "NO"; return 0;}
        __int128 x0, y0;
        __int128 g = eGCD(a, b, x0, y0);

        if (s%g!=0) {std::cout << "NO"; return 0;}
        a/=g; b/=g;

        if (y0 == 0) {
                if (x0 > 0) {
                        x0 += b;
                        y0 -= a;
                }
                if (x0 < 0) {
                        x0 -= b;
                        y0 += a;
                }
        }
        if (x0 == 0) {
                if (y0 > 0) {
                        x0 -= b;
                        y0 += a;
                }
                if (y0 < 0) {
                        x0 += b;
                        y0 -= a;
                }
        }

        __int128 x = x0*(s/g);
        __int128 y = y0*(s/g);

        while (1) {
                if (y<0) {break;}
                if (x<0) {
                        __int128 k = (0-x)/b;
                        x += b*(k);
                        y -= a*(k);
                        if (x<0) {x+=b; y-=a;}
                        continue;
                }
                if (x>0 && y>0 && GCD(x, y) == 1) {
                        std::cout << "YES";
                        return 0;
                }
                x += b; y -= a;
        }

        x = x0*(s/g);
        y = y0*(s/g);

        while (1) {
                if (x<0) {break;}
                if (y<0) {
                        __int128 k = (0-y)/a;
                        x -= b*(k);
                        y += a*(k);
                        if (y<0) {y+=a; x-=b;}
                        continue;
                }
                if (x>0 && y>0 && GCD(x, y) == 1) {
                        std::cout << "YES";
                        return 0;
                }
                x -= b; y += a;
        }
        std::cout << "NO";
        return 0; 
}