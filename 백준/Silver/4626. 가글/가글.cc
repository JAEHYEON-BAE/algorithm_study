// 1410

#include <iostream>
#include <vector>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  for (int k=1;k<=t;++k) {
    int n, d, b, e; std::cin >> n >> d >> b >> e;
    std::cout << "Problem set " << k << ": " << n << " / " << d << ", base 7 digits " << b << " through " << e << ": ";
    n=n%d;
    std::string result="";

    for (int i=0;i<=e;++i) {
      n=n*7;
      if (i>=b) result+='0'+(n/d);
      n%=d;
    }
    std::cout << result << '\n';
  }
  
  return 0;
}

