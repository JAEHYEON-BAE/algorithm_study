// 3080

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const long long mod = 1'000'000'007;
long long fac[33] = {1}, ans = 1;

struct Node{
  std::vector<std::pair<char, int>> children;
} nd[9090909]; int pv;

void insert(int node, const char *s){
  if (*s==0) return;
  int idx=-1;
  for(int i=0;i<nd[node].children.size();++i){
    if(nd[node].children[i].first == *s) {
      idx = nd[node].children[i].second; break; 
    }
  }
  if(idx==-1){
    nd[node].children.emplace_back(*s, ++pv);
    nd[node].children.shrink_to_fit();
    idx=pv;
  }
  insert(idx, s+1);
}
void dfs(int v){
  ans=ans*fac[nd[v].children.size()]%mod;
  for(auto i: nd[v].children) dfs(i.second);
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  for (int i=1;i<33;++i) fac[i]=fac[i-1]*i%mod;
  int root = ++pv;
  int n; std::cin >> n;
  std::string s; 
  for (int i=0;i<n;++i){
    std::cin >> s; 
    insert(root, (s+'#').c_str());
  }
  dfs(root);
  std::cout << ans;
}
