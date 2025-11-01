// 21767

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;
using ll=long long int;

ll a[4];  

struct Card
{
  int t;
  ll u;
  Card() {}
  Card(int t, ll u): t(t), u(u) {}

  bool operator<(const Card &o) const {
    return static_cast<long double>(u)/static_cast<long double>(a[t]) < static_cast<long double>(o.u)/static_cast<long double>(a[o.t]);
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  std::cin >> a[0] >> a[1] >> a[2] >> a[3];
  std::vector<Card> cards(n);
  for (int i=0;i<n;++i) {
    char c;  std::cin >> c;
    cards[i].t=(c-'A');
    std::cin >> cards[i].u;
  }

  for (int i=0;i<k;++i) {
    Card &c=*std::max_element(cards.begin()+i, cards.end());
    std::cout << static_cast<char>('A'+(c.t)) << ' ' << c.u << '\n';
    a[c.t]+=c.u;
    std::swap(c, cards[i]);
  }
  
  return 0;
}