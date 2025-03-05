// 1373

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string bi;  std::cin >> bi;
  int n=bi.size();
  std::string result="";
  for (int i=n-1;i>=0;) {
    int tmp=0;
    tmp+=(bi[i--]=='1');
    if (i<0) {result.push_back(static_cast<char>(tmp+'0')); break;}
    tmp+=(bi[i--]=='1')<<1;
    if (i<0) {result.push_back(static_cast<char>(tmp+'0')); break;}
    tmp+=(bi[i--]=='1')<<2;
    result.push_back(static_cast<char>(tmp+'0'));    
  }
  std::reverse(result.begin(), result.end());
  std::cout << result;
  
  
  return 0;
}