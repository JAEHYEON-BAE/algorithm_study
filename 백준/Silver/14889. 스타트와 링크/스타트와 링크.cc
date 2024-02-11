#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<std::vector<int>> s(n, std::vector<int>(n, 0));
        for (int i=0;i<n;++i) {
                for (int j=0;j<n;++j) {
                        std::cin >> s[i][j];
                }
        }

        std::vector<bool> v(n);
        std::fill(v.begin() + n/2, v.end(), true);
        int result = 1987654321;
        std::vector<std::vector<int>> team;
        do {
                if (v[0]) break;
                std::vector<int> tmp1;
                std::vector<int> tmp2;
                for (int i=0;i<n;++i) {
                        if (v[i]) tmp1.push_back(i);
                        else tmp2.push_back(i);
                }

                int start=0, link=0;
                for (size_t i=0;i<tmp1.size();++i) {
                        for (size_t j=0;j<tmp1.size();++j) {
                                start += s[tmp1[i]][tmp1[j]];
                                link += s[tmp2[i]][tmp2[j]];
                        }
                }
                result = std::min(result, std::abs(start-link));
        } while (std::next_permutation(v.begin(), v.end()));

        std::cout << result;
        return 0;
}