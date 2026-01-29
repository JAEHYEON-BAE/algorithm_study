// 4378

#include <iostream>
#include <vector>
#include <string>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

std::vector<std::vector<char>> keyboard={
  {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
  {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
  {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''},
  {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'}
}; 

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::vector<int> row(256, -1), col(256, -1);
  for (int i=0;i<4;++i) for (int j=0;j<keyboard[i].size();++j) {
    const char &c=keyboard[i][j];

    row[c]=i;
    col[c]=j;
  }
  std::string s;
  while (std::getline(std::cin, s)) {
    for (char &c:s) {
      if (c==' ') std::cout << ' ';
      else {
        std::cout << keyboard[row[c]][col[c]-1];
      }
    }
    std::cout << '\n';
  }
  
  return 0;
}
