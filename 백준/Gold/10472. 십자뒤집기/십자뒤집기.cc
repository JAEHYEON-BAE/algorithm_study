// 10472

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

std::vector<int> dp(1<<9, -1);
int trigger[9]={0b000'001'011, 0b000'010'111, 0b000'100'110, 0b001'011'001, 0b010'111'010, 0b100'110'100, 0b011'001'000, 0b111'010'000, 0b110'100'000};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int p;  std::cin >> p;
  std::string str1, str2, str3;
  std::vector<int> dist(1<<9, INF);
  dist[0]=0;
  std::queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int curr=q.front();
    q.pop();
    for (int i=0;i<9;++i) {
      int nxt=curr^trigger[i];
      if (dist[nxt]<INF) continue;
      else {
        dist[nxt]=1+dist[curr];
        q.push(nxt);
      }
    }
  }
  
  while (p--) {
    int bit=0;
    std::cin >> str1 >> str2 >> str3;
    int i=8;
    for (const char &c:str1+str2+str3) {
      if (c=='*') bit|=1<<i;
      --i;
    }
    std::cout << dist[bit] << '\n';
  }
  
  return 0;
}