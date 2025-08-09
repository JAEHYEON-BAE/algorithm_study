// 12188

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

constexpr int dr[8]={-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int dc[8]={0, 1, 1, 1, 0, -1, -1, -1};
constexpr int knight_dr[8]={-2, -1, 1, 2, 2, 1, -1, -2};
constexpr int knight_dc[8]={1, 2, 2, 1, -1, -2, -2, -1};

inline bool OOB(int r, int c)
{
  return r<0 || r>=8 || c<0 || c>=8;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int T;  std::cin >> T;
  for (int t=1;t<=T;++t) {
    int n;  std::cin >> n;

    std::array<std::array<char, 8>, 8> board;
    for (auto &r:board) for (char &c:r) c='.';
    for (int i=0;i<n;++i) {
      std::string line;  std::cin >> line;
      int r=line[0]-'A', c=line[1]-'1';
      board[r][c]=line.back();
    }

    if (n==1) {
      std::cout << "Case #" << t << ": 0\n";
      continue;
    }

    int cnt=0;
    for (int r=0;r<8;++r) for (int c=0;c<8;++c) {
      const char &id=board[r][c];
      if (id=='.') continue;
      else if (id=='K') {
        for (int d=0;d<8;++d) {
          int _r=r+dr[d], _c=c+dc[d];
          if (OOB(_r, _c)) continue;
          if (board[_r][_c]!='.') ++cnt;
        }
      } else if (id=='Q') {
        for (int d=0;d<8;++d) {
          int _r=r+dr[d], _c=c+dc[d];
          while (!OOB(_r, _c)) {
            if (board[_r][_c]!='.') {
              ++cnt;
              break;
            }
            _r+=dr[d], _c+=dc[d];
          }
        }
      } else if (id=='R') {
        for (int d=0;d<8;d+=2) {
          int _r=r+dr[d], _c=c+dc[d];
          while (!OOB(_r, _c)) {
            if (board[_r][_c]!='.') {
              ++cnt;
              break;
            }
            _r+=dr[d], _c+=dc[d];
          }
        }
      } else if (id=='B') {
        for (int d=1;d<8;d+=2) {
          int _r=r+dr[d], _c=c+dc[d];
          while (!OOB(_r, _c)) {
            if (board[_r][_c]!='.') {
              ++cnt;
              break;
            }
            _r+=dr[d], _c+=dc[d];
          }
        }
      } else if (id=='N') {
        for (int d=0;d<8;++d) {
          int _r=r+knight_dr[d], _c=c+knight_dc[d];
          if (OOB(_r, _c)) continue;
          if (board[_r][_c]!='.') ++cnt;
        }
      } else if (id=='P') {
        if (!OOB(r+1, c+1) && board[r+1][c+1]!='.') ++cnt;
        if (!OOB(r+1, c-1) && board[r+1][c-1]!='.') ++cnt;
      } else assert(!"INVALID ID");
    }

    std::cout << "Case #" << t << ": " << cnt << '\n';
  }
  
  return 0;
}
