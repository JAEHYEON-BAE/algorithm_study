// 16924

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::bitset<100>> board(n, 0), result(n, 0);
  for (int i=0;i<n;++i) {
    std::string line;  std::cin >> line;
    for (int j=0;j<m;++j) if (line[j]=='*') board[i][j]=1;
  }

  std::vector<std::tuple<int, int, int>> answer;

  for (int size=(std::min(n, m)+1)>>1;size>=1;--size) {
    for (int i=size;i<n-size;++i) for (int j=size;j<m-size;++j) if (board[i][j]) {
      bool FLAG=1;
  
      for (int k=i-size;k<=i+size;++k) if (!board[k][j]) {
        FLAG=0;
        break;
      }
  
      if (!FLAG) continue;
  
      for (int k=j-size;k<=j+size;++k) if (!board[i][k]) {
        FLAG=0;
        break;
      }
  
      if (FLAG) {
        bool ALREADY_DONE=1;
        for (int k=i-size;k<=i+size;++k) {
          if (!result[k][j]) ALREADY_DONE=0;
          result[k][j]=1;
        }
        for (int k=j-size;k<=j+size;++k) {
          if (!result[i][k]) ALREADY_DONE=0;
          result[i][k]=1;
        }

        if (!ALREADY_DONE) answer.emplace_back(i, j, size);
      }
    }
  }

  if (board==result) {
    std::cout << answer.size() << '\n';
    for (const auto &[x, y, s]:answer) {
      std::cout << x+1 << ' ' << y+1 << ' ' << s << '\n';
    }
  }
  else std::cout << "-1";

  return 0;
}