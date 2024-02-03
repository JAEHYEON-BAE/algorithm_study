#include <iostream>
#include <vector>
int minusone=0, zero=0, one=0;
bool isFilled(int c, int r, int n, const std::vector<std::vector<int>>& v)
{
        int a = v[c][r];
        for (int i=c;i<c+n;i++) {
                for (int j=r;j<r+n;j++) {
                        if (v[i][j] != a) return false;
                }
        }
        if (a==1) ++one;
        else if (a==0) ++zero;
        else ++minusone;
        return true;
}
void dnq(int c, int r, int n, const std::vector<std::vector<int>>& v)
{
        if (isFilled(c, r, n, v) == true) return;
        dnq(c, r, n/3, v);
        dnq(c, r+n/3, n/3, v);
        dnq(c, r+2*n/3, n/3, v);
        dnq(c+n/3, r, n/3, v);
        dnq(c+n/3, r+n/3, n/3, v);
        dnq(c+n/3, r+2*n/3, n/3, v);
        dnq(c+2*n/3, r, n/3, v);
        dnq(c+2*n/3, r+n/3, n/3, v);
        dnq(c+2*n/3, r+2*n/3, n/3, v);
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n;  std::cin >> n;
        std::vector<std::vector<int>> v(n, std::vector<int>(n));
        for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                        std::cin >> v[i][j];
                }
        }
        dnq(0, 0, n, v);
        std::cout << minusone << "\n" << zero << "\n" << one;
        return 0;
}