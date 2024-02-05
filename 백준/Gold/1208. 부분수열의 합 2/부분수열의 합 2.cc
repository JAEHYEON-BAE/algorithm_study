#include <iostream>
#include <vector>
#include <unordered_map>
void left(std::unordered_map<int, int>& map, const int& start, const int& end, const int& sum, const std::vector<int>& v)
{
        if (start == end) {
                ++map[sum];
                return;
        }
        left(map, start+1, end, sum, v);
        left(map, start+1, end, sum+v[start], v);
}
void right(std::unordered_map<int, int>& map, long long int& cnt, const int& start, const int& end, const int& sum, const std::vector<int>& v, const int& s)
{
        if (start == end) {
                cnt += map[s-sum];
                return;
        }
        right(map, cnt, start+1, end, sum, v, s);
        right(map, cnt, start+1, end, sum+v[start], v, s);
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
        long long int cnt=0;
        std::unordered_map<int, int> map;
        left(map, 0, n/2, 0, v);
        right(map, cnt, n/2, n, 0, v, s);
        if (!s) --cnt;
        std::cout << cnt;
        return 0;
}