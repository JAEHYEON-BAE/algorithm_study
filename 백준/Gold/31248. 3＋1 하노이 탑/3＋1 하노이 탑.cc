// 31248

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

std::vector<std::pair<char, char>> moves;

void hanoi(int n, char from, char to, char via)
{
  if (n==0) return;
  hanoi(n-1, from, via, to);
  moves.push_back({from, to});
  hanoi(n-1, via, to, from);
}

int recur(int n, bool b) 
{
  if (n==0) return 0;
  if (n==1) {
    if (b) moves.push_back({'A', 'D'});
    else moves.push_back({'B', 'D'});
    return 1;
  }
  if (b) {
    hanoi(n-2, 'A', 'B', 'C');
    moves.push_back({'A', 'C'});
    moves.push_back({'A', 'D'});
    moves.push_back({'C', 'D'});
  }
  else {
    hanoi(n-2, 'B', 'A', 'C');
    moves.push_back({'B', 'C'});
    moves.push_back({'B', 'D'});
    moves.push_back({'C', 'D'});
  }
  return (1<<(n-2))-1 + 3 + recur(n-2, b^1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::cout << recur(n, 1) << '\n';
  for (auto it=moves.begin();it<moves.end();++it) {
    std::cout << (*it).first << ' ' << (*it).second << '\n';
  }

  /** 1...N을  N-1, N 와 1...N-2로 분할 : 2^(N-2)-1
    * 3번 옮긴 후, 1...N-2에 대해 동일하게 시행
    */
  return 0;
}