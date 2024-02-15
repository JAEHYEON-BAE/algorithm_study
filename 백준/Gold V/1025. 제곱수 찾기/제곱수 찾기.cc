#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n, m;       std::cin >> n >> m;
        std::vector<std::string> v(n);
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
        }

        int result = -1;
        for (int i=0;i<n;++i) for (int j=0;j<m;++j) {
                for (int dr=-i;dr<n-i;++dr) for (int dc=-j;dc<m-j;++dc) {
                        std::string tmp = "";
                        int r=i, c=j;
                        while (r>=0 && r<n && c>=0 && c<m) {
                                tmp += v[r][c];
                                r+=dr;  c+=dc;
                                int x = std::stoi(tmp);
                                if ((static_cast<int>(sqrt(x)))*(static_cast<int>(sqrt(x)))==x) {
                                        result = std::max(result, x);
                                }
                                if (dr==0&&dc==0) break;
                        }
                }
        }
        std::cout << result;
        return 0;
}