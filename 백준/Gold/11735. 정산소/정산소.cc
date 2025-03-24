// 11735

#include <iostream>
#include <vector>
#include <unordered_set>

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

  std::unordered_set<int> r_set, c_set;

  char c; long long int x;
  long long int sum = n*(n+1)/2;

  long long int r_minus=0, c_minus=0;
  long long int r_num=0, c_num=0;
  while (q--) {
    std::cin >> c >> x;
    if (c=='R') {
      if (r_set.find(x)!=r_set.end()) {
        std::cout << 0 << '\n';
        continue;
      }
      
      long long int tmp = x*n+sum;
      tmp -= r_num*x + r_minus;
      std::cout << tmp << '\n';
      c_minus += x;
      ++c_num;
      r_set.insert(x);
    }
    else {
      if (c_set.find(x)!=c_set.end()) {
        std::cout << 0 << '\n';
        continue;
      }
      
      long long int tmp = x*n+sum;
      tmp -= c_num*x + c_minus;
      std::cout << tmp << '\n';
      r_minus += x;
      ++r_num;
      c_set.insert(x);
    }
  }
  
  return 0;
}