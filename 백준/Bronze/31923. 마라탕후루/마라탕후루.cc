// 31923

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, p, q;  std::cin >> n >> p >> q;
  std::vector<int> a(n), b(n);
  for (int &x:a) std::cin >> x;
  for (int &x:b) std::cin >> x;

  int d=p-q;
  
  if (d==0) {
    for (int i=0;i<n;++i) if (a[i]!=b[i]) {
      std::cout << "NO";
      return 0;
    }
    std::cout << "YES\n";
    for (int i=0;i<n;++i) std::cout << "0 ";
    return 0;
  }

  std::vector<int> ans(n);
  for (int i=0;i<n;++i) {
    int k=b[i]-a[i];
    if (k%d || k/d<0 || k/d>10000) {
      std::cout << "NO";
      return 0;
    }
    ans[i]=k/d;
  }
  std::cout << "YES\n";
  for (int i=0;i<n;++i) std::cout << ans[i] << ' ';
 
  return 0;
}