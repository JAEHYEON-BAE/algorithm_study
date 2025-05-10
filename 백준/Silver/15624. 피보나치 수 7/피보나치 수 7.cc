// 15624

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<long long int> F(n+1);
  F[0]=0;
  F[1]=1;
  for (int i=2;i<=n;++i) F[i]=(F[i-1]+F[i-2])%1'000'000'007;
  std::cout << F[n];
  return 0;
}