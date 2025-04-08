// 14238
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

bool dp[51][51][51][4][4];
char result[51];

bool recur(int _a, int _b, int _c, int p, int pp, const int &a, const int &b, const int &c)
{
  if (_a==a && _b==b && _c==c) return 1;
  if (dp[_a][_b][_c][p][pp]) return 0;
  dp[_a][_b][_c][p][pp]=1;

  if (_a<a) {
    result[_a+_b+_c]='A';
    if (recur(_a+1, _b, _c, 1, p, a, b, c)) return 1;
  }

  if (_b<b) {
    result[_a+_b+_c]='B';
    if (p!=2 && recur(_a, _b+1, _c, 2, p, a, b, c)) return 1;
  }

  if (_c<c) {
    result[_a+_b+_c]='C';
    if (p!=3 && pp!=3 && recur(_a, _b, _c+1, 3, p, a, b, c)) return 1;
  }

  return 0;
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string s;  std::cin >> s;
  int a=0, b=0, c=0;
  for (const char &x:s) {
    if (x=='A') ++a;
    else if (x=='B') ++b;
    else ++c;
  }

  int n=s.size();
  if (b>(n+1)>>1) {std::cout << -1; return 0;}
  if (c>(n+2)/3) {std::cout << -1; return 0;}

  if (recur(0, 0, 0, 0, 0, a, b, c)) {
    for (int i=0;i<n;++i) std::cout << result[i];
  }
  else std::cout << -1;

  return 0;
}