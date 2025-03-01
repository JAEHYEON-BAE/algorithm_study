// 14404

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

int gcd(int a, int b)
{
  if (a==1 || b==1) return 1;
  while (b) {
    int t=b;
    b=a%b;
    a=t;
  }
  return a;
}

void divisor(const int x, std::unordered_set<int>& set)
{
  if (x<=0) return;
  for (int i=1;i*i<=x;++i) {
    if (x%i==0) set.insert(i), set.insert(x/i);
  }
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a, b, x;  std::cin >> a >> b >> x;
  int g=gcd(a, b);
  if (g%x==0) {
    std::cout << -1;
    return 0;
  }
  std::unordered_set<int> y;
  y.insert(1);
  divisor(g, y);
  if (a%x==0) {
    divisor(b, y);
    int tmp=x;

    while (tmp<b) {
      divisor(b-tmp, y);
      tmp+=x;
    }
  }
  else if (b%x==0) {
    divisor(a, y);
    int tmp=x;
    while (tmp<a) {
      divisor(a-tmp, y);
      tmp+=x;
    }
  }
  else {
    int tmp=x;
    int p=a/x, q=b/x;
    for (int i=0;i<=p;++i) for (int j=0;j<=q;++j) {
      divisor(gcd(a-tmp*i, b-tmp*j), y);
    }
  }
  // for (int i:y) std::cout << i << std::endl;
  // std::cout << std::endl;
  
  std::cout << y.size();
  return 0;
}