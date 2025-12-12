// 34157 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

using ll=long long int;
constexpr ll MOD=998'244'353LL;

std::vector<ll> inv;
void build(int n)
{
  inv.resize(n+1); 
  inv[1]=1; 
  for (int i=2;i<=n;++i) {
    inv[i]=(MOD-MOD/i*inv[MOD%i]%MOD)%MOD;
  }
}


struct _34157
{
  int n;
  std::vector<ll> in, out, prob, a;
  int cnt=0;

  // u in targeting[v] := u trigger v
  std::vector<std::vector<ll>> G, targeting;

  _34157(int n): n(n), in(n), out(n), prob(n), a(n), G(n), targeting(n) {}

  void solve() {
    tour(0, -1);

    for (int i=0;i<n;++i) {
      std::vector<ll> tmp;
      for (const int &o:targeting[i]) if (in[o]<=in[i] && out[i]<=out[o])
        tmp.push_back(o);
      targeting[i]=tmp;
    }

    prob[0]=1;

    DFS(0, -1);
  }

  void tour(int u, int p) {
    in[u]=++cnt;
    for (const int &v:G[u]) if (v!=p) tour(v, u);
    out[u]=cnt;
  }

  void DFS(int u, int p) {
    for (const int &v:targeting[u]) {
      prob[u]=prob[u]*(a[v]-1)%MOD*inv[a[v]]%MOD;
      --a[v];
    }

    for (const int &v:G[u]) if (v!=p) {
      prob[v]=prob[u];
      DFS(v, u);
    }

    for (const int &v:targeting[u]) ++a[v];
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  build(n);

  _34157 x(n);
  for (int i=0;i<n;++i) {
    std::cin >> x.a[i];
    for (int j=0;j<x.a[i];++j) {
      int k;  std::cin >> k;
      --k;
      x.targeting[k].push_back(i);
    }
  }

  for (int i=0;i<n-1;++i) {
    int u, v;  std::cin >> u >> v;
    --u, --v;
    x.G[u].push_back(v);
    x.G[v].push_back(u);
  }
  
  x.solve();

  for (int i=1;i<n;++i) std::cout << x.prob[i] << '\n';
  return 0;
}
