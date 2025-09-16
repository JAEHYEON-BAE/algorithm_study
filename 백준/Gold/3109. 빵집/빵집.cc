// 3109

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

/* INPUT */
#define INPUT_BUFFER_SIZE (1<<20)

char get()
{
  static char buf[INPUT_BUFFER_SIZE], *S=buf, *T=buf;
  if (S==T) {
    T=(S=buf)+fread(buf, 1, INPUT_BUFFER_SIZE, stdin);
    if (S==T) return EOF;
  }
  return *S++;
}
void read(int &x)
{
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}
void read(long long int &x)
{
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}
void read(std::string &s, int size=0)
{
  static char c; s="";
  if (size) s.reserve(size);
  for (c=get();c<'!';c=get());
  for (;c>='!';c=get()) s+=c;
}

constexpr int dr[3]={-1, 0, 1};

bool DFS(int r, int c, std::vector<std::string> &board) {
  if (c+1==board[0].size()) return 1;

  for (int d=0;d<3;++d) {
    int nr=r+dr[d];
    int nc=c+1;
    if (nr<0 || nr>=board.size() || board[nr][nc]=='x') continue;
    board[nr][nc]='x';
    if (DFS(nr, nc, board)) return 1;
  }
  return 0;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int r, c;  read(r), read(c);
  std::vector<std::string> board(r);
  for (auto &x:board) read(x);

  int cnt=0;
  for (int i=0;i<r;++i) {
    board[i][0]='x';
    if (DFS(i, 0, board)) ++cnt;
  }
  std::cout << cnt;
  return 0;
}