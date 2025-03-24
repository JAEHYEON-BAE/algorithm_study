// 11735

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long int n; int q;
  std::cin >> n >> q;
  std::vector<std::vector<bool>> zero(n+1, std::vector<bool>(2, 0));
  // zero[r][0], zero[c][1]

  char c; long long int x;
  long long int sum = n*(n+1)/2;

  long long int r_minus=0, c_minus=0;
  long long int r_num=0, c_num=0;
  while (q--) {
    std::cin >> c >> x;
    if (zero[x][(c=='R')?0:1]) std::cout << 0 << '\n';
    else if (c=='R') {
      long long int tmp = x*n+sum;
      tmp -= r_num*x + r_minus;
      std::cout << tmp << '\n';
      c_minus += x;
      ++c_num;
      zero[x][0]=1;
    }
    else {
      long long int tmp = x*n+sum;
      tmp -= c_num*x + c_minus;
      std::cout << tmp << '\n';
      r_minus += x;
      ++r_num;
      zero[x][1]=1;
    }
  }
  
  return 0;
}