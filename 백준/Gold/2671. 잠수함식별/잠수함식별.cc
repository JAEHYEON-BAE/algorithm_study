// 2671

#include <iostream>
#include <vector>
#include <bitset>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // (100~1~|01)~
  std::string str;  std::cin >> str;
  int n=str.size();
  int i=0;
  while (i<n) {
    // std::cout << i << std::endl;
    if (i+2<n && str[i]=='1' && str[i+1]=='0' && str[i+2]=='0') {
      // PATTERN 1
      i+=3;
      if (i>=n) {std::cout << "NOISE";return 0;}
      while (i<n) {
        if (str[i]=='1') break;
        else {
          ++i;
          if (i==n) {std::cout << "NOISE";return 0;}
        }
      }
      if (i>=n) {std::cout << "NOISE";return 0;}
      while (i<n) {
        if (str[i]=='0') {
          if (i+1<n && str[i-2]=='1' && str[i-1]=='1' && str[i+1]=='0') {
            --i;
          }
          break;
        }
        else {
          ++i;
        }
      }
    }
    else if (i+1<n && str[i]=='0' && str[i+1]=='1') {
      // PATTERN 2
      i+=2;
    }
    else {
      std::cout << "NOISE";
      return 0;
    }
  }
  std::cout << "SUBMARINE";
  return 0;
}