// 34676 

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::unordered_map<std::string, int> v;
  for (int i=0;i<n;++i) {
    std::string s;  std::cin >> s;
    ++v[s];

    // 1 coffee
    for (int j=0;j<9;++j) {
      auto cpy=s;
      cpy[j]='?';
      ++v[cpy];
      cpy[j]=s[j];
    }

    // 2 coffee
    for (int j=0;j<8;++j) {
      auto cpy=s;
      cpy[j]='?';
      for (int k=j+1;k<9;++k) {
        cpy[k]='?';
        ++v[cpy];
        cpy[k]=s[k];
      }
      cpy[j]=s[j];
    }

    // juice
    for (int j=0;j<9;++j) {
      for (int k=j;k<9;++k) {
        ++v[s.substr(0, j)+'*'+s.substr(k+1)];
      }
    }
  }
  
  int q;  std::cin >> q;
  while (q--) {
    std::string s;  std::cin >> s;
    std::cout << v[s] << '\n';
  }
  return 0;
}
