// 30349

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int m, n, a, b, x, y;
  std::cin >> m >> n >> a >> b >> x >> y;

  int Tx_min=std::max(0, x);
  int Tx_max=std::min(a-1, x+m-1);

  int Ty_min=std::max(0, y);
  int Ty_max=std::min(b-1, y+n-1);

  if (Tx_min>Tx_max || Ty_min>Ty_max) {
    std::cout << "NEPATAIKYS";
    return 0;
  }
  std::cout << Tx_min+Ty_min;
  return 0;
}