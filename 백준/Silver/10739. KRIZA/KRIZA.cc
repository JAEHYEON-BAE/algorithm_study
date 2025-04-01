// 10739
#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>1;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long long n, k, ans = 0;
  std::cin >> n >> k;
  std::vector<long long int> pos(n);
  for(int i=0;i<n;++i){
    int tmp; std::cin >> tmp;
    pos[tmp-1]=i;
  }
  for(int i=0;i<n;++i) {
    ans+=((pos[i]-pos[(i-1+n)%n]+n)%n)*(k/n+(i<k%n));
  }
  std::cout << ans - ((pos[0]-pos[n-1]+n)%n) + pos[0];
}