// 1463

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> dist(n+1, -1);
  dist[n]=0;

  std::queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int curr=q.front();
    q.pop();
    if (curr==1) break;

    if (curr%3==0 && dist[curr/3]==-1) 
      q.push(curr/3), dist[curr/3]=1+dist[curr];
    if (curr%2==0 && dist[curr/2]==-1) 
      q.push(curr/2), dist[curr/2]=1+dist[curr];
    if (dist[curr-1]==-1) 
      q.push(curr-1), dist[curr-1]=1+dist[curr];
  }
  std::cout << dist[1];

  return 0;
}