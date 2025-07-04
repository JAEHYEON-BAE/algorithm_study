// 7433

#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  std::vector<bool> mod(k, 0);
  int x;  std::cin >> x;
  mod[((x%k)+k)%k]=1;
  
  for (int i=1;i<n;++i) {
    std::cin >> x;
    std::vector<bool> tmp(mod.size(), 0);
    for (int j=0;j<k;++j) {
      if (mod[j]) tmp[((j+x)%k+k)%k]=tmp[((j-x)%k+k)%k]=1;
    }
    mod=tmp;
  }

  std::cout << ((mod[0])?"Divisible":"Not divisible");

  return 0;
}
