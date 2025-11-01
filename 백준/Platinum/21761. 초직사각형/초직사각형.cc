// 21767

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;
using ll=long long int;
using ld=long double;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  ll a[4];  
  std::cin >> a[0] >> a[1] >> a[2] >> a[3];
  std::vector<std::vector<ll>> cards(4);
  for (int i=0;i<4;++i) cards[i].push_back(0);
  for (int i=0;i<n;++i) {
    char t; ll u;  std::cin >> t >> u;
    cards[t-'A'].push_back(u);
  }
  for (int i=0;i<4;++i) std::sort(cards[i].begin(), cards[i].end(), std::greater<ll>());
  int it[4]={0, 0, 0, 0};
  for (int i=0;i<k;++i) {
    ld tmp[4]={(ld)cards[0][it[0]]/(ld)a[0], (ld)cards[1][it[1]]/(ld)a[1], (ld)cards[2][it[2]]/(ld)a[2], (ld)cards[3][it[3]]/(ld)a[3]};
    int t=std::max_element(tmp, tmp+4)-tmp;
    std::cout << (char)('A'+t) << ' ' << cards[t][it[t]] << '\n';
    a[t]+=cards[t][it[t]];
    ++it[t];
  }

  return 0;
}