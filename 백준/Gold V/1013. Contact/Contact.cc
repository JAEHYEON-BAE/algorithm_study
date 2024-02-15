#include <iostream>
#include <string>
#include <regex>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int t;  std::cin >> t;
        std::regex pattern("^(100+1+|01)+$");
        while (t--) {
                std::string str;
                std::cin >> str;
                if (std::regex_match(str, pattern)) {
                        std::cout << "YES\n";
                }
                else std::cout << "NO\n";
        }
        return 0;
}