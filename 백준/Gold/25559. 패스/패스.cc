// 25559

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

  if (n==1) std::cout << '1';
  else if (n&1) std::cout << "-1";
  else {
    for (int i=0;i<n;i+=2) std::cout << n-i << ' ' << i+1 << ' ';
  }
  
  return 0;
}