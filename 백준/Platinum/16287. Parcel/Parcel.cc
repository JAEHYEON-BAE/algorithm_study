// 16287

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int w, n;  std::cin >> w >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];
  std::sort(v.begin(), v.end());
  
  std::array<int, 400'001> ii, jj;
  for (int i=0;i<400'001;++i) ii[i]=jj[i]=-1;

  for (int i=0;i<n-1;++i) for (int j=i+1;j<n;++j) {
    int s=v[i]+v[j];
    if (ii[s]==-1) ii[s]=i, jj[s]=j;
  }

  for (int i=0;i<n-1;++i) for (int j=i+1;j<n;++j) {
    int tmp=w-v[i]-v[j];
    if (tmp>400'000 || tmp<0 || ii[tmp]<0 || jj[tmp]<0) continue;
    if (ii[tmp]!=i && ii[tmp]!=j && jj[tmp]!=i && jj[tmp]!=j) {
      std::cout << "YES";
      return 0;
    }
  }
  std::cout << "NO";
  return 0;
}