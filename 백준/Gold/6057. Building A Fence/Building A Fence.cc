// 6057

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

inline int COMB(int a, int b) 
{
  if (a<b) return 0;
  if (b==0 || b==a) return 1;
  if (b>a-b) b=a-b;

  long long int result=1LL;
  for (int i=0;i<b;++i) {
    result=result*(a-i)/(i+1);
  }
  return static_cast<int>(result);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  /*
  naive: (n-1) C 3;
  the longest piece's size < n/2
  */

  int invalid=0;
  for (int l=(n+1)>>1;l<=n-3;++l) {
    invalid+=COMB(n-l-1, 2);
  }
  invalid<<=2;
  std::cout << COMB(n-1, 3)-invalid;
  
  return 0;
}