#include <iostream>
#include <string>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        std::string str;
        std::getline(std::cin, str);
        if ((str[0]>='A' && str[0]<='Z') || str[0]=='_' || str[str.size()-1]=='_') {
                std::cout << "Error!";
                return 0;
        }
        bool is_cpp = false;
        bool is_java = false;
        bool toUpper = false;
        std::string result;
        for (char c: str) {
                if (c>='A' && c<='Z') {
                        if (is_cpp) {
                                std::cout << "Error!";
                                return 0;
                        }
                        is_java = true;
                        result += '_';
                        result += (char)(c+'a'-'A');
                        continue;
                }
                if (c=='_') {
                        if (is_java || toUpper) {
                                std::cout << "Error!";
                                return 0;
                        }
                        is_cpp = true;
                        toUpper = true;
                        continue;
                }
                if (toUpper) {
                        result += (char)(c+'A'-'a');
                        toUpper = false;
                }
                else result += c;
        }
        std::cout << result;
        return 0;
}