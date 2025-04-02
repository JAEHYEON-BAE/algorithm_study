// 1459
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

long long int recur(long long int x, long long int y, const long long int &w, const long long int &s)
{
  if (s>=(w<<1)) return (x+y)*w;

  if (y==0) {
    if (s<w) return (x/2)*s*2+(x%2)*w;
    else return x*w;
  }
  else return s*y+recur(x-y, 0, w, s);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long int x, y, w, s;  std::cin >> x >> y >> w >> s;

  if (x<y) std::swap(x, y);
  std::cout << recur(x, y, w, s);
    
  return 0;
}