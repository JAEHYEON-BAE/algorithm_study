// 1529

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;

using Matrix=std::vector<std::vector<ll>>;
constexpr ll MOD=1'234'567'891;

inline bool valid(int x) 
{
  while (x) {
    if (x%10!=4 && x%10!=7) return 0;
    x/=10;
  }
  return 1;
}

Matrix mat_mul(const Matrix &a, const Matrix &b)
{
  Matrix tmp={{0, 0}, {0, 0}};
  for (int i=0;i<2;++i) for (int k=0;k<2;++k) for (int j=0;j<2;++j) {
    tmp[i][j]+=a[i][k]*b[k][j]%MOD;
    tmp[i][j]%=MOD;
  }
  return tmp;
}
Matrix mat_exp(Matrix a, int r)
{
  Matrix tmp={{1, 0}, {0, 1}};
  while (r) {
    if (r&1) tmp=mat_mul(tmp, a);
    a=mat_mul(a, a);
    r>>=1;
  }
  return tmp;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, l;  std::cin >> n >> l;

  ll _44=0, _47=0, _74=0, _77=0;

  std::unordered_set<int> set;
  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    if (valid(x) && set.count(x)==0) {
      set.insert(x);

      if (std::to_string(x)[0]=='4') {
        if (x%10==4) ++_44;
        else ++_47;
      }
      else {
        if (x%10==4) ++_74;
        else ++_77;
      }
    }
  }

  Matrix m={{_44, _74}, {_47, _77}};
  m=mat_exp(m, l);

  ll f=(m[0][0]+m[0][1])%MOD;
  ll s=(m[1][0]+m[1][1])%MOD;
  
  std::cout << (f+s)%MOD;
  return 0;
}