// 19686

#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  int k=(~0u)>>1;
  
  /* increasing */
  int breakpoint=0;
  bool result=true;
  for (int i=1;i<n;++i) {
    if (v[i-1]>v[i]) {
      if (breakpoint!=0) {
        result=false; break;
      }
      else breakpoint=i;
    }
  }
  
  if (result) {
    if (breakpoint==0) k=0;
    else if (v[n-1]<=v[0]) {
      k=std::min(k, breakpoint);
    }
  }

  /* decreasing */
  breakpoint=0;
  result=true;
  for (int i=1;i<n;++i) {
    if (v[i-1]<v[i]) {
      if (breakpoint!=0) {
        result=false; break;
      }
      else breakpoint=i;
    }
  }
  
  if (result) {
    if (breakpoint==0) k=0;
    else if (v[n-1]>=v[0]) {
      k=std::min(k, breakpoint);
    }
  }

  if (k==(~0u)>>1) std::cout << -1;
  else std::cout << k;


  return 0; 
}
