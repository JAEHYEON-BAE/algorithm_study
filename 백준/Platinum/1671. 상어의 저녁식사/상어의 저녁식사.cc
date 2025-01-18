// 1671

#include <iostream>
#include <vector>
#include <algorithm>

struct Shark
{
  int size, speed, intell;

  bool operator==(const Shark& other) const {
    return size==other.size && speed==other.speed && intell==other.intell;
  }

  bool operator<(const Shark& other) const {
    return (size<=other.size) && (speed<=other.speed) && (intell<=other.intell);
  }

  bool operator>(const Shark& other) const {
  return (size>=other.size) && (speed>=other.speed) && (intell>=other.intell);  
  }
};

bool bp_m(int shark, const std::vector<std::vector<int>>& graph, std::vector<int>& match, std::vector<bool>& done) 
{
  for (const int& neighbor: graph[shark]) if (!done[neighbor]) {
    done[neighbor] = true;
    
    if (match[neighbor]==-1 || bp_m(match[neighbor], graph, match, done)) {
      match[neighbor] = shark;
      return true;
    }
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<Shark> sharks(n);
  for (int i=0;i<n;++i) std::cin >> sharks[i].size >> sharks[i].speed >> sharks[i].intell;

  std::vector<std::vector<int>> graph(n);
  // 0 ~ n-1  : predator
  // n ~ 2n-1 : prey
  
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
    if (i==j) continue;
    if (sharks[i]==sharks[j]) {if(i>j) graph[i].push_back(n+j);}
    else if (sharks[i]>sharks[j]) graph[i].push_back(n+j);
  }

  std::vector<int> match(n*2, -1);
  std::vector<bool> done;

  for (int i=0;i<n;++i) {
    done.assign(n*2, false);
    bp_m(i, graph, match, done);
    done.assign(n*2, false);
    bp_m(i, graph, match, done);
  }
  
  int result=n;
  for (int x: match) {
    if (x!=-1) --result;
  }
  
  std::cout << result;
}
