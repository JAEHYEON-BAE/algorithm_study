#include <iostream>
#include <unordered_map>
#include <vector>
void left(std::unordered_map<int, int>& map, const int& start, const int& end, const int& sum, const std::vector<int>& v) 
{
        if (start == end) {
                ++map[sum];
                return;
        }
        left(map, start+1, end, sum, v);
        left(map, start+1, end, sum+v[start], v);
}
void right(std::unordered_map<int, int>& map, const int& start, const int& end, const int& sum, int& cnt, const int& s, const std::vector<int>& v)
{
        if (start == end) {
                cnt += map[s-sum];
                return;
        }
        right(map, start+1, end, sum, cnt, s, v);
        right(map, start+1, end, sum+v[start], cnt, s, v);
}
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n, s;       std::cin >> n >> s;
        std::vector<int> v(n);
        for (int i=0;i<n;i++) {
                std::cin >> v[i];
        }
        std::unordered_map<int, int> map;
        int cnt=0;
        left(map, 0, n/2, 0, v);
        right(map, n/2, n, 0, cnt, s, v);
        if (!s) --cnt;
        std::cout << cnt;
        return 0;
}