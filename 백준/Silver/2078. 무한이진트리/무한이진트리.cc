// 2078

#include <iostream>
#include <vector>
#include <bitset>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

void sol(int a, int b, int& l, int &r)
{
  if (a==1 && b==1) return;
  else if (a==1) {
    r+=b-1;
    return;
  }
  else if (b==1) {
    l+=a-1;
    return;
  }
  else {
    if (a>b) {
      l+=a/b;
      sol(a%b, b, l, r);
    }
    else {
      r+=b/a;
      sol(a, b%a, l, r);
    }
  }
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b;  std::cin >> a >> b;
  int l=0, r=0;
  sol(a, b, l, r);
  std::cout << l << ' ' << r;
  
  return 0;
}