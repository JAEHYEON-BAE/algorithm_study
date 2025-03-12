// 7656

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

  std::string word;
  bool q=false;

  std::string buf;
  while (std::cin >> word) {
    if (!q && word=="What") {
      std::cin >> word;
      if (word=="is") {
        q=true;
        buf+="Forty-two is ";
      }
      else if (word=="is?") {
        q=false;
        std::cout << "Forty-two is.\n";
        buf.clear();
      }
      else {
        buf.clear();
        q=false;
      }
    }
    else if (q) {
      if (word.back()=='.') {
        q=false;
        buf.clear();
      }
      else if (word.back()=='?') {
        word.pop_back();
        std::cout << buf << word << '.' << '\n';
        q=false;
        buf.clear();
      }
      else buf+=(word+' ');
    }
  }
 
  return 0;
}