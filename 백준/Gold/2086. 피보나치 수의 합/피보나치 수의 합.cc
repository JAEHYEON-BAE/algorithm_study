// 2086
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr long long int MOD=1'000'000'000;

std::array<std::array<long long int, 2>, 2> mat_mul(const std::array<std::array<long long int, 2>, 2> &a, const std::array<std::array<long long int, 2>, 2> &b)
{
  std::array<std::array<long long int, 2>, 2> result = {{ {{0, 0}}, {{0, 0}} }};
  for (int i=0;i<2;++i) for (int k=0;k<2;++k) for (int j=0;j<2;++j) result[i][j]=(result[i][j]+a[i][k]*b[k][j]%MOD)%MOD;
  return result;
}

std::array<std::array<long long int, 2>, 2> mat_power(std::array<std::array<long long int, 2>, 2> a, long long int n) {
  if (n==0) return {{ {{1, 0}}, {{0, 1}} }};
  if (n==1) return a;

  std::vector<bool> bits;
  long long int tmp = n;
  while (tmp>0) {
    bits.push_back(tmp&1);
    tmp>>=1;
  }

  std::array<std::array<long long int, 2>, 2> result = a;
  for (int i=bits.size()-2;i>=0;--i) {
    result=mat_mul(result, result);
    if (bits[i]) result=mat_mul(result, a);
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  long long int a, b;  std::cin >> a >> b;

  std::array<std::array<long long int, 2>, 2> m={{ {{1, 1}}, {{1, 0}} }};

  long long int r=mat_power(m, b+1)[0][0]%MOD;
  long long int l=mat_power(m, a)[0][0]%MOD;
  std::cout << (r-l+MOD)%MOD;
  
  return 0;
}