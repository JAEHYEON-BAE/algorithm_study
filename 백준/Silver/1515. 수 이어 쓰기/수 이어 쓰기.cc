#include <iostream>
#include <string>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::string str;
        std::cin >> str;
        long long int i=1;
        int j=0;
        int len = str.size();
        while (true) {
                std::string num = std::to_string(i);
                for (char c : num) {
                        if (c==str[j]) {
                                ++j;
                        }
                        if (j == len) {
                                std::cout << i;
                                return 0;
                        }
                }
                ++i;
        }

        return 0; 
}