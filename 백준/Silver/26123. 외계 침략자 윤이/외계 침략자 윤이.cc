// 26123

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, d;  std::cin >> n >> d;
  std::vector<int> h(n);
  std::vector<int> cnt(300'001, 0);
  int max=-1;
  for (int i=0;i<n;++i) {
    std::cin >> h[i];
    max=std::max(max, h[i]);
    ++cnt[h[i]];
  }

  long long int result=0LL;
  for (int i=0;i<d;++i) {
    if (max<=0) break;
    result=result+cnt[max];
    cnt[max-1]+=cnt[max];
    --max;
  }
  std::cout << result;

  
  return 0;
}