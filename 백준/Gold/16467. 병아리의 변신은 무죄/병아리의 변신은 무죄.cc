// 16467
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

static constexpr int MOD=100'000'007;

std::vector<std::vector<int>> mat_mul(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b)
{
  int n=a.size();
  std::vector<std::vector<int>> result(n, std::vector<int>(n));
  for (int i=0;i<n;++i) for (int k=0;k<n;++k) for (int j=0;j<n;++j) {
    result[i][j]=(result[i][j]+1LL*a[i][k]*b[k][j]%MOD)%MOD;
  }
  return result;
}
std::vector<int> mat_mul(const std::vector<std::vector<int>> &a, const std::vector<int> &b)
{
  int n=a.size();
  std::vector<int> result(n, 0);
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    result[i]=(result[i]+1LL*a[i][j]*b[j]%MOD)%MOD;
  }
  return result;
}

std::vector<std::vector<int>> mat_power(const std::vector<std::vector<int>> &mat, int r)
{
  if (r==0) {
    std::vector<std::vector<int>> I(mat.size(), std::vector<int>(mat.size(), 0));
    for (int i=0;i<mat.size();++i) I[i][i]=1;
    return I;    
  }
  if (r==1) return mat;
  std::vector<std::vector<int>> tmp=mat_power(mat, r/2);
  if (r&1) return mat_mul(mat_mul(tmp, tmp), mat);
  else return mat_mul(tmp, tmp);
}

long long int power(int a, int r)
{
  if (r==0) return 1;
  if (r==1) return a%MOD;
  long long int tmp=power(a, r>>1)%MOD;
  if (r&1) return tmp*tmp%MOD*a%MOD;
  else return tmp*tmp%MOD;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;

  // fib[i]=fib[i-1]+fib[i-k-1]

  while (t--) {
    int k, n;  std::cin >> k >> n;
    if (k==0) {
      std::cout << power(2, n) << '\n';
      continue;
    }
    if (n<k+1) {
      std::cout << 1 << '\n';
      continue;
    }
    std::vector<int> init(k+1, 1);
    std::vector<std::vector<int>> mat(k+1, std::vector<int>(k+1, 0));
    mat[0][0]=mat[0][k]=1;
    for (int i=1;i<=k;++i) mat[i][i-1]=1;
    std::cout << mat_mul(mat_power(mat, n-k), init)[0] << '\n';
  }
  
  return 0;
}