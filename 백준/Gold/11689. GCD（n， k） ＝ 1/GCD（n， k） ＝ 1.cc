// 11689

#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long int n;  std::cin >> n;
  if (n==1) {
    std::cout << 1;
    return 0;
  }

  long long int result=n;
  if (n%2==0) {
    result>>=1;
    while (n%2==0) n>>=1;
  }
  if (n%3==0) {
    result=(result/3)<<1;
    while (n%3==0) n/=3;
  }
  for (int i=1;static_cast<long long int>(i)*i<=n;) {
    i+=4;
    if (n%i==0) {
      result=result/i*(i-1);
      while (n%i==0) n/=i;
    }
    i+=2;
    if (n%i==0) {
      result=result/i*(i-1);
      while (n%i==0) n/=i;
    }
  }
  
  if (n>1) result=result/n*(n-1);

  std::cout << result;  
  
  return 0;  
}
