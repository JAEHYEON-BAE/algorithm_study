// 12100

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

static int result[2]={0, 0};
void backtracking(int r, int c, int cnt, bool color, std::vector<std::vector<bool>> &board, std::vector<bool> &used_1, std::vector<bool> &used_2)
{
  int n=board.size();
  if (c>=n) {
    ++r;
    if (c&1) c=0;
    else c=1;
  }
  if (r>=n) {
    result[color]=std::max(result[color], cnt);
    return;
  }
  if (board[r][c] && !used_1[c-r+n-1] && !used_2[r+c]) {
    used_1[c-r+n-1]=used_2[r+c]=1;
    backtracking(r, c+2, cnt+1, color, board, used_1, used_2);
    used_1[c-r+n-1]=used_2[r+c]=0;
  }
  backtracking(r, c+2, cnt, color, board, used_1, used_2);
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<bool>> board(n, std::vector<bool>(n));
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    int x;  std::cin >> x;
    board[i][j]=x;
  }
  std::vector<bool> used_1(n<<1, 0), used_2(n<<1, 0);

  backtracking(0, 0, 0, 0, board, used_1, used_2);
  backtracking(0, 1, 0, 1, board, used_1, used_2);

  std::cout << result[0]+result[1];
  return 0;
}