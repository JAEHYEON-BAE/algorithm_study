// 32124

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, p; std::string s;
  std::cin >> n >> p >> s;

  std::string res="(";
  for (const char &c:s) {
    if (c=='(') res+="((";
    else if (c==')') res+="))";
    else if (c=='+') res+=")+(";
    else res+=c;
  }
  res+=')';
  std::cout << res.size() << '\n' << res;
  
  return 0;
}

