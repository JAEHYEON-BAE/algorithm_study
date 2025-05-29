// 18382

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

template <typename T>
inline void print_v(const std::vector<std::vector<T>> &v)
{
  for (auto x:v) {
    for (auto y:x) std::cout << y << ' ';
    std::cout << '\n';
  }
  std::cout << std::endl;
  return;
}
template <typename T, size_t N>
inline void print_v(const T (&v)[N][N])
{
  for (int i=0;i<N;++i) {
    for (int j=0;j<N;++j) std::cout << v[i][j] << ' ';
    std::cout << '\n';
  }
  std::cout << std::endl;
}

static int result=0;

void up(int (&board)[16])
{
  for (int c=0;c<4;++c) {
    std::queue<int> q;
    for (int r=0;r<4;++r) {
      if (board[(r<<2)+c]) q.push(board[(r<<2)+c]);
      board[(r<<2)+c]=0;
    }
    bool dirty[4]={0, 0, 0, 0};
    int r=0;
    while (!q.empty()) {
      int idx=(r<<2)+c;
      if (r>0 && board[idx-4]==q.front() && !dirty[r-1]) {
        board[idx-4]<<=1;
        result+=board[idx-4];
        dirty[r-1]=1;
      }
      else board[idx]=q.front(), ++r;
      q.pop();
    }
  }
}
void down(int (&board)[16])
{
  for (int c=0;c<4;++c) {
    std::queue<int> q;
    for (int r=3;r>=0;--r) {
      if (board[(r<<2)+c]) q.push(board[(r<<2)+c]);
      board[(r<<2)+c]=0;
    }
    bool dirty[4]={0, 0, 0, 0};
    int r=3;
    while (!q.empty()) {
      int idx=(r<<2)+c;
      if (r<3 && board[idx+4]==q.front() && !dirty[r+1]) {
        board[idx+4]<<=1;
        result+=board[idx+4];
        dirty[r+1]=1;
      }
      else board[idx]=q.front(), --r;
      q.pop();
    }
  }
}
void left(int (&board)[16])
{
  for (int r=0;r<4;++r) {
    std::queue<int> q;
    for (int c=0;c<4;++c) {
      if (board[(r<<2)+c]) q.push(board[(r<<2)+c]);
      board[(r<<2)+c]=0;
    }
    bool dirty[4]={0, 0, 0, 0};
    int c=0;
    while (!q.empty()) {
      int idx=(r<<2)+c;
      if (c>0 && board[idx-1]==q.front() && !dirty[c-1]) {
        board[idx-1]<<=1;
        result+=board[idx-1];
        dirty[c-1]=1;
      }
      else board[idx]=q.front(), ++c;
      q.pop();
    }
  }
}
void right(int (&board)[16])
{
  for (int r=0;r<4;++r) {
    std::queue<int> q;
    for (int c=3;c>=0;--c) {
      if (board[(r<<2)+c]) q.push(board[(r<<2)+c]);
      board[(r<<2)+c]=0;
    }
    bool dirty[4]={0, 0, 0, 0};
    int c=3;
    while (!q.empty()) {
      int idx=(r<<2)+c;
      if (c<3 && board[idx+1]==q.front() && !dirty[c+1]) {
        board[idx+1]<<=1;
        result+=board[idx+1];
        dirty[c+1]=1;
      }
      else board[idx]=q.front(), --c;
      q.pop();
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);
  
  int score;  std::cin >> score;
  std::string cmd;  std::cin >> cmd;
  int board[16]={};
  for (int i=0;i<16;++i) std::cin >> board[i];
  int n=cmd.size()>>2;
  for (int i=0;i<n;++i) {
    char c=cmd[i<<2];
    if (c=='L') left(board);
    else if (c=='U') up(board);
    else if (c=='R') right(board);
    else down(board);

    int idx=(static_cast<int>(cmd[(i<<2)+2]-'0')<<2)+static_cast<int>(cmd[(i<<2)+3]-'0');
    board[idx]=static_cast<int>(cmd[(i<<2)+1]-'0');
  }
  std::cout << score+result;

  
  return 0;
}