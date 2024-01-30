#include <iostream>
#include <string>
#include <map>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::string str;
        std::cin >> str;
        std::map<char, int> map;
        for (char x: str) {
                if (map.find(x) == map.end()) {map[x] = 0;}
                ++map[x];
        }

        std::string answer;
        char odds = '0';
        for (std::pair<char, int> p: map) {
                if (p.second%2==0) {
                        for (int i=0;i<p.second/2;i++) {
                                answer.push_back(p.first);
                        }
                }
                else {
                        if (odds != '0') {std::cout << "I'm Sorry Hansoo"; return 0;}
                        for (int i=0;i<(p.second-1)/2;i++) {
                                answer.push_back(p.first);
                        }
                        odds = p.first;
                }
        }
        int len = (int) answer.size();

        if (odds != '0') {
                answer.push_back(odds);
        }
        for (int i=0;i<len;i++) {
                answer.push_back(answer[len-i-1]);
        }
        std::cout << answer;
        return 0;
}