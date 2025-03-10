// 14391

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::vector<int>> v(n, std::vector<int>(m));
  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    for (int j=0;j<m;++j) {
      v[i][j]=x/power10[m-j-1]%10;
    }
  }


  int max=0;
  for (int bit=0;bit<1<<(n*m);++bit) {
    // false -> horizontal, true -> vertical
    int tmp=0;
    std::bitset<16> visited(0);
    for (int i=n-1;i>=0;--i) for (int j=m-1;j>=0;--j) {
      int idx=i*m+j;
      
      if (visited[idx]) continue;
      visited.set(idx);
      
      if (bit>>idx & 1) {
        if (idx<m) tmp+=v[idx/m][idx%m];
        else {
          int size=0;
          while (bit>>idx & 1) {
            tmp+=v[idx/m][idx%m]*power10[size++];
            visited.set(idx);
            if (idx<m) break;
            idx-=m;
          }
        }
      }
      else {
        if (idx%m==0) tmp+=v[idx/m][idx%m];
        else {
          int size=0;
          while (!(bit>>idx & 1)) {
            tmp+=v[idx/m][idx%m]*power10[size++];
            visited.set(idx);
            if (idx%m==0) break;
            idx-=1;
          }
        }
      }
    }
    max=std::max(max, tmp);
  }
  std::cout << max;

  return 0;
}