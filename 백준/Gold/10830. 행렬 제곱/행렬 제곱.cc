#include <iostream>
#include <vector>
std::vector<std::vector<int>> multiple(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b, int n)
{
        std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
        for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                        for (int k=0;k<n;k++) {
                                result[i][j] += (a[i][k]%1000) * (b[k][j]%1000);
                        }
                        result[i][j]%=1000;
                }
        }
        return result;
}

std::vector<std::vector<int>> power(const std::vector<std::vector<int>>& a, long long int b, int n)
{
        if (b==1) return a;
        std::vector<std::vector<int>> tmp = power(a, b/2, n);

        if (b%2==0) 
                return multiple(tmp, tmp, n);
        else
                return multiple(multiple(tmp, tmp, n), a, n);
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n; long long int b; std::cin >> n >> b;
        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                        std::cin >> a[i][j];
                }
        }

        std::vector<std::vector<int>> answer = power(a, b, n);
        for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                        std::cout << answer[i][j]%1000 << " ";
                }
                std::cout << "\n";
        }
        return 0;
}