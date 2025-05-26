// 2098

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <set>

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
template <typename T>
inline void print_set(const std::set<T> &pq)
{
  for (const T &x:pq) std::cout << x << ' ';
  std::cout << std::endl;
}


std::set<int> cand[9][9];

struct Blank
{
  int r, c;
  Blank(int r, int c): r(r), c(c) {}
  bool operator<(const Blank &o) const {
    if (r==o.r) return c>o.c;
    return r>o.r;
  }
  std::set<int>& candidate() const {
    return cand[r][c];
  }
};


bool solve(int num, std::vector<Blank> &blanks, int (&board)[9][9]) 
{
  if (num>=blanks.size()) return 1;
  int r=blanks[num].r, c=blanks[num].c;
  std::set<int> can=blanks[num].candidate();

  // std::cout << r << ' ' << c << '\n';
  // print_set(can);
  
  for (const int &x:can) {
    // 후보 백업 저장
    std::vector<std::pair<int, int>> tmp;
    
    // (r, c)에 x를 대입한다고 가정
    board[r][c]=x;

    // 다른 후보 삭제
    for (int i=0;i<9;++i) {
      if (cand[r][i].erase(x)) tmp.push_back({r, i});
      if (cand[i][c].erase(x)) tmp.push_back({i, c});
      if (cand[r/3*3+i/3][c/3*3+i%3].erase(x)) tmp.push_back({r/3*3+i/3, c/3*3+i%3});
    }

    // 유효성 평가
    bool valid=1;
    for (int i=0;i<9;++i) {
      for (int j=0;j<9;++j) {
        if (board[i][j]==0 && cand[i][j].empty()) {
          valid=0;
          break;
        }
      }
      if (!valid) break;
    }

    // 다음 단계 진행
    if (valid && solve(num+1, blanks, board)) return 1;

    // 실패 시 backtracking
    // 후보 백업
    for (auto &pi:tmp) {
      cand[pi.first][pi.second].insert(x);
    }

    // (r, c) 0으로 복원
    board[r][c]=0;
  }
  // 모두 실패 시 0
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int board[9][9];
  std::vector<Blank> blanks;
  int cnt=0;
  for (int i=0;i<9;++i) {
    std::string line; std::cin >> line;
    for (int j=0;j<9;++j) {
      board[i][j]=line[j]-'0';
      if (board[i][j]==0) {
        cand[i][j]={1, 2, 3, 4, 5, 6, 7, 8, 9};
        blanks.push_back(Blank(i, j));
      }
    }
  }

  for (const Blank &b:blanks) {
    int r=b.r, c=b.c;
    for (int i=0;i<3;++i) for (int j=0;j<3;++j) {
      int x=board[r/3*3+i][c/3*3+j];
      if (x && cand[r][c].find(x)!=cand[r][c].end()) cand[r][c].erase(x);
    }
    for (int i=0;i<9;++i) {
      int x=board[r][i];
      if (x && cand[r][c].find(x)!=cand[r][c].end()) cand[r][c].erase(x);
      x=board[i][c];
      if (x && cand[r][c].find(x)!=cand[r][c].end()) cand[r][c].erase(x);
    }
  }
  
  // print_v(board);
  solve(0, blanks, board);
  // print_v(board);
  for (int i=0;i<9;++i) {
    for (int j=0;j<9;++j) std::cout << board[i][j];
    std::cout << '\n';
  }
  
  
  return 0;
}