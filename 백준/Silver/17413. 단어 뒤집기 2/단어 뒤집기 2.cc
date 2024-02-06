#include <iostream>
#include <string>
#include <stack>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        std::string str;
        std::getline(std::cin, str, '\n');
        std::string result = "";
        bool tag = false;
        std::string tmp="";
        std::stack<char> stk;
        for (char c: str) {
                if (c == '<') {
                        tag = true;
                        while (!stk.empty()) {
                                std::cout << stk.top();
                                stk.pop();
                        }
                }
                if (c == '>') {tag = false; std::cout << tmp + '>'; tmp=""; continue;}
                if (tag) tmp.push_back(c);
                else if (c == ' ') {
                        while (!stk.empty()) {
                                std::cout << stk.top();
                                stk.pop();
                        }
                        std::cout << ' ';
                }
                else stk.push(c);
        }
        while (!stk.empty()) {
                std::cout << stk.top();
                stk.pop();
        }
        return 0;
}