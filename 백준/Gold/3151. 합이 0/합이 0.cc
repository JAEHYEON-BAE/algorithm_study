// 3151

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::map<int, ll> cnt;
  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    ++cnt[x];
  }
  std::vector<int> a;
  for (auto &p:cnt) a.push_back(p.first);

  ll res=0;
  n=a.size();
  for (int i=0;i<n;++i) {
    int target=-a[i];
    // std::cout << a[i] << '\n';
    if (!(target&1)) {
      auto pos=std::lower_bound(a.begin()+i+1, a.end(), target/2);
      if (pos<a.end() && *pos==target/2 && cnt[*pos]>1) {
        ll t=cnt[*pos];
        res+=cnt[a[i]]*t*(t-1)/2;
        // std::cout << '\t' << *pos << '\t' << t << '\n';
      }
      // std::cout << *pos << '\n';
    }

    if (cnt[a[i]]>1) {
      auto pos=std::lower_bound(a.begin()+i+1, a.end(), target*2);
      if (pos<a.end() && *pos==target*2) {
        ll t=cnt[a[i]];
        res+=t*(t-1)/2*cnt[*pos];
      }
    }
    
    int l=i+1, r=n-1;
    while (l<r) {
      ll tmp=a[l]+a[r];
      if (tmp==target) {
        // std::cout << '\t' << a[l] << ' ' << a[r] << '\t' << cnt[a[l]] << ' ' << cnt[a[r]] << '\n';
        res+=cnt[a[l]]*cnt[a[r]]*cnt[a[i]], ++l, --r;
      }
      else if (tmp<target) ++l;
      else --r;
    }
  }

  if (cnt[0]>2) {
    ll t=cnt[0];
    res+=t*(t-1)*(t-2)/6;
  }
  std::cout << res;
  
  return 0;
}