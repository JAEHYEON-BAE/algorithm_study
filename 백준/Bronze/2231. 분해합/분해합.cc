// 2231

#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  for (int i=n-60;i<n;++i) {
    int tmp=i;
    int sum=tmp;
    while (tmp) {
      sum+=tmp%10;
      tmp/=10;
    }
    if (sum==n) {
      std::cout << i;
      return 0;
    }
  }
  std::cout << '0';
  return 0;
}