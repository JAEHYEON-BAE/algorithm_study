// 2036

#include <iostream>
#include <vector>
#include <algorithm>
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
  std::vector<long long int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];
  std::sort(v.begin(), v.end());
  long long int score=0;
  for (int i=n-1;i>=0;--i) {
    if (v[i]>1) {
      if (i-1>=0 && v[i-1]>1) {
        score+=v[i]*v[i-1];
        --i;
      } 
      else score+=v[i];
    }
    else if (v[i]==1) score+=1;
    else break;
  }

  for (int i=0;i<n;++i) {
    if (v[i]<0) {
      if (i+1<n && v[i+1]<=0) {
        score+=v[i]*v[i+1];
        ++i;
      }
      else score+=v[i];
    }
    else break;
  }
  std::cout << score;
 
  return 0;
}