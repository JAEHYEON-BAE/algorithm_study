// 19575

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int MOD=1'000'000'007;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, x;  std::cin >> n >> x;
  long long int result=0LL;
  int a, k;  std::cin >> a >> k;
  result+=a;
  for (int i=1;i<n+1;++i) {
    std::cin >> a >> k;
    result=(result*x%MOD+a)%MOD;
  }
  std::cout << result;
  return 0;
}