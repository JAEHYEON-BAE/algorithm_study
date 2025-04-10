// 30021
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  int sum=(n*(n+1))>>1;

  std::vector<bool> is_prime(sum+1, 1);
  is_prime[0]=is_prime[1]=0;
  for (int i=0;i*i<=sum;++i) {
    if (is_prime[i]) for (int j=i<<1;j<=sum;j+=i) {
      is_prime[j]=0;
    }
  }
  
  std::vector<bool> visited(n+1, 0);
  std::vector<int> seq;
  int tmp=0;
  for (int _=0;_<n;++_) {
    bool FLAG=1;
    for (int i=1;i<=n;++i) {
      if (visited[i] || is_prime[tmp+i]) continue;
      visited[i]=1;
      tmp+=i;
      seq.push_back(i);
      FLAG=0;
      break;
    }
    if (FLAG) {
      std::cout << "NO";
      return 0;
    }
  }
  std::cout << "YES\n";
  for (const int &x:seq) std::cout << x << ' ';
  return 0;
}