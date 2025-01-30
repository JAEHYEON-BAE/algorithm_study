// 9663
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

void solve(int column, std::vector<int> &map, int &cnt, const int &n) 
{
  if (column==n) {++cnt;return;}
  for (int i=0;i<n;++i) {
    map[column]=i;
    bool valid=true;
    for (int j=0;j<column;++j) {
      if (map[column]==map[j] || column-j==abs(map[column]-map[j])) {valid=false;break;}
    }
    if (valid) solve(column+1, map, cnt, n);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> map(n);
  int cnt=0;
  solve(0, map, cnt, n);
  std::cout << cnt;
  
  return 0; 
}
