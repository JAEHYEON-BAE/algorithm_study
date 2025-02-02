// 16566

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, k;  std::cin >> n >> m >> k;
  std::vector<int> v(m);
  for (int i=0;i<m;++i) std::cin >> v[i];
  std::sort(v.begin(), v.end());
  std::vector<bool> used(m, false);
  int x;
  std::vector<int> offset(m);
  for (int i=0;i<m;++i) offset[i]=i+1;
  while (k--) {
    std::cin >> x;
    int pos=std::upper_bound(v.begin(), v.end(), x)-v.begin();
    if (used[pos]) {
      used[offset[pos]]=true;
      std::cout << v[offset[pos]] << '\n';
      int k=offset[offset[pos]];
      while (k<m) {
        if (!used[k]) break;
        k=offset[k];
      }
      offset[pos]=k;      
    } else {
      std::cout << v[pos] << '\n';
      used[pos]=true;
      int k=offset[pos];
      while (k<m) {
        if (!used[k]) break;
        k=offset[k];
      }
      offset[pos]=k;
    }
  }

  return 0; 
}
