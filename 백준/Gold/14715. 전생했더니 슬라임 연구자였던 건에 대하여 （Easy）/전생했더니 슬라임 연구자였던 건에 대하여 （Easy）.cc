// 14715

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k;  std::cin >> k;

  int cnt=0;
  for (int i=2;i*i<=k;++i) while (k%i==0) ++cnt, k/=i;
  if (k!=1) ++cnt;

  std::cout << (cnt==1?0:32-__builtin_clz(cnt-1));
  return 0;
}

