// 7433

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  std::bitset<100> mod(0);
  int x;  std::cin >> x;
  x=(x%k+k)%k;
  mod[x]=1;
  
  for (int i=1;i<n;++i) {
    std::cin >> x;
    x=(x%k+k)%k;
    mod=(mod<<x) | (mod>>(k-x)) | (mod>>x) | (mod<<(k-x));
  }

  std::cout << (mod[0]?"Divisible":"Not divisible");

  return 0;
}
