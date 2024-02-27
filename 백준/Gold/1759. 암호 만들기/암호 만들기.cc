#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
inline bool is_vowels(const char& c)
{
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
        else return false;
}
inline bool is_valid(const std::string& str) 
{
        int v=0, c=0;
        for (const char x: str) {
                if (is_vowels(x)) ++v;
                else ++c;
        }
        if (v>=1 && c>=2) return true;
        else return false;
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int l, c;
        std::cin >> l >> c;
        std::vector<char> v(c);
        for (int i=0;i<c;++i) {
                std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        std::string answer;
        std::vector<bool> b(c);
        std::fill(b.begin(), b.begin()+l, true);
        do {
                std::string str;
                for (int i=0;i<c;++i) {
                        if (b[i]) str += v[i];
                }
                if (is_valid(str)) {
                        str += '\n';
                        answer += str;
                }
        } while (std::prev_permutation(b.begin(), b.end()));
        std::cout << answer;
        return 0;
}