#include <iostream>
#include <vector>
#include <cmath>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        long long int min, max; std::cin >> min >> max;

        std::vector<bool> v(max-min+1, true);

        for (long long int i=2;i<=(long long int)std::sqrt(max);++i) {
                long long int sq = i*i;
//              std::cout << "Check for " << sq << ":\n";
                if (min%sq==0) {
                        for (size_t j=0;j<v.size();j+=sq) {
                                v[j] = false;
//                              std::cout << "\tNumber " << min+j << ": False\n";
                        }
                } else {
                        for (size_t j=(min/sq +1)*sq-min;j<v.size();j+=sq) {
                                v[j] =false;
//                              std::cout << "\tNumber " << min+j << ": False\n";
                        }
                }
        }
        int result=0;
        for (bool x: v) {
                if (x) ++result;
        }
        std::cout << result;
        return 0;
}