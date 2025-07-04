// 6015

#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<long long int> w(n);
  for (int i=0;i<n;++i) std::cin >> w[i];

  long long int f=0, s=0;
  for (int i=n-1;i>=0;--i) {
    if (w[i]+s>=f) {
      std::swap(f, s);
      f+=w[i];
    }
  }
  std::cout << f << ' ' << s;
  
  return 0;
}
