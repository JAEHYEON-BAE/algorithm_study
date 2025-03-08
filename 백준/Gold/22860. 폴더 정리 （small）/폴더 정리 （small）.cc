// 22861

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <bitset>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int insert(const std::string &s, std::unordered_map<std::string, int> &map)
{
  static int idx=0;
  if (map.find(s)==map.end()) map[s]=idx++;
  return map[s];
}

std::pair<int, std::bitset<2001>> DFS(const int &node, std::vector<int> &dp, std::vector<std::bitset<2001>> &files, const std::vector<std::vector<int>> &children, const std::vector<bool> &is_dir) 
{
  if (dp[node]!=-1) {
    return {dp[node], files[node]};
  }
  if (!is_dir[node]) {
    std::bitset<2001> tmp(0);
    tmp.set(node);
    return {dp[node]=1, files[node]=tmp};
  }
  int cnt=0; std::bitset<2001> tmp(0);
  for (int child:children[node]) {
    auto result=DFS(child, dp, files, children, is_dir);
    cnt+=result.first;
    tmp|=result.second;
  }
  // std::cout << "for node " << node << ':' << '\t';
  // std::cout << cnt << '\t' << set.size() << std::endl;
  return {dp[node]=cnt, files[node]=tmp};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::unordered_map<std::string, int> map;
  std::vector<int> dp(n+m+1, -1);
  // std::vector<std::unordered_set<int>> files(n+m+1);
  std::vector<std::bitset<2001>> files(n+m+1, 0);
  std::vector<std::vector<int>> children(n+m+1);
  std::vector<bool> is_dir(n+m+1, false);
  for (int i=0;i<n+m;++i) {
    std::string parent, child; int c;
    std::cin >> parent >> child >> c;

    int p_idx=insert(parent, map);
    int c_idx=insert(child, map);

    is_dir[p_idx]=true;
    is_dir[c_idx]=c;
    children[p_idx].push_back(c_idx);
  }

  // for (auto x:map) {
  //   std::cout << x.first << '\t' << x.second << std::endl;
  // }
  
  int q;  std::cin >> q;
  while (q--) {
    std::string s;  std::cin >> s;
    std::string tmp="";
    for (const char &c:s) {
      if (c=='/') tmp.clear();
      else tmp.push_back(c);
    }
    int idx=map[tmp];
    auto result=DFS(idx, dp, files, children, is_dir);
    std::cout << result.second.count() << ' ' << result.first << '\n';
  }
  

  return 0;
}