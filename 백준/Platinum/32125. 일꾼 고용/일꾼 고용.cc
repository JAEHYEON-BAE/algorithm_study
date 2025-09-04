// 32125

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>

using ll=long long int;
using pl=std::pair<ll, int>;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n, k;  std::cin >> n >> k;
    std::vector<int> c(n);
    for (int &x:c) {
      std::cin >> x;
      if (x==2) x=-1;
    }

    std::unordered_map<int, std::vector<int>> map;
    map[0]={0};
    
    std::vector<int> c_sum(n+1, 0);
    for (int i=0;i<n;++i) {
      c_sum[i+1]=c_sum[i]+c[i];
      map[c_sum[i+1]].push_back(i+1);
    }
    
    std::vector<ll> w_sum(n+1, 0);
    for (int i=1;i<=n;++i) {
      ll x;  std::cin >> x;
      w_sum[i]=w_sum[i-1]+c[i-1]*x;
    }

    ll res=0LL;
    for (const auto &pair:map) {
      if (pair.second.size()<2) continue;
      std::vector<pl> v;
      v.reserve(pair.second.size());
      
      for (const int &x:pair.second) {
        v.push_back({w_sum[x], x});
      }

      ll cnt=0LL;

      // w_sum을 기준으로 sorting하면 쉽게 계산할 수 있지 않을까?
      // O(NlogN)
      std::sort(v.begin(), v.end());

      // binary search : O(N) * O(logN) = O(NlogN)
      for (const pl &p:v) {
        auto it_n=std::lower_bound(v.begin(), v.end(), pl(p.first-k, -1));
        auto it_p=std::lower_bound(v.begin(), v.end(), pl(p.first+k+1, -1));
        cnt+=-1LL+std::abs(it_p-it_n);
      }
      if (cnt&1) assert(!"cnt is not even!");
      res+=cnt>>1;
    }
    std::cout << res << '\n';
  }
  return 0;
}