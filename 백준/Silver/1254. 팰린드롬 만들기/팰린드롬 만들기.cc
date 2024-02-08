#include <iostream>
#include <string>
bool is_palin(const std::string& str, int a, int b) 
{
        while (a<=b) {
                if (str[a] != str[b]) return false;
                ++a; --b;
        }
        return true;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        std::string str;
        std::cin >> str;
        int n = (int)str.size();
        int p = n-1;
        for (int i=n-1;i>=0;--i) {
                if (is_palin(str, i, n-1)) {
                        p = i;
                }
        }
        std::cout << n+p;
        return 0;
}