// 1039
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::array<std::array<char, 3>, 3> answer, guess;
  std::array<int, 26> cnt={};
  
  for (int i=0;i<3;++i) for (int j=0;j<3;++j) {
    std::cin >> answer[i][j];
    ++cnt[answer[i][j]-'A'];
  }
  int green=0;
  int yellow=0;
  for (int i=0;i<3;++i) for (int j=0;j<3;++j) {
    std::cin >> guess[i][j];
    if (answer[i][j]==guess[i][j]) {
      ++green;
      --cnt[answer[i][j]-'A'];
    }
  }
  for (int i=0;i<3;++i) for (int j=0;j<3;++j) {
    if (answer[i][j]!=guess[i][j] && cnt[guess[i][j]-'A']) {
      ++yellow;
      --cnt[guess[i][j]-'A'];
    }
  }

  std::cout << green << '\n' << yellow;
  return 0;
}