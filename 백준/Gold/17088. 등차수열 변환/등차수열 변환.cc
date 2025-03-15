// 2671

#include <iostream>
#include <vector>
#include <bitset>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  if (n==1) {
    std::cout << 0;
    return 0;
  }
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  int first[3]={v[0]-1, v[0], v[0]+1};
  int last[3]={v.back()-1, v.back(), v.back()+1};

  int min=INF;
  for (int i=0;i<3;++i) {
    for (int j=0;j<3;++j) {

      int l=first[i], r=last[j];
      if ((r-l)%(n-1)!=0) continue;
    
      int tmp=((i==1)?0:1)+((j==1)?0:1);

      int d=(r-l)/(n-1);
      for (int k=1;k<n-1;++k) {
        // KEEP GOING !
        if (abs(l+d*k - v[k])<=1) tmp+=(l+d*k==v[k])?0:1;
        else {
          tmp=INF;
          break;
        }
      }

      min=std::min(min, tmp);
    }
  }
  if (min==INF) std::cout << -1;
  else std::cout << min;
 
  return 0;
}