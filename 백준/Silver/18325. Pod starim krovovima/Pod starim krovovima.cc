// 18325

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

struct Glass
{
  int cap, cur, idx;
  Glass(): cap(0), cur(0), idx(0) {}
  bool operator< (const Glass &other) const {
    return cap>other.cap;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  long long int total=0LL;
  std::vector<Glass> glasses(n);
  for (int i=0;i<n;++i) {
    int t;
    std::cin >> t >> glasses[i].cap;
    glasses[i].idx=i;
    total=total+t;
  }
  std::sort(glasses.begin(), glasses.end());
  for (int i=0;i<n;++i) {
    if (total<=glasses[i].cap) {
      glasses[i].cur=total;
      break;
    }
    else {
      total-=glasses[i].cap;
      glasses[i].cur=glasses[i].cap;
    }
  }
  std::vector<int> result(n);
  int empty=0;
  for (const Glass &g:glasses) {
    result[g.idx]=g.cur;
    if (g.cur==0) ++empty;
  }

  std::cout << empty << '\n';
  for (int x:result) std::cout << x << ' ';
  
  
  return 0;
}