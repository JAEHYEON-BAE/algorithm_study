// 15132

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int MOD=1'000'000'007;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string str;  std::cin >> str;

  std::unordered_set<char> s;
  for (const char &c:str) {
    if (c!='|' && c!='~') s.insert(c);
  }
  int n=s.size();
  
  bool neg=false;
  std::vector<bool> used(52, false);
  std::vector<bool> var(52, false);
  for (int i=0;i<str.size();++i) {
    if (str[i]=='|') continue;
    if (str[i]=='~') {
      neg=true;
      continue;
    }
    int x=('a'<=str[i] && str[i]<='z') 
          ? static_cast<int>(str[i]-'a')
          : 26+static_cast<int>(str[i]-'A');
    if (neg) {
      if (used[x] && !var[x]) {
        std::cout << (1LL<<n);
        return 0;
      }
      else {
        used[x]=true;
        var[x]=true;
      }
      neg=false;
    }
    else {
      if (used[x] && var[x]) {
        std::cout << (1LL<<n);
        return 0;
      }
      else {
        used[x]=true;
        var[x]=false;
      }
    }
  }
  std::cout << (1LL<<n)-1;
  return 0;
}