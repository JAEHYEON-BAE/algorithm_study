// 6767

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <queue>

std::string encode(const std::vector<std::vector<int>> &state)
{
  int n=state.size();

  std::string res;
  res.reserve(10);
  for (int i=0;i<n;++i) {
    for (const int &x:state[i]) res+=static_cast<char>(x+'0');
    if (i<n-1) res+='|';
  }
  return res;
}

std::vector<std::vector<int>> decode(const std::string &state)
{
  int n=(state.size()+1)>>1;
  std::vector<std::vector<int>> res(n);
  
  int i=0;
  for (const char &c:state) {
    if (c=='|') ++i;
    else res[i].push_back(c-'0');
  }
  return res;
}

std::vector<std::string> neighbors(const std::string &s)
{
  auto v=decode(s);
  int n=v.size();
  std::vector<std::string> res;
  for (int i=0;i<n;++i) if (!v[i].empty()) {
    if (i) {
      if (v[i-1].empty() || v[i-1].back()>v[i].back()) {
        v[i-1].push_back(v[i].back());
        v[i].pop_back();

        res.push_back(encode(v));

        v[i].push_back(v[i-1].back());
        v[i-1].pop_back();
      }
    }
    if (i+1<n) {
      if (v[i+1].empty() || v[i+1].back()>v[i].back()) {
        v[i+1].push_back(v[i].back());
        v[i].pop_back();

        res.push_back(encode(v));

        v[i].push_back(v[i+1].back());
        v[i+1].pop_back();
      }
    }
  }
  return res;
}


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;
  while (std::cin >> n && n) {
    std::vector<std::vector<int>> state(n);

    for (int i=0;i<n;++i) {
      int x;  std::cin >> x; state[i].push_back(x);
    }

    std::string dest;
    for (int i=1;i<=n;++i) {
      dest+=static_cast<char>(i+'0');
      if (i<n) dest+='|';
    }
    
    std::queue<std::string> q;
    std::unordered_map<std::string, int> dist;
    std::unordered_map<std::string, bool> visited;

    auto s=encode(state);
    q.push(s);
    dist[s]=0;
    visited[s]=1;

    bool DONE=0;
    
    while (!q.empty()) {
      std::string curr=q.front();
      int d=dist[curr];
      q.pop();

      if (curr==dest) {
        std::cout << d << '\n';
        DONE=1;
        break;
      }
      
      auto nexts=neighbors(curr);
      for (const std::string &next:nexts) {
        if (visited[next]) continue;
        dist[next]=d+1;
        visited[next]=1;
        q.push(next);
      }
    }
    if (!DONE) {
      std::cout << "IMPOSSIBLE\n";
      continue;
    }
  }
  
  return 0;
}

