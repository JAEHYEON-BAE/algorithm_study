// 16287

#include <iostream>
#include <vector>
#include <algorithm>

using Matrix=std::vector<std::vector<long long int>>;
static constexpr long long int MOD=1'000'003;

void mat_mul(Matrix &a, const Matrix &b)
{
  int n=a.size();
  Matrix c(n, std::vector<long long int>(n, 0));
  for (int i=0;i<n;++i) for (int k=0;k<n;++k) {
    if (a[i][k]) for (int j=0;j<n;++j) if (b[k][j]) {
      c[i][j]+=a[i][k]*b[k][j];
      c[i][j]%=MOD;
    }
  }
  a=c;
}
void mat_pow(Matrix &map, int r)
{
  int n=map.size();
  Matrix tmp(n, std::vector<long long int>(n, 0));
  for (int i=0;i<n;++i) tmp[i][i]=1;
  
  while (r) {
    if (r&1) mat_mul(tmp, map);
    mat_mul(map, map);
    r>>=1;
  }
  map=tmp;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, s, e, t;  std::cin >> n >> s >> e >> t;
  --s;--e;
  Matrix map(n*5, std::vector<long long int>(n*5, 0));
  for (int i=0;i<n;++i) {
    for (int k=1;k<5;++k) map[i*5+k][i*5+k-1]=1;
    std::string line;  std::cin >> line;
    for (int j=0;j<n;++j) {
      if (line[j]!='0') map[i*5][j*5+(line[j]-'0')-1]=1LL;
    }
  }

  mat_pow(map, t);
  std::cout << map[s*5][e*5];
  
  
  return 0;
}