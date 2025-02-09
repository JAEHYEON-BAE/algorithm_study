// 1112

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::string line;
  std::vector<int> row(n, 0), col(m, 0);
  for (int i=0;i<n;++i) {
    std::cin >> line;
    for (int j=0;j<m;++j) {
      if (line[j]=='1') {
        ++row[i];
        ++col[j];
      }
    }
  }
  int r=0, c=0;
  for (int i=0;i<n;++i) r+=row[i]%2;
  for (int j=0;j<m;++j) c+=col[j]%2;

  if (r%2==0 && c%2==0) std::cout << std::min(r+c, n-r+m-c);
  else if (r%2 && c%2) std::cout << std::min(r+m-c, c+n-r);
  else std::cout << -1;

  return 0; 
}