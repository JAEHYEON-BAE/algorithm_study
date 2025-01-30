// 19686

#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<int> v(n, 1);
  for (int i=0;i<m;++i) {
    int a, b, c; std::cin >> a >> b >> c;
    --a, --b;
    if (v[a]<c) v[a]=c;
    if (v[b]<c) v[b]=c;
  }
  for (int& x:v) std::cout << x << ' ';
  
  return 0; 
}
