// 5175

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <sstream>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

bool bit_sort(int a, int b) 
{
  int x=__builtin_popcount(a);
  int y=__builtin_popcount(b);
  if (x==y) return a<b;
  return x<y;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int k;  std::cin >> k;
  for (int tc=1;tc<=k;++tc) {
    int m, n;  std::cin >> m >> n;
    std::vector<int> v(n);
    std::cin.ignore();
    for (int i=0;i<n;++i) {
      std::string line;  std::getline(std::cin, line);
      std::stringstream iss(line);

      int x;
      while (iss >> x) v[i]|=1<<(x-1);
    }
    // for (int x:v) std::cout << x << ' ';std::cout <<std::endl;

    std::vector<int> bsv((1<<n)-1);
    for (int i=0;i<(1<<n)-1;++i) bsv[i]=i+1;
    std::sort(bsv.begin(), bsv.end(), bit_sort);

    for (int bs:bsv) {
      int tmp=0;
      for (int i=0;i<n;++i) {
        if (bs&(1<<i)) tmp|=v[i];
      }
      if (tmp==(1<<m)-1) {
        std::cout << "Data Set " << tc << ':';
        for (int i=0;i<n;++i) {
          if (bs&(1<<i)) std::cout << ' ' << (char)('A'+i);
        }
        std::cout << '\n' << '\n';
        break;
      }
    }

    
  }
  return 0;
}