// 14905

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

static int FLAG=0;

void DFS(int depth, int sum, const int &n, std::vector<int> &path, int tmp, const std::vector<int> &primes, const std::vector<bool> &is_prime)
{
  if (FLAG) return;
  
  if (depth==4) {
    if (sum==n) {
      for (const int &x:path) std::cout << x << ' ';
      FLAG=1;
    }
    return;
  }

  if (depth==3 && n>sum && is_prime[n-sum]) {
    path[3]=n-sum;
    for (const int &x:path) std::cout << x << ' ';
    FLAG=1;
    return;
  }

  if (sum+(3-depth)*2>n) return;

  for (int i=tmp;i<primes.size();++i) {
    if (sum+primes[i]>n) break;
    path[depth]=primes[i];
    tmp=i;
    DFS(depth+1, sum+primes[i], n, path, tmp, primes, is_prime);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::vector<bool> is_prime(100'000'001, 1);
  is_prime[0]=is_prime[1]=0;
  for (int i=2;i*i<=100'000'000;++i) {
    if (is_prime[i]) for (int j=i<<1;j<=100'000'000;j+=i) {
      is_prime[j]=0;
    }
  }

  std::vector<int> primes;
  for (int i=0;i<=100'000'000;++i) {
    if (is_prime[i]) primes.push_back(i);
  }
  
  
  int n;
  while (std::cin >> n) {
    if (n<8) {
      std::cout << "Impossible.\n";
      continue;
    }

    std::vector<int> path(4);
    FLAG=0;
    DFS(0, 0, n, path, 0, primes, is_prime);  
    std::cout << '\n';
  }
  return 0;
}