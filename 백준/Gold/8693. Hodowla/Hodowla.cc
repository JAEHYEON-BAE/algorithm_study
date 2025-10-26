// 8693

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

  int n;  std::cin >> n;
  std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) std::cin >> v[i][j];

  int m;  std::cin >> m;
  std::vector<std::vector<int>> d(n, std::vector<int>(n, 0));
  for (int _=0;_<m;++_) {
    int c1, r1, c2, r2;  std::cin >> c1 >> r1 >> c2 >> r2;
    --r1, --c1, --r2, --c2;
    // std::cout << r1 << ' ' << c1 << '\t' << r2 << ' ' << c2 << '\n';

    ++d[r1][c1];
    if (c2+1<n) --d[r1][c2+1];
    if (r2+1<n) --d[r2+1][c1]; 
    if (r2+1<n && c2+1<n) ++d[r2+1][c2+1];
  }

  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    if (i) d[i][j]+=d[i-1][j];
    if (j) d[i][j]+=d[i][j-1];
    if (i && j) d[i][j]-=d[i-1][j-1];
    
    if (d[i][j]&1) d[i][j]=1;
    else d[i][j]=0;
    // std::cout << d[i][j] << ' ';
  }

  for (int i=0;i<n;++i) {
    for (int j=0;j<n;++j) std::cout << (v[i][j]^d[i][j]) << ' ';
    std::cout << '\n';
  }
  
  
  return 0;
}