// 5843

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);
  
  ll n, m;  std::cin >> n >> m;
  ll res=0LL;
  std::vector<std::pair<ll, ll>> p;
  p.push_back({0, 1});
  p.push_back({m, -1});
  while (n--) {
    ll s, e;  std::cin >> s >> e;
    p.push_back({s, -1});
    p.push_back({e, 1});
    res+=std::abs(s-e);
  }
  std::sort(p.begin(), p.end());

  ll sum=p.front().second;
  for (int i=1;i<p.size();++i) {
    res+=(p[i].first-p[i-1].first)*std::abs(sum);
    sum+=p[i].second;
  }
  std::cout << res;
  return 0;
}