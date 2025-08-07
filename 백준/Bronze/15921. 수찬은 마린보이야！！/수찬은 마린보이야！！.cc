// 15921

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
  int tot=0;
  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    tot+=x;
  }
  if (n && tot) std::cout << "1.00";
  else std::cout << "divide by zero";


  return 0;
}
