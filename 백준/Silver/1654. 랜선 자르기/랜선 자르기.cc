#include <iostream>
#include <vector>
#include <algorithm>
int count(const std::vector<int>& v, const int& cm) 
{
        int cnt=0;
        for (int x:v) {
                cnt += x/cm;
        }
        return cnt;
}

int main()
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);     std::cout.tie(NULL);
        int k, n;       std::cin >> k >> n;
        std::vector<int> v(n);
        int m=0;
        for (int i=0;i<k;i++) {
                std::cin >> v[i];
                m = std::max(m, v[i]);
        }
        long long int result=0;
        long long int l=1, r=m;
        while (l<=r) {
                long long int mid = (l+r)/2;
                int cnt = count(v, mid);
                if (cnt<n) {
                        r = mid-1;
                }
                else {
                        l = mid+1;
                        result = std::max(result, mid);
                }
        }
        std::cout << result;
        return 0;
}