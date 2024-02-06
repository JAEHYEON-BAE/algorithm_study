#include <iostream>
#include <string>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        std::string str;
        getline(std::cin, str);
        int cnt_q=0, cnt_u=0, cnt_a=0, cnt_c=0, cnt_k=0;
        int processing = 0;
        int result = 0;
        for (char c: str) {
                if (c=='q') {++cnt_q; ++processing;}
                if (c=='u') ++cnt_u;
                if (c=='a') ++cnt_a;
                if (c=='c') ++cnt_c;
                if (c=='k') ++cnt_k;

                if (cnt_q>=cnt_u && cnt_u>=cnt_a && cnt_a>=cnt_c && cnt_c>=cnt_k) {
                        if (c=='k') {
                                result = std::max(result, processing);
                                --processing;
                        }
                }
                else {
                        std::cout << "-1";
                        return 0;
                }
        }
        if (processing > 0)     std::cout << "-1";
        else std::cout << result;
        return 0;
}