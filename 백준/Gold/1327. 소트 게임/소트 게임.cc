// 1327

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 10'000'000};

struct VectorHash
{
  size_t operator()(const std::vector<int> &v) const {
    size_t hash=0;
    for (int i=0;i<v.size();++i) {
      hash+=power10[i]*v[i];
    }
    return hash;
  }
};

std::vector<int> reverse(std::vector<int> x, const int &pos, const int &k) 
{
  std::reverse(x.begin()+pos, x.begin()+pos+k);
  return x;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n >> k;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];
  
  std::vector<int> comb(n);
  for (int i=0;i<n;++i) comb[i]=i+1;
  std::unordered_map<std::vector<int>, int, VectorHash> mapp;
  std::unordered_map<int, std::vector<int>> r_map;

  // BFS?
  // permutation -> mapping (40320 elements);
  int i=0;
  do {
    mapp[comb]=i;
    r_map[i++]=comb;
  } while (std::next_permutation(comb.begin(), comb.end()));

  std::queue<int> q;
  std::vector<bool> visited(mapp.size(), false);
  std::vector<int> distance(mapp.size(), INF);

  q.push(mapp.at(v));
  visited[mapp.at(v)]=true;
  distance[mapp.at(v)]=0;
  while (!q.empty()) {
    int curr=q.front();
    if (curr==0) break;
    q.pop();
    // std::cout << "curr: " << curr << '\t' << '{';
    // for (int x:r_map.at(curr)) std::cout << x << ' ';
    // std::cout << '}' << std::endl;
    
    for (int i=0;i<=n-k;++i) {
      int next=mapp.at(reverse(r_map.at(curr), i, k));
      if (!visited[next]) {
        visited[next]=true;
        distance[next]=distance[curr]+1;
        q.push(next);
        // std::cout << "\tnext: " << next << '\t' << '{';
        // for (int x:r_map.at(next)) std::cout << x << ' ';
        // std::cout << '}' << std::endl;
      }
    }
  }
  std::cout << ((distance[0]==INF)?-1:distance[0]);
  
  
  return 0;
}