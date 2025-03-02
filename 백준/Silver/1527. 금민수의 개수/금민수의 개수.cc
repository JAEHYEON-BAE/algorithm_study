// 1527

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int MOD=1'000'000'007;

const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int a, b;
long long result=0;

void solve(long long num)
{
  if (num>b) return;
  if (a<=num && num<=b) ++result;
  solve(num*10+4);
  solve(num*10+7);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> a >> b;
  solve(4);  solve(7);
  std::cout << result;

  return 0;
}