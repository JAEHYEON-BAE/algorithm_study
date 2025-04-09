// 14041
#include <iostream>
#include <vector>
#include <algorithm>
// #include <iomanip>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

inline bool rush_hour(const int &time)
{
  return (time>=420 && time<600) || (time>=900 && time<1140);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string str;  std::cin >> str;
  int h=std::stoi(str.substr(0, 2));
  int m=std::stoi(str.substr(3, 2));

  int time=h*60+m;
  // rushhour: 420~600, 900~1140
  if (time+120<=420 || time>=1140 || (time>=600 && time+120<=900)) time+=120;
  else {
    int total=0;
    while (1) {
      if (rush_hour(time)) {
        total+=10;
        time+=20;
      }
      else {
        total+=20;
        time+=20;
      }

      if (total>=120) break;
    }
    // std::cout <<total << std::endl;
    if (total>=120) time-=total-120;
  }
  if (time>=1440) time-=1440;

  std::cout.width(2);
  std::cout.fill('0');
  std::cout << time/60;
  std::cout << ':';
  std::cout.width(2);
  std::cout.fill('0');
  std::cout << time%60;
  
  
  return 0;
}