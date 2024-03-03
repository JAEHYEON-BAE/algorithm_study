#include <iostream>
#include <string>
#include <stack>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        std::string str, bomb;
        std::cin >> str >> bomb;
        std::string tmp;
        for (const char& c: str) {
                tmp.push_back(c);
                if (tmp.size()>=bomb.size() && tmp.find(bomb, tmp.size()-bomb.size())!=std::string::npos) {
                        for (size_t i=0;i<bomb.size();++i) tmp.pop_back();
                }
        }
        if (tmp.size()) std::cout << tmp;
        else std::cout << "FRULA";
        return 0;
}