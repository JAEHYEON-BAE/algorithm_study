// 8972

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

constexpr int dr[9]={1, 1, 1, 0, 0, 0, -1, -1, -1};
constexpr int dc[9]={-1, 0, 1, -1, 0, 1, -1, 0, 1};

int R, C;
std::vector<std::string> board;

struct Arduino
{
  int r, c;
  Arduino() {}
  Arduino(int r, int c): r(r), c(c) {}
  bool operator-(const Arduino &o) const {
    return std::abs(r-o.r)+std::abs(c-o.c);
  }
  void mv(const Arduino &t) {
    int rr, rc;
    int dist=1000;
    for (int d=0;d<9;++d) {
      int nr=r+dr[d];
      int nc=c+dc[d];
      if (nr<0 || nr>=R || nc<0 || nc>=C) continue;
      int tmp=std::abs(nr-t.r)+std::abs(nc-t.c);
      if (tmp<dist) {
        dist=tmp;
        rr=nr, rc=nc;
      }
    }
    r=rr, c=rc;
  }
  void mv(int d) {
    r+=dr[d];
    c+=dc[d];
  }
  int flatten() const {
    return r*C+c;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::cin >> R >> C;
  board.resize(R);
  std::vector<Arduino> mad;
  Arduino a;
  for (int i=0;i<R;++i) {
    std::cin >> board[i];
    for (int j=0;j<C;++j) {
      if (board[i][j]=='R') mad.push_back(Arduino(i, j));
      else if (board[i][j]=='I') a.r=i, a.c=j;
    }
  }
  int n=mad.size();
  std::vector<bool> alive(n, 1);
  std::string mv;  std::cin >> mv;
  int m=mv.size();
  for (int i=0;i<m;++i) {
    int d=mv[i]-'0'-1;
    
    board[a.r][a.c]='.';
    a.mv(d);
    if (board[a.r][a.c]=='R') {
      std::cout << "kraj " << i+1;
      return 0;
    }
    board[a.r][a.c]='I';

    std::unordered_map<int, std::vector<int>> mad_pos;
    for (int j=0;j<n;++j) if (alive[j]) {
      board[mad[j].r][mad[j].c]='.';
      mad[j].mv(a);
      mad_pos[mad[j].flatten()].push_back(j);
    }

    if (mad_pos.count(a.flatten())) {
      std::cout << "kraj " << i+1;
      return 0;
    }
    for (const auto &p:mad_pos) {
      if (p.second.size()>1) {
        for (const int &x:p.second) alive[x]=0;
      }
      else {
        board[p.first/C][p.first%C]='R';
      }
    }
  }
  for (const auto &s:board) std::cout << s << '\n';
  return 0;
}