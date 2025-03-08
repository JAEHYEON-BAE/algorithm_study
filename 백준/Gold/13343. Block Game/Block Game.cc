// 6677

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

bool game(long long int n, long long int m)
{
  if (n%m==0 || n>m<<1) return true;
  else return !game(m, n%m);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long int n, m;  std::cin >> n >> m;
  if (n<m) std::swap(n, m);
  if (game(n, m)) std::cout << "win";
  else std::cout << "lose";

  return 0;
}