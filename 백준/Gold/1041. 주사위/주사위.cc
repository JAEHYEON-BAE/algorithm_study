// 1041

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll=long long int;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  ll n, a, b, c, d, e, f;
  std::cin >> n >> a >> b >> c >> d >> e >> f;
  ll max=std::max({a, b, c, d, e, f});
  ll min=std::min({a, b, c, d, e, f});

  if (n==1) {
    std::cout << a+b+c+d+e+f-max;
    return 0;
  }
  ll corner=std::min({a+b+c, a+b+d, a+d+e, a+c+e, b+c+f, b+d+f, c+e+f, d+e+f});
  ll bottom=std::min({a+b, a+c, a+d, a+e, b+c, b+d, b+f, c+e, c+f, d+e, d+f, e+f});

  ll tmp=corner*4+bottom*4;
  std::cout << tmp + (n-2)*(n-2)*min*5LL + (n-2)*bottom*8LL + (n-2)*min*4LL;
  return 0;
}

