// 25239
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string str;  std::cin >> str;
  int h=std::stoi(str.substr(0, 2));
  int m=std::stoi(str.substr(3, 2));

  std::bitset<6> sealed(0);
  int recover[6];
  for (int i=0;i<6;++i) std::cin >> recover[i];

  int n;  std::cin >> n;
  while (n--) {
    long double time;
    std::string event;
    std::cin >> time >> event;
    if (event=="^") {
      sealed[h>>1]=1;
    }
    else {
      if (event[1]=='0') {
        int x=std::stoi(event.substr(0, 2));
        m+=x;
      }
      else {
        int x=static_cast<int>(event[0]-'0');
        h+=x;
      }

      h+=m/60;
      m%=60;
      h%=12;
    }

    if (sealed==127) {
      std::cout << 0;
      return 0;
    }
  }

  int res=0;
  for (int i=0;i<6;++i) {
    if (!sealed[i]) res+=recover[i];
  }
  std::cout << (res<100?res:100);
  return 0;
}