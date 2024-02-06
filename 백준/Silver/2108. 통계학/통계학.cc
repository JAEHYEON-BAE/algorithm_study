#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int n;  std::cin >> n;
        int sum=0;
        std::vector<int> v;
        std::map<int, int> map;
        int s=4001, l=-4001;
        for (int i=0;i<n;i++) {
                int x;  std::cin >> x;
                sum += x;
                v.push_back(x);
                ++map[x];
                s = std::min(s, x);
                l = std::max(l, x);
        }
        int avg;
        if (sum<0) {
                sum *= -1;
                if ((sum%n)*2>=n) avg = (sum/n+1) * (-1);
                else avg = sum/n * -1;
        }
        else {
                if ((sum%n)*2>=n) avg = sum/n+1;
                else avg = sum/n;
        }
        std::sort(v.begin(), v.end());
        int mode=v[0], tmp=0;
        bool cnt=false;
        for (const std::pair<int, int> pii: map) {
                if (pii.second > tmp) {
                        tmp = pii.second;
                        mode = pii.first;
                        cnt = false;
                }
                else if (pii.second == tmp) {
                        if (!cnt) {
                                mode = pii.first;
                                cnt = true;
                        }
                }
        }
        std::cout << avg << "\n" << v[n/2] << "\n" << mode << "\n" << l-s;
        return 0;
}