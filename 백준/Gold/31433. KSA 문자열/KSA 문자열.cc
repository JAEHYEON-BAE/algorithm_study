// 31433

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF = (~0u) >> 2;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string str; std::cin >> str;
  if (str.size()==1) {
    if (str=="K") {std::cout << 0;return 0;}
    else {std::cout << 2;return 0;}
  } 
  else if (str.size()==2) {
    if (str[0]=='K') {
      if (str[1]=='S') {std::cout << 0;return 0;}
      else {std::cout << 2;return 0;}
    }
    else if (str[0]=='S') {
      std::cout << 2;return 0;
    } 
    else {
      if (str[1]=='K') {std::cout << 2;return 0;}
      else {std::cout << 4;return 0;}
    }
  }

  
  int idx=0;
  int cnt=0;
  if (str[0]=='K') { 
    for (const char &c: str) {
      if (idx==0 && c=='K') ++idx;
      else if (idx==1 && c=='S') ++idx;
      else if (idx==2 && c=='A') ++idx;
      else ++cnt;
      idx%=3;
    }
  } else if (str[0]=='S') {
    for (const char &c: str) {
      if (idx==0 && c=='S') ++idx;
      else if (idx==1 && c=='A') ++idx;
      else if (idx==2 && c=='K') ++idx;
      else ++cnt;
      idx%=3;
    }
  } else {
    for (const char &c: str) {
      if (idx==0 && c=='A') ++idx;
      else if (idx==1 && c=='K') ++idx;
      else if (idx==2 && c=='S') ++idx;
      else ++cnt;
      idx%=3;
    }
  }

  std::cout << 2*cnt;

  return 0;
}