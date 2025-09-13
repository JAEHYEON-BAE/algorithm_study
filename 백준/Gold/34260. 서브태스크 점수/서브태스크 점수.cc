#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <array>
#include <bitset>

using ll=long long int;
constexpr ll MOD=998'244'353;

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int p;  std::cin >> p;
  std::array<ll, 3001> tot_cnt{};
  tot_cnt[0]=1;
  
  for (int i=0;i<p;++i) {
    int n, m;  std::cin >> n >> m;
    
    std::vector<int> score(n);
    for (int &x:score) std::cin >> x;
    
    std::vector<std::vector<int>> graph(n);
    std::vector<int> in_degree(n, 0);
    for (int j=0;j<m;++j) {
      int u, v;  std::cin >> u >> v;
      --u;--v;
      graph[u].push_back(v);
      ++in_degree[v];
    }


    std::queue<int> q;
    for (int j=0;j<n;++j) if (!in_degree[j]) q.push(j);

    std::vector<int> bit(n);
    for (int j=0;j<n;++j) bit[j]=1<<j;

    std::vector<int> dp(1<<n, -1);
    dp[0]=0;

    std::vector<int> comb;
    
    while (!q.empty()) {
      int curr=q.front();
      int curr_bit=bit[curr];

      int curr_score=0;
      for (int j=0;j<n;++j) if (curr_bit&(1<<j)) curr_score+=score[j];
      dp[curr_bit]=curr_score;
      // std::cout << curr << ' ' << curr_score << ' ' << std::bitset<7>(curr_bit) << '\n';
      comb.push_back(curr_bit);
      // std::cout << std::bitset<4>(curr_bit) << '\t' << dp[curr_bit] << '\n';
      q.pop();

      for (const int &next:graph[curr]) {
        bit[next]|=curr_bit;
        // std::cout << '\t' << next << ' ' << score[next] << ' ' << std::bitset<4>(bit[next]) << '\n';
        if (--in_degree[next]==0) q.push(next);
      }
    }
    // std::cout << "\n--------------------\n" << std::endl;

    int k=comb.size();
    std::vector<bool> c(k, 0);
    for (int len=2;len<=k;++len) {
      c.assign(k, 0);
      std::fill(c.begin(), c.begin()+len, 1);
      do {
        int mask=0;
        for (int j=0;j<k;++j) if (c[j]) mask|=comb[j];
        
        int tmp_score=0;
        for (int j=0;j<n;++j) if (mask&(1<<j)) tmp_score+=score[j];
        assert(tmp_score<=100);
        
        if (dp[mask]==-1) dp[mask]=tmp_score;
      } while (std::prev_permutation(c.begin(), c.end()));
    }

    std::array<ll, 101> cnt{};
    for (int j=0;j<(1<<n);++j) if (dp[j]!=-1) {
      // std::cerr << std::bitset<7>(j) << '\t' << dp[j] << std::endl;
      assert(dp[j]>=0 && dp[j]<=100);
      ++cnt[dp[j]];
      // std::cout << dp[j] << ' ' << cnt[dp[j]] << '\n';
    }

    std::array<ll, 3001> tmp{};
    for (int j=0;j<=3000;++j) if (tot_cnt[j]) for (int k=0;k<=100 && j+k<=3000;++k) if (cnt[k]) {
      tmp[j+k]+=tot_cnt[j]*cnt[k];
      tmp[j+k]%=MOD;
    }
    tot_cnt.swap(tmp);
  }

  ll ans=0LL;
  for (ll i=0LL;i<=3000;++i) if (tot_cnt[i]) {
    ans+=tot_cnt[i]*i;
    // std::cout << tot_cnt[i] << ' ' << i << '\n';
    ans%=MOD;
  }
  std::cout << ans;
  return 0;
}