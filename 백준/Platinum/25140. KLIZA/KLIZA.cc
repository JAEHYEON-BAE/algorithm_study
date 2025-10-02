// 20160

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_map>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

static constexpr int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

inline int v2i(const std::vector<int> &v) 
{
  int res=0;
  for (int i=0;i<9;++i) {
    res+=power10[8-i]*v[i];
  }
  return res;
}

constexpr int dr[4]={-1, 0, 1, 0};
constexpr int dc[4]={0, 1, 0, -1};

std::vector<int> mv(int x)
{
  std::vector<int> res;
  std::vector<int> tmp(9);
  int pos;
  for (int i=8;i>=0;--i) {
    tmp[i]=x%10;
    x/=10;
    if (tmp[i]==0) pos=i;
  }
  int r=pos/3, c=pos%3;

  for (int d=0;d<4;++d) {
    int nr=r+dr[d];
    int nc=c+dc[d];
    if (nr<0 || nr>=3 || nc<0 || nc>=3) continue;
    int npos=nr*3+nc;
    std::swap(tmp[pos], tmp[npos]);
    res.push_back(v2i(tmp));
    std::swap(tmp[pos], tmp[npos]);
  }
  return res;
}

int comp(int x, int y)
{
  int pos;
  for (int i=8;i>=0;--i) {
    if (x/power10[i]%10==0) {pos=i;break;}
  }
  return y/power10[pos]%10;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int s=0, e=123456780;
  for (int i=8;i>=0;--i) {
    char c;  std::cin >> c;
    if (c=='X') continue;
    else s+=power10[i]*(c-'0');
  }

  // init
  std::unordered_map<int, int> map, rmap;
  std::vector<int> comb={0, 1, 2, 3, 4, 5, 6, 7, 8};
  int id=0;
  do {
    int tmp=0;
    for (int i=0;i<9;++i) {
      tmp+=comb[i]*power10[i];
    }
    map[tmp]=id++;
    rmap[map[tmp]]=tmp;
  } while (std::next_permutation(comb.begin(), comb.end()));

  
  std::queue<int> q;
  std::vector<int> dist(id, -1);
  q.push(s);
  dist[map.at(s)]=0;

  std::vector<int> parent(id, -1);
  
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    int d=dist[map.at(u)];
    std::vector<int> cand=mv(u);
    for (const int &v:cand) if (dist[map.at(v)]==-1) {
      dist[map.at(v)]=1+d;
      parent[map.at(v)]=map.at(u);
      q.push(v);
    }
  }

  std::vector<int> path;
  for (int x=map.at(e);x!=map.at(s);x=parent[x]) {
    path.push_back(rmap.at(x));
  }

  std::reverse(path.begin(), path.end());

  std::cout << path.size() << '\n';
  if (path.empty()) return 0;
  std::cout << comp(s, path[0]) << ' ';
  for (int i=1;i<path.size();++i) {
    std::cout << comp(path[i-1], path[i]) << ' ';
  }

  return 0;
}