// 1786

#include <iostream>
#include <vector>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  std::string str;  std::cin >> str;

  int result=-1;
  for (size_t i=0;i<str.size();++i) {
    size_t tmp = i;
    int len=0;
    for (size_t j=tmp+1;j<str.size();) {
      // std::cout << i << ' ' << j << ' ';
      if (str[i]!=str[j]) {
        if (len==0) ++j;
        else {
          j=j-(i-tmp)+1;
          i=tmp;
          result=(result>len)?result:len;
          len=0;
        }
      }
      else ++i, ++j, ++len;
      // std::cout << len << std::endl;
    }
    i=tmp;
    result = (result>len)? result: len;
  }

  std::cout << result;
  return 0; 
}
