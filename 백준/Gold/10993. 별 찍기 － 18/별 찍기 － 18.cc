// 10993

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

void recur(int x, int r, int c, std::vector<std::vector<char>> &picture)
{
  if (x==0) return;
  int size=(1<<x)-1;
  if (x&1) {
    for (int i=0;i<size;++i) {
      picture[r+i][c-i]=picture[r+i][c+i]='*';
    }
    for (int i=c-size+1;i<c+size-1;++i) {
      picture[r+size-1][i]='*';
    }
    recur(x-1, r+(size>>1), c, picture);
  }
  else {
    for (int i=c-size+1;i<c+size-1;++i) {
      picture[r][i]='*';
    }
    for (int i=0;i<size;++i) {
      picture[r+i][c+i-size+1]=picture[r+i][c-i+size-1]='*';
    }
    recur(x-1, r+1, c, picture);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<char>> picture((1<<n)-1, std::vector<char>((1<<(n+1))-3, ' '));
  
  int height=(1<<n)-1;
  int mid=(((1<<(n+1))-2)>>1)-1;
  
  recur(n, 0, mid, picture);

  if (n&1) {
    for (int i=0;i<height;++i) {
      for (int j=0;j<=mid+i;++j) std::cout << picture[i][j];
      std::cout << '\n';
    }
  }
  else {
    for (int i=0;i<height;++i) {
      for (int j=0;j<(1<<(n+1))-3-i;++j) std::cout << picture[i][j];
      std::cout << '\n';
    }
  }
  
  return 0;
}