// 23250

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

std::pair<int, int> hanoi(int n, long long int k)
{
  
  if (k==1LL) return {1, n&1?3:2};
  if (k+1==1LL<<n) return {n&1?1:2, 3};
  
  long long int tot=1LL<<n;
  if (k==tot>>1) return {1, 3};
  else if (k<(tot>>1)) {
    std::pair<int, int> tmp=hanoi(n-1, k);
    
    if (tmp.first==2 || tmp.first==3) tmp.first=5-tmp.first;
    if (tmp.second==2 || tmp.second==3) tmp.second=5-tmp.second;
    return tmp;
  }
  else {
    std::pair<int, int> tmp=hanoi(n-1, k-(tot>>1));
    if (tmp.first==1 || tmp.first==2) tmp.first=3-tmp.first;
    if (tmp.second==1 || tmp.second==2) tmp.second=3-tmp.second;
    return tmp;
  }
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n; long long int k;  std::cin >> n >> k;
  auto res=hanoi(n, k);
  std::cout << res.first << ' ' << res.second;
  

  
  return 0;
}
