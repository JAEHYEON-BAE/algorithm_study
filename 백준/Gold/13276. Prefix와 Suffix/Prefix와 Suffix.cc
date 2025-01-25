// 13276

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

std::vector<int> KMP(const std::string& s, const std::string& x) {
  int s_size=s.size(), x_size=x.size();
  std::vector<int> fail(x_size, 0);
  for (int i=1,j=0;i<x_size;++i) {
    while (j>0 && x[i]!=x[j]) j=fail[j-1];
    if (x[i]==x[j]) fail[i]=++j;
  }

  std::vector<int> result;
  
  for (int i=0,j=0;i<s_size;++i) {
    while (j>0 && s[i]!=x[j]) j=fail[j-1];
    if (s[i]==x[j]) {
      if (j==x_size-1) {
        result.emplace_back(i-j);
        j=fail[j];
      }
      else ++j;
    }
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s, a, b;
  std::cin >> s >> a >> b;
  int a_size=a.size(), b_size=b.size();

  std::vector<int> a_s=KMP(s, a), b_s=KMP(s, b);

  std::unordered_set<std::string> result;
  for (const int& x:a_s) for (const int& y:b_s) {
    int len = y+b_size-x;
    if (len<0 || len<a_size || len<b_size) continue;
    result.emplace(s.substr(x, len));
  }  

  std::cout << result.size();
  
  return 0; 
}
