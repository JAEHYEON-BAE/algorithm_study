// 6884
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>1;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

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
  
  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    std::vector<int> v(n);
    for (int i=0;i<n;++i) std::cin >> v[i];

    int shortest=INF;
    int start=-1;
    for (int i=0;i<n-1;++i) {
      int sum=v[i], cnt=1;
      for (int j=i+1;j<n;++j) {
        sum+=v[j];
        ++cnt;
        if (is_prime[sum] && cnt<shortest) {
          start=i;
          shortest=cnt;
        }
      }
    }

    if (shortest<INF) {
      std::cout << "Shortest primed subsequence is length " << shortest << ": ";
      for (int i=0;i<shortest;++i) std::cout << v[start+i] << ' ';
      std::cout << '\n';
    }
    else {
      std::cout << "This sequence is anti-primed.\n";
    }
  }
  return 0;
}