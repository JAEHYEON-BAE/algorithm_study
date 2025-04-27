#include <iostream>
#include <vector>
#include <algorithm>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> b(n);
  std::vector<int> a(n);
  for (int i=0;i<n;++i) {
    std::cin >> b[i];
    a[i]=i+1;
  }

  for (int i=n-1;i>=0;--i) {
    for (int j=0;j<a.size();++j) b[j]^=a[j];
    a.erase(std::lower_bound(a.begin(), a.end(), b[i]));    
  }

  for (const int& x:b) std::cout << x << ' ';
  return 0;
}