// 4206

#include <iostream>
#include <vector>
#include <string>

long long KMP(const std::vector<bool>& t, const std::string& p)
{
  int tlen=t.size(), plen=p.size();
  std::vector<int> pi(plen);
  for (int i=1,j=0;i<plen;++i) {
    while (j>0 && p[i]!=p[j]) j=pi[j-1];
    if (p[i]==p[j]) pi[i]=++j;
  }

  long long cnt=0;
  for (int i=0,j=0;i<tlen;++i) {
    while (j>0 && t[i]!=(p[j]-'0')) j=pi[j-1];
    if (t[i]==(p[j]-'0')) {
      if (j==plen-1) {
        ++cnt;
        j=pi[j];
      }
      else ++j;
    }
  }

  return cnt;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::vector<int> fib(28);
  fib[0]=1, fib[1]=1;
  for (int i=2;i<28;++i) {
    fib[i]=fib[i-1]+fib[i-2];
  }


  std::vector<std::vector<bool>> FS(28);
  FS[0]={0}, FS[1]={1};
  for (int i=2;i<28;++i) {
    FS[i]=FS[i-1];
    FS[i].insert(FS[i].end(), FS[i-2].begin(), FS[i-2].end());
  }

  
  int n, t=0;
  while (std::cin >> n) {
    std::cout << "Case " << ++t << ": ";
    std::string p;  std::cin >> p;
    
    const auto pos = std::lower_bound(fib.begin(), fib.end(), p.size()) - fib.begin();

    if (pos>n) {
      std::cout << 0 << '\n';
      continue;
    }
    
    std::vector<long long> dp(101, 0);
    if (p.size()==1) {
      if (p=="0") {
        dp[0]=1, dp[1]=0;
      } else {
        dp[0]=0, dp[1]=1;
      }

      for (int i=2;i<=n;++i) {
        dp[i]=dp[i-1]+dp[i-2];
      }

      std::cout << dp[n] << '\n';
      continue;
    }
    
    std::vector<bool> sf=FS[pos+1], fs=FS[pos], ss=FS[pos+1];
    sf.insert(sf.end(), FS[pos].begin(), FS[pos].end());
    fs.insert(fs.end(), FS[pos+1].begin(), FS[pos+1].end());
    ss.insert(ss.end(), FS[pos+1].begin(), FS[pos+1].end());

    const long long f=KMP(FS[pos], p);
    const long long s=KMP(FS[pos+1], p);

    const long long sf_cnt=KMP(sf, p) - s - f;
    const long long fs_cnt=KMP(fs, p) - f - s;
    const long long ss_cnt=KMP(ss, p) - s*2;

    dp[pos] = f;
    dp[pos+1] = s;
    dp[pos+2] = dp[pos]+dp[pos+1]+sf_cnt;
    for (int i=pos+3;i<=n;++i) {
      // dp[i]=dp[i-1]+dp[i-2]+mid;
      if ((i-pos)%2) dp[i]=dp[i-1]+dp[i-2]+fs_cnt;
      else dp[i]=dp[i-1]+dp[i-2]+ss_cnt;
    }

    std::cout << dp[n] << '\n';
    continue;
  }
  return 0; 
}
