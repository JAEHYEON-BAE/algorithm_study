#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
long long int area(const int& n, const std::vector<std::vector<int>>& v) 
{
        long long int result=0;
        for (int i=0;i<n-1;i++) {
                result += v[i][0]*v[i+1][1] - v[i+1][0]*v[i][1];
        }
        result += v[n-1][0]*v[0][1] - v[0][0]*v[n-1][1];
        return std::abs(result);
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<std::vector<int>> v(n, std::vector<int>(2));
        for (int i=0;i<n;i++) {
                std::cin >> v[i][0] >> v[i][1];
        }

        long long int result = 0;
        std::vector<std::vector<int>> x(3, std::vector<int>(2));
        for (int i=0;i<n-2;i++) {
                x[0] = v[i];
                for (int j=i+1;j<n-1;j++) {
                        x[1] = v[j];
                        for (int k=j+1;k<n;k++) {
                                x[2] = v[k];
                                result = std::max(result, area(3, x));
                        }
                }
        }

        std::cout << result/2;
        if (result%2==1) {
                std::cout << ".5";
        }
        else {
                std::cout << ".0";
        }

        return 0;
}