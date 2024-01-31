#include <iostream>
#include <vector>
#include <string>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n;  std::cin >> n;
        std::vector<std::string> v(n);
        std::vector<std::pair<int, int>> a;
        for (int i=0;i<n;i++) {
                std::cin >> v[i];
                for (int j=0;j<n;j++) {
                        if (v[i][j]!='.') {
                                a.push_back({i, j});
                        }
                }
        }
        int cnt=0;
        int len = (int)a.size();
        for (int i=0;i<len-2;i++) {
                std::pair<int, int> x = a[i];
                for (int j=i+1;j<len-1;j++) {
                        std::pair<int, int> y = a[j];
                        for (int k=j+1;k<len;k++) {
                                std::pair<int, int> z = a[k];
                                if (x==z || y==z) continue;
                                if ((y.second-x.second)*(z.first-y.first)==(y.first-x.first)*(z.second-y.second)) {
                                        ++cnt;
                                }
                        }
                }
        }
        std::cout << cnt;
        return 0;
}