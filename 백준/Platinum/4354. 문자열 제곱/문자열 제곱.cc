// 4354

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

std::vector<int> KMP(const std::string &s)
{
  int n=s.size();
  std::vector<int> fail(n, 0);
  for (int i=1;i<n;++i) {
    int j=fail[i-1];
    while (j>0 && s[i]!=s[j]) j=fail[j-1];
    if (s[i]==s[j]) ++j;
    fail[i]=j;
  }
  return fail;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string line;
  while (std::cin >> line) {
    if (line==".") break;
    std::vector<int> fail=KMP(line);
    int n=line.size();
    int x=n-fail[n-1];
    if (n%x==0) std::cout << n/x << '\n';
    else std::cout << "1\n";
  }

  return 0;
}