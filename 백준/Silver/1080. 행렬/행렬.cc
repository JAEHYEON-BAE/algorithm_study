#include <iostream>
#include <vector>
#include <string>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, m;       std::cin >> n >> m;
        std::vector<std::string> a(n), b(n);
        for (int i=0;i<n;++i) {
                std::cin >> a[i];
        }
        for (int i=0;i<n;++i) {
                std::cin >> b[i];
        }
        if (n<3 || m<3) {
                if (a==b) std::cout << "0";
                else std::cout << "-1";
                return 0;
        }

        int cnt=0;
        for (int i=0;i<n-2;++i) for (int j=0;j<m-2;++j) {
                if (a[i][j]!=b[i][j]) {
                        for (int p=i;p<i+3;++p) for (int q=j;q<j+3;++q) {
                                if (a[p][q]=='0') a[p][q]='1';
                                else a[p][q]='0';
                        }
                        ++cnt;
                }
        }
        if (a==b) std::cout << cnt;
        else std::cout << "-1";
        return 0;
}