#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// vector[a][b]
int solve(int a, int b) 
{
        if (a<=0 && b>=a && b<=-a) 
                return 4*a*a+1-(b-a);
        if (b<=0 && a>=b && a<=-b)
                return 4*b*b+1+(a-b);
        if (b>=0 && a>=-b && a<b)
                return 4*b*b-2*b+1-(a+b);
        if (a>=0 && b>=-a && b<=a+1)
                return 4*a*a+2*a+1+(b+a);
        std::cout << "Something went wrong!!" << std::endl;
        return -99;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int r1, c1, r2, c2;
        std::cin >> r1 >> c1 >> r2 >> c2;

        int len = 0;
        len = std::max(len, (int)std::to_string(solve(r1, c1)).size());
        len = std::max(len, (int)std::to_string(solve(r2, c1)).size());
        len = std::max(len, (int)std::to_string(solve(r1, c2)).size());
        len = std::max(len, (int)std::to_string(solve(r2, c2)).size());

        for (int i=r1;i<=r2;i++) {
                for (int j=c1;j<=c2;j++) {
                        std::cout << std::right << std::setw(len) << solve(i, j) << " ";
                }
                std::cout << "\n";
        }
        return 0;
}