// 7365
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>1;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int a[3], b[7];

struct Ratio
{
  std::string r;
  int x, y;
  Ratio(int x, int y): x(x), y(y) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << static_cast<long double>(a[x])/b[y]; 
    r=ss.str();
  }
  bool operator<(const Ratio& other) const {
    if (r==other.r) return x<other.x;
    return r<other.r;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2] >> b[3] >> b[4] >> b[5] >> b[6];


  std::vector<Ratio> k;
  for (int i=0;i<3;++i) for (int j=0;j<7;++j) {
    k.push_back(Ratio(i, j));
  }

  std::sort(k.begin(), k.end());
  for (const Ratio& x:k) {
    std::cout << x.r << ' ' << x.x+1 << ' ' << x.y+1 << '\n';
  }
}