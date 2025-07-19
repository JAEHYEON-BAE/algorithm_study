// 17401

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>


constexpr int MOD=1'000'000'007;

using Matrix=std::vector<std::vector<long long int>>;

Matrix mul(const Matrix &a, const Matrix &b)
{
  int n=a.size();
  Matrix result(n, std::vector<long long int>(n, 0));
  for (int i=0;i<n;++i) for (int k=0;k<n;++k) for (int j=0;j<n;++j) {
    result[i][j]=(result[i][j]+a[i][k]*b[k][j]%MOD)%MOD;
  }
  return result;
}

Matrix exp(Matrix a, int r) {
  int n=a.size();
  Matrix result(n, std::vector<long long int>(n, 0));
  for (int i=0;i<n;++i) result[i][i]=1;
  while (r) {
    if (r&1) result=mul(result, a);
    a=mul(a, a);
    r>>=1;
  }
  return result;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t, n, d;  std::cin >> t >> n >> d;

  std::vector<Matrix> map(t);
  
  for (int i=0;i<t;++i) {
    Matrix tmp(n, std::vector<long long int>(n, 0));
    int m;  std::cin >> m;
    for (int j=0;j<m;++j) {
      int a, b, c;  std::cin >> a >> b >> c;
      --a;--b;
      tmp[a][b]=c;
    }
    
    if (i) map[i]=mul(map[i-1], tmp);
    else map[i]=tmp;
  }

  
  for (auto &c:((d%t)?mul(exp(map[t-1], d/t), map[d%t-1]):exp(map[t-1], d/t))) {
    for (auto &r:c) std::cout << r << ' ';
    std::cout << '\n';
  }

  return 0;
}