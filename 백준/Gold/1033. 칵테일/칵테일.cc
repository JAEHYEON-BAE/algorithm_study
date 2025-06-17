// 1033

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

long long int GCD(long long int a, long long int b)
{
  int c;
  while (b) {
    c=a%b;
    a=b;
    b=c;
  }
  return a;
}
long long int LCM(long long int a, long long int b) 
{
  return a/GCD(a, b)*b;
}

void update(int node, long long int value, std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::vector<long long int> &v)
{
  visited[node]=1;
  v[node]*=value;
  for (const int &next:graph[node]) if (!visited[next]) {
    update(next, value, graph, visited, v);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> graph(n);
  std::vector<long long int> v(n, 1);
  for (int i=0;i<n-1;++i) {
    int a, b, p, q;
    std::cin >> a >> b >> p >> q;
    long long int tmp=LCM(q*v[a], p*v[b]);
    std::vector<bool> visited(n, 0);
    update(a, tmp/(q*v[a]), graph, visited, v);
    
    std::fill(visited.begin(), visited.end(), 0);
    update(b, tmp/(p*v[b]), graph, visited, v);

    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (long long int &x:v) std::cout << x << ' ';
  return 0;
}
