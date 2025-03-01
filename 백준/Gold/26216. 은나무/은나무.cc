// 26216

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

long long int power(int x, int k)
{
  if (k==0) return 1LL;
  long long int tmp=power(x, k/2);
  if (k&1) return tmp*tmp*static_cast<long long int>(x);
  else return tmp*tmp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k, h, q;
  std::cin >> k >> h >> q;
  long long int tot=0LL;
  for (int i=0;i<h;++i) {
    tot+=power(k+1, i);
  }
  long long int n=tot*static_cast<long long int>(k)+1LL;
  while (q--) {
    long long int a, b;
    std::cin >> a >> b;
    if (a>=n || b>=n) {
      std::cout << -1 << '\n';
      continue;
    }
    if (a==b) {
      std::cout << 0 << '\n';
      continue;
    }

    std::vector<int> a_route, b_route;
    long long int mod=n/(k+1);
    do {
      if (mod==1) {
        a_route.emplace_back(a-1);
        continue;
      }
      if (a%mod) a_route.emplace_back((a/mod)<<1);
      else {
        a_route.emplace_back(((a/mod)<<1)-1);
        break;
      }
      a%=mod;
    } while (mod/=(k+1));
    
    mod=n/(k+1);
    do {
      if (mod==1) {
        b_route.emplace_back(b-1);
        continue;
      }
      if (b%mod) b_route.emplace_back((b/mod)<<1);
      else {
        b_route.emplace_back(((b/mod)<<1)-1);
        break;
      }
      b%=mod;
    } while (mod/=(k+1));

    long long int length=0LL;
    bool divided=false;
    for (int i=0;i<std::max(a_route.size(), b_route.size());++i) {
      if (i>=a_route.size() || i>=b_route.size()) {
        ++length;  continue;
      }
      if (a_route[i]!=b_route[i]) divided=true;
      if (divided) length+=2;
    }
    std::cout << length << '\n';
  }


  return 0;
}