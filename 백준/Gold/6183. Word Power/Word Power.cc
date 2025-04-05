// 6183
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>1;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

void lower(char &x)
{
  if (x>='A' && x<='Z') x=x-'A'+'a';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::string> c(n), q(m);

  for (int i=0;i<n;++i) {
    std::cin >> c[i];
    for (char &x:c[i]) lower(x);
  }
  for (int i=0;i<m;++i) {
    std::cin >> q[i];
    for (char &x:q[i]) lower(x);
  }
  
  for (const std::string &str:c) {
    int cnt=0;
    for (int i=0;i<m;++i) {
      int x=0, y=0;
      bool FLAG=0;
      for (int x=0;x<str.size();++x) {
        if (str[x]==q[i][y]) ++y;
        if (y==q[i].size()) {FLAG=1; break;}
      }
      if (FLAG) ++cnt;
    }
    std::cout << cnt << '\n';
  }
 
  return 0;
}