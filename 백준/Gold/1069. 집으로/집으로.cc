#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
namespace jaehyeon
{
        long double sqrt(const int& x, double precision)
        {
                int naive_sqrt = static_cast<int>(std::sqrt(x));
                if (naive_sqrt*naive_sqrt==x) {
                        return static_cast<long double>(naive_sqrt);
                }
                double low = 0, high = x, mid;
                while ((high-low)>precision) {
                        mid = (low+high)/2;
                        if (mid*mid > x) {
                                high = mid;
                        } else {
                                low = mid;
                        }
                }
                return (high+low)/2;
        }
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int x, y, d, t;
        std::cin >> x >> y >> d >> t;
        double precision = 1e-10;

        long double distance = jaehyeon::sqrt(x*x+y*y, precision);
        int int_distance = static_cast<int> (distance);
        if (d<=t) {
                std::cout << std::fixed << std::setprecision(11) << distance;
                return 0;
        }

        if (distance < d) {
                std::cout << std::fixed << std::setprecision(11) << std::min(std::min(distance, static_cast<long double>(2*t)), static_cast<long double>(t+d) - distance);
                return 0;
        }

        long double answer = 0.0;
        int q = int_distance / d;
        answer = static_cast<long double>(q*t) + std::min(distance - q*d, static_cast<long double>(t));
        std::cout << std::fixed << std::setprecision(11) << answer;
        return 0;
}