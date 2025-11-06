// 2792

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<int> v(m);
  int max=0;
  for (int &x:v) {std::cin >> x; max=std::max(max, x);}

  int l=1, r=max;
  int ans=r;
  while (l<=r) {
    int mid=(l+r)>>1;
    int res=0;

    for (int &x:v) {
      res+=(x+mid-1)/mid;
      if (res>n) break;
    }

    if (res<=n) {
      ans=mid;
      r=mid-1;
    }
    else l=mid+1;
  }

  std::cout << ans;
  
  return 0;
}