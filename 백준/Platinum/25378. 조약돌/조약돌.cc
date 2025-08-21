// 25378

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

  std::vector<int> v(n);
  for (int &i:v) std::cin >> i;

  int cnt=0;
  for (int i=0;i<n-1;++i) if (v[i]) {
    if (v[i]<=v[i+1]) {
      v[i+1]-=v[i];
      ++cnt;
    }
    else {
      v[i+1]=0;
      cnt+=2;
    }
  }
  if (v.back()) ++cnt;
  std::cout << cnt;
  return 0;
}

