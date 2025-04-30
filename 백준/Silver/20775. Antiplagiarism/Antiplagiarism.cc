// 20775

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

void ROTATE(std::vector<std::string> &c)
{
  int n=c.size();
  std::vector<std::string> tmp=c;
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    tmp[i][j]=c[n-1-j][i];
  }
  c=tmp;
}

void MIRROR(std::vector<std::string> &c) 
{
  int n=c.size();
  std::vector<std::string> tmp=c;
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    tmp[i][j]=c[n-1-i][j];
  }
  c=tmp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::string> c1(n), c2(n);
  for (int i=0;i<n;++i) std::cin >> c1[i];
  for (int i=0;i<n;++i) std::cin >> c2[i];
  
  if (c1==c2) {
    std::cout << "YES";
    return 0;
  }
  MIRROR(c1);
  if (c1==c2) {
    std::cout << "YES";
    return 0;
  }
  MIRROR(c1);

  for (int i=0;i<3;++i) {
    ROTATE(c1);
    if (c1==c2) {
      std::cout << "YES";
      return 0;
    }
    MIRROR(c1);
    if (c1==c2) {
      std::cout << "YES";
      return 0;
    }
    MIRROR(c1);
  }

  std::cout << "NO";
  return 0;
}