// 26216

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string notes, inputs;
  std::cin >> notes >> inputs;
  std::vector<int> n, in;
  for (int i=0;i<notes.size();++i) {
    if (notes[i]=='!') n.back()=10-n.back();
    else if (notes[i]=='W') n.emplace_back(8);
    else if (notes[i]=='A') n.emplace_back(4);
    else if (notes[i]=='S') n.emplace_back(2);
    else if (notes[i]=='D') n.emplace_back(6);
    else {
      if (notes[i]=='L') {
        if (notes[i+1]=='U') n.emplace_back(7);
        else n.emplace_back(1);
      }
      else {
        if (notes[i+1]=='U') n.emplace_back(9);
        else n.emplace_back(3);
      }
      ++i;
    }
  }
  for (const char &c: inputs) {
    if (c=='W') in.emplace_back(8);
    else if (c=='A') in.emplace_back(4);
    else if (c=='S') in.emplace_back(2);
    else if (c=='D') in.emplace_back(6);
    else in.emplace_back(static_cast<int>(c-'0'));
  }

  int lv=n.size();
  int j=0;
  for (int i=0;i<in.size();++i) {
    if (j==lv) {
      j=0;
    }
    else if (in[i]==n[j]) {
      ++j;
    } else {
      j=0;
    }
  }
  std::cout << ((j==lv)?"Yes":"No");
  
  return 0;
}