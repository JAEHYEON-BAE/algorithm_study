#include <iostream>
#include <string>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::string str;
        std::cin >> str;
        std::string num;
        bool minus = false;
        int result = 0;
        for (int i=0;i<=(int)str.size();i++) {
                if (str[i]=='-' || str[i]=='+' || i==(int)str.size()) {
                        if (minus) result -= std::stoi(num);
                        else result += std::stoi(num);
                        num = "";
                }
                else {
                        num.push_back(str[i]);
                }
                if (str[i]=='-') minus=true;
        }
        std::cout << result;
        return 0;
}