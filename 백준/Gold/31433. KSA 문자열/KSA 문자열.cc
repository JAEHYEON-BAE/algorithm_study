#include <iostream>
#include <string>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        std::string str;
        std::cin >> str;
        size_t len = str.size();
        std::vector<bool> valid(len, true);
        int count = 0;
        if (len>=2 && str[0]=='S' && str[1]=='A') {
                char match = 'K';
                for (size_t i=2;i<len;++i) {
                        const char c = str[i];
                        if (c==match) {
                                if (match=='K') match='S';
                                else if (match=='S') match='A';
                                else match='K';
                        }
                        else {
                                ++count;
                        }
                }
                ++count;
        }
        else {
                char match = 'K';
                for (const char& c: str) {
                        if (c==match) {
                                if (match=='K') match='S';
                                else if (match=='S') match='A';
                                else match='K';
                        }
                        else {
                                ++count;
                        }
                }
        }
        std::cout << 2*count;
        return 0;
}