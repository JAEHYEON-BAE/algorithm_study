// 6120

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

std::pair<int, int> digit(int x)
{
  assert(x);
  int min=9, max=1;
  while (x) {
    max=std::max(x%10, max);
    if (x%10) min=std::min(x%10, min);
    x/=10;
  }
  return {min, max};
}
bool dp(int x, std::vector<int> &W)
{
  for(int i=1;i<=x;++i) {
    if (W[i]!=-1) continue;
    std::pair<int, int> tmp=digit(i);
    W[i]=(W[i-tmp.first] && W[i-tmp.second])?0:1;
  }
  return W[x];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::vector<int> W(1'000'001, -1);
  for (int i=1;i<10;++i) W[i]=1, W[i+10]=1;
  W[10]=0;
  int n;  std::cin >> n;
  while (n--) {
    int x;  std::cin >> x;
    std::cout << (dp(x, W)?"YES\n":"NO\n");
  }
  return 0;
}