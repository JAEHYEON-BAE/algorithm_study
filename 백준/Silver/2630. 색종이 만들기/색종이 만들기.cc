#include <iostream>
#include <vector>
int white=0, blue=0;
bool isFilled(int c, int r, int n, const std::vector<std::vector<bool>>& v) {
        bool a = v[c][r];
        for (int i=c;i<c+n;i++) {
                for (int j=r;j<r+n;j++) {
                        if (v[i][j]!=a) {
                                return false;
                        }
                }
        }
        if (a) ++blue;
        else ++white;
        return true;
}

void dnq(int c, int r, int n, const std::vector<std::vector<bool>>& v) {
        if (isFilled(c, r, n, v)) {return;}
        dnq(c, r, n/2, v);
        dnq(c+n/2, r, n/2, v);
        dnq(c, r+n/2, n/2, v);
        dnq(c+n/2, r+n/2, n/2, v);
}


int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n;  std::cin >> n;
        std::vector<std::vector<bool>> v(n, std::vector<bool>(n));
        for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                        int tmp;
                        std::cin >> tmp;
                        v[i][j] = tmp;
                }
        }
        dnq(0, 0, n, v);
        std::cout << white << "\n" << blue;
        return 0;
}