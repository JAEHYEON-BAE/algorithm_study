#include <iostream>
#include <vector>
bool is_palin(const int& x)
{
        std::string str = std::to_string(x);
        int l=0, r=(int)str.size()-1;
        while (l<=r) {
                if (str[l]!=str[r]) return false;
                ++l;    --r;
        }
        return true;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<bool> p(2000001, true);
        p[0] = p[1] = false;
        for (int i=2;i*i<=2000001;++i) {
                if (p[i]) {
                        for (int j=i;i*j<=2000001;++j) {
                                p[i*j] = false;
                        }
                }
        }
        for (int i=n;i<=2000001;++i) {
                if (p[i] && is_palin(i)) {
                        std::cout << i;
                        break;
                }
        }
        return 0;
}