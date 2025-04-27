// 9815

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>1;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

int q(std::string s) 
{
  int a, b;
  std::sort(s.begin(), s.end());
  b=std::stoi(s);
  std::reverse(s.begin(), s.end());
  a=std::stoi(s);
  std::cout << a << '-' << b << '=' << a-b << '\n';
  return a-b;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string s;
  while (std::cin >> s) {
    if (s=="-1") break;

    s=std::to_string(std::stoi(s));
    std::cout << "N=" << s << ":\n";
    
    if (s.size()!=4) {
      std::cout << "No!!\n";
      continue;
    }


    char x=s[0];
    bool same=1;
    for (const char &c:s) {
      if (c!=x) {
        same=0; break;
      }
    }
    if (same) {
      std::cout << "No!!\n";
      continue;
    }

    int cnt=0;
    while (1) {
      int result=q(s);
      ++cnt;
      if (result==6174 || result==0) {
        std::cout << "Ok!! " << cnt << " times\n";
        break;
      }

      s=std::to_string(result);
    }
  }

  
  return 0;
}