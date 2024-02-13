#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        std::vector<std::string> v(n);
        for (int i=0;i<n;++i) {
                std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());
        int cnt=0;
        for (int i=0;i<n-1;++i) {
                if (v[i+1].size() < v[i].size()) ++cnt;
                else if (v[i+1].substr(0, v[i].size())==v[i]) continue;
                else ++cnt;
        }
        std::cout << cnt+1;
        return 0;
}