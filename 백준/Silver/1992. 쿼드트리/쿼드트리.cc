#include <iostream>
#include <vector>
#include <string>
std::string result = "";
bool isFilled(int c, int r, int n, const std::vector<std::vector<bool>>& v) {
        bool a = v[c][r];
        for (int i=c;i<c+n;i++) {
                for (int j=r;j<r+n;j++) {
                        if (v[i][j]!=a) {
                                return false;
                        }
                }
        }
        if (a) result=result+'1';
        else result=result+'0';
        return true;
}

void dnq(int c, int r, int n, const std::vector<std::vector<bool>>& v) {
        if (isFilled(c, r, n, v)) return;
        result = result+'(';
        dnq(c, r, n/2, v);
        dnq(c, r+n/2, n/2, v);
        dnq(c+n/2, r, n/2, v);
        dnq(c+n/2, r+n/2, n/2, v);
        result=result+')';
}


int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        int n;  std::cin >> n;
        std::vector<std::vector<bool>> v(n, std::vector<bool>(n));
        for (int i=0;i<n;i++) {
                std::string str;
                std::cin >> str;
                for (int j=0;j<n;j++) {
                        if (str[j]=='0') v[i][j] = 0;
                        else v[i][j] = 1;
                }
        }
        dnq(0, 0, n, v);
        std::cout << result;
        return 0;
}