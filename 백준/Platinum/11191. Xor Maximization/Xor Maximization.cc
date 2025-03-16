// 11191

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

std::vector<long long int> basis(64, 0);

void insert(long long int x) 
{
  for (int i=63;i>=0;--i) {
    if (!(x & (1LL<<i))) continue;
    if (!basis[i]) {
      basis[i]=x;
      return;
    }
    x^=basis[i];
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  long long int x;
  for (int i=0;i<n;++i) {
    std::cin >> x;
    insert(x);
  }

  long long int result=0;
  for (int i=63;i>=0;--i) {
    result=std::max(result, result^basis[i]);
  }
  std::cout << result;
  
  return 0;
}