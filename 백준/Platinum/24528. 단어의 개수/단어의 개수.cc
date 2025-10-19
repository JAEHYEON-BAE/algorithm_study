// 24528

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=998'244'353;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  // dp{i+1}=dp{i} + (dp{i}-dp{prev(c)-1})
  int n;  std::cin >> n;
  ll dp=1;
  std::vector<ll> prev(26, 0LL);
  for (int i=0;i<n;++i) {
    char c;  ll v;
    std::cin >> c >> v;
    ll tmp=v*dp%MOD-(v-1LL)*prev[c-'a']%MOD;
    tmp=(tmp+MOD)%MOD;
    dp=(v+1LL)*dp%MOD-v*prev[c-'a']%MOD;
    dp=(dp+MOD)%MOD;
    prev[c-'a']=tmp;
  }
  std::cout << (dp-1+MOD)%MOD;
  return 0;
}