// 1112

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;

inline std::pair<int, int> mod(int x, int y)
{
  if (x==0) return {0, 0};
  int q=x/y, r=x%y;
  if (r>=0) {
    return {q, r};
  }
  else {
    int tmp=abs(y)+r;
    return {q+1, tmp};
  }
}

void form(int x, const int &b) 
{
  std::string answer="";
  if (x<0 && b>0) {
    x*=-1;
    while (x) {
      std::pair<int, int> tmp=mod(x, b);
      answer.push_back(static_cast<char>('0'+tmp.second));
      x=tmp.first;
    }
    std::reverse(answer.begin(), answer.end());
    std::cout << '-' << answer;
    return;
  }
  else {
    while (x) {
      std::pair<int, int> tmp=mod(x, b);
      answer.push_back(static_cast<char>('0'+tmp.second));
      x=tmp.first;
    }
    std::reverse(answer.begin(), answer.end());
    std::cout << answer;
    return;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int x, b;  std::cin >> x >> b;
  if (x==0) {
    std::cout << 0; return 0;
  }

  form(x, b);
  return 0; 
}