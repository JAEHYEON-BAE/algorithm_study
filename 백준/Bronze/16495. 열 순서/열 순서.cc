// 16495

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

long long int power26[11];
long long int cnts[11];
void init()
{
  cnts[0]=0; cnts[1]=26;
  power26[0]=1; power26[1]=26;
  for (int i=2;i<11;++i) {
    power26[i]=power26[i-1]*26LL;
    cnts[i]=cnts[i-1]+power26[i];
  }
  return;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  init();
  std::string s;  std::cin >> s;
  long long int num=1LL;
  int n=s.size();
  num+=cnts[n-1];
  for (int i=0;i<n;++i) {
    num+=power26[n-i-1]*static_cast<long long>(s[i]-'A');
  }
  std::cout << num; 
  
  return 0;
}