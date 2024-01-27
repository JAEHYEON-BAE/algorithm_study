#include <iostream>
#include <string>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int r, c; 
        std::cin >> r >> c;
        std::vector<std::string> str;
        std::string answer = "zzzzzzzzzzzzzzzzzzzzzzzzzz";
        for (int i=0;i<r;i++) {
                std::string s;
                std::cin >> s;

                std::string word;
                for (char c: s) {
                        if (c=='#') {
                                if (word.size() > 1) {
                                        answer = std::min(answer, word);
                                        word.clear();
                                }
                                word.clear();
                                continue;
                        }
                        word += c;
                }
                if (word.size() > 1) {
                        answer = std::min(answer, word);
                }
                str.push_back(s);
        }

        for (int j=0;j<c;j++) {
                std::string s;
                for (int i=0;i<r;i++) {
                        s += str[i][j];
                }
                std::string word;
                for (char c: s) {
                        if (c=='#') {
                                if (word.size() > 1) {
                                        answer = std::min(answer, word);
                                        word.clear();
                                }
                                word.clear();
                                continue;
                        }
                        word += c;
                }
                if (word.size() > 1) {
                        answer = std::min(answer, word);
                }
        }
        if (answer == "zzzzzzzzzzzzzzzzzzzzzzzzzz") {
                answer.clear();
        }
        std::cout << answer;
        return 0;
}