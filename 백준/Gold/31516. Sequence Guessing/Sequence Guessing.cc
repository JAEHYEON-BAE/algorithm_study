// 31516

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cout << "66668" << std::endl;
  std::vector<int> v(66668);
  for (int i=0;i<66'668;++i) {
    if (i&1) v[i]=v[i-1]+1;
    else v[i]=3*(i>>1);
  }
  std::vector<std::pair<bool, bool>> FLAG(33'334, {0, 0});

  std::set<int> used;
  int x;
  while (std::cin >> x) {
    if (x==-1) {
      for (const int &a:v) std::cout << a << '\n';
      std::cout.flush();
      return 0;
    }
    else {
      int k=x/3;
      if (x==100'000) {
        std::cout << "66668" << std::endl;
        used.insert(66668);
        continue;
      }
      if (x%3==0) {
        std::cout << 2*k+1 << std::endl;
        used.insert(2*k+1);
      }
      else if (x%3==1) {
        if (FLAG[k].second) {
          std::cout << 2*k+2 << std::endl;
          used.insert(2*k+2);
        }
        else {
          std::cout << "-1" << std::endl;
          FLAG[k].first=1;
          v[2*k+1]=x+1;
        }
      }
      else {
        if (FLAG[k].first) {
          std::cout << 2*k+2 << std::endl;
          used.insert(2*k+2);
        }
        else {
          std::cout << "-1" << std::endl;
          FLAG[k].second=1;
          v[2*k+1]=x-1;
        }
      }
    }
    if (used.size()==100'000) break;
  }
  return 0;
}
