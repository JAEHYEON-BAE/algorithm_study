#include <iostream>
#include <vector>
#include <string>
int count_one(int n)
{
        int result = 0;
        n &= 0x3FF;
        while (n) {
                n &= n-1;
                ++result;
        }
        return result;
}
/*
void print_bits(int n)
{
        std::vector<char> tmp;
        for (int i=0;i<10;++i) {
                if (n&(1<<i))   tmp.push_back('O');
                else    tmp.push_back('#');
        }
        for (int i=9;i>=0;--i) {
                std::cout << tmp[i];
        }
        std::cout << std::endl;
}
*/
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);

        std::vector<std::string> map(10);
        for (int i=0;i<10;++i) {
                std::cin >> map[i];
        }
        std::vector<int> bi_map(10, 0);
        for (int i=0;i<10;++i) {
                for (int j=0;j<10;++j) {
                        if (map[i][j]=='O')     bi_map[i] |= (1<<(9-j));
                }
        }

        int answer = 101;

        for (int i=0;i<(1<<10);++i) {
                int temp = count_one(i);
                std::vector<int> tmp_bi_map = bi_map;

                tmp_bi_map[0] ^= (i<<1) ^ (i>>1) ^ i;
                tmp_bi_map[1] ^= i;

                for (int j=1;j<10;++j) {
                        int push = tmp_bi_map[j-1]&0x3FF;
                        temp += count_one(push);

                        tmp_bi_map[j-1] ^= push;
                        tmp_bi_map[j] ^= (push<<1) ^ (push) ^ (push>>1);
                        if (j<9)        tmp_bi_map[j+1] ^= push;
                }

                if ((tmp_bi_map[9]&0x3FF)==0){
                        answer = (temp<answer)? temp : answer;
                }
        }
        if (answer==101) std::cout << "-1";
        else    std::cout << answer;
        return 0;
}