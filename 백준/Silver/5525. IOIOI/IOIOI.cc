// 5525

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m; std::string s;
  std::cin >> n >> m >> s;

  bool x=1;
  int length=0, cnt=0;
  for (int i=0;i<m;++i) {
    if ((x && s[i]=='I') || (!x && s[i]=='O')) {
      x^=1;
      ++length;
    }
    else {
      // DEBUG(i), DEBUG(length), DEBUG((length+1)/2-n);
      // std::cout << '\n';
      if (length>=n*2+1) cnt+=(length+1)/2-n;
      x=1;
      length=0;
      if (s[i]=='I') --i;
    }
  }

  if (length>=n*2+1) cnt+=(length+1)/2-n;
  std::cout << cnt;
  return 0;
}