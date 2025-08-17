// 13754

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  if (n==1) {std::cout << '0'; return 0;}

  long long int k, sum=0LL, max=0LL;
  for (int i=0;i<n;++i) {
    std::cin >> k;
    sum+=k;
    max=std::max(max, k);
  }
  std::cout << std::min(sum>>1, sum-max);
  return 0;
}

