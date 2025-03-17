// 4716

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

struct Team 
{
  int k, da, db;
  int value() const {
    return da-db;
  }
  bool operator<(const Team &other) const {
    return abs(this->value()) > abs(other.value());
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, a, b;
  while (std::cin >> n >> a >> b) {
    if (n==0&&a==0&&b==0) break;
    std::vector<Team> teams(n);
    for (int i=0;i<n;++i) {
      std::cin >> teams[i].k >> teams[i].da >> teams[i].db;
    }
    std::sort(teams.begin(), teams.end());

    long long int result=0LL;

    for (const Team &team: teams) {
      // std::cout << team.k << ' ' << team.da << ' ' << team.db << ' ' << team.value() << std::endl;
      if (team.value()<0) {
        if (a>=team.k) {
          result+=static_cast<long long int>(team.k)*team.da;
          a-=team.k;
        }
        else {
          result+=static_cast<long long int>(team.k-a)*team.db;
          result+=static_cast<long long int>(a)*team.da;
          b-=(team.k-a);
          a=0;
        }
      } else {
        if (b>=team.k) {
          result+=static_cast<long long int>(team.k)*team.db;
          b-=team.k;
        }
        else {
          result+=static_cast<long long int>(team.k-b)*team.da;
          result+=static_cast<long long int>(b)*team.db;
          a-=(team.k-b);
          b=0;
        }
      }
      // std::cout << a << ' ' << b << ' ' << result << std::endl;
      // std::cout << std::endl;
    }
    
    std::cout << result << '\n';
  }

  return 0;
}