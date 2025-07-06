#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string buf;
  std::string tmp="";
  int n;  std::cin >> n;
  while (n--) {
    tmp+='*';
    buf.append(tmp+'\n');
  }
  std::cout << buf;

  return 0;
}