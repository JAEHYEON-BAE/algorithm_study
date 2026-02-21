// 33684

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

using ll=long long int;
constexpr ll MOD=1'000'000'007;

/* INPUT */
#define INPUT_BUFFER_SIZE (1<<20)
char get()
{
  static char buf[INPUT_BUFFER_SIZE], *S=buf, *T=buf;
  if (S==T) {
    T=(S=buf)+fread(buf, 1, INPUT_BUFFER_SIZE, stdin);
    if (S==T) return EOF;
  }
  return *S++;
}
template<typename T>
void read(T &x)
{
  static char c; x=T(0);
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  ll n; read(n);
  std::vector<std::vector<int>> tree(n);
  std::vector<int> degree(n, 0);

  for (int i=0;i<n-1;++i) {
    int u, v; read(u), read(v);
    --u, --v;
    tree[u].push_back(v);
    tree[v].push_back(u);
    ++degree[u], ++degree[v];
  }
  std::vector<ll> a(n-1);
  for (ll &x:a) {read(x);}
  std::sort(a.begin(), a.end(), std::greater<>());
  

  std::vector<ll> child(n, 1);
  std::queue<int> q;
  for (int i=0;i<n;++i) if (degree[i]==1) q.push(i);
  
  std::vector<ll> weights;

  std::vector<bool> visited(n, 0);
  while (!q.empty()) {
    int u=q.front();
    q.pop();
    visited[u]=1;
    weights.push_back((n-child[u])*child[u]);
    for (const int &v:tree[u]) if (!visited[v]) {
      child[v]+=child[u];
      if (--degree[v]==1) q.push(v);
    }
  }
  weights.pop_back();
  std::sort(weights.begin(), weights.end());
  // for (ll &x:weights) std::cout << x << ' ';
  // std::cout << std::endl;

  ll res=0LL;
  for (int i=0;i<n-1;++i) {
    res+=(weights[i]%MOD)*(a[i]%MOD)%MOD;
    res%=MOD;
  }
  std::cout << res;
  return 0;
}
