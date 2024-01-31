#include <iostream>
#include <vector>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int k;  std::cin >> k;
        std::vector<int> dir(12);
        std::vector<int> len(12);
        for (int i=0;i<6;i++) {
                std::cin >> dir[i] >> len[i];
                dir[i+6] = dir[i];
                len[i+6] = len[i];
        }
        for (int i=0;i<6;i++) {
                if (dir[i]==dir[i+2] && dir[i+1]==dir[i+3]) {
                        std::cout << k*(len[i+4]*len[i+5] - len[i+1]*len[i+2]);
                        return 0;
                }
        }
        return 0;
}