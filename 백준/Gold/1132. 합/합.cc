// 1132

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

using ll=long long int;

static constexpr ll power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

struct OCC
{
  int idx;
  ll cnt;
  OCC(){}
  OCC(int i): idx(i), cnt(0) {}
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::string str;

  std::array<OCC, 10> cnt;
  for (int i=0;i<10;++i) cnt[i]=OCC(i);
  
  std::array<bool, 10> is_first{};
  for (int i=0;i<n;++i) {
    std::cin >> str;

    is_first[str[0]-'A']=1;
    
    int len=str.size();
    for (int j=0;j<len;++j) {
      cnt[str[j]-'A'].cnt+=power10[len-1-j];
    }
  }
  std::sort(cnt.begin(), cnt.end(), 
    [] (const OCC &a, const OCC &b) 
    {
      return a.cnt>b.cnt;
    });

  int notfirst=-1;
  for (int i=9;i>=0;--i) if (!is_first[cnt[i].idx]) {
    notfirst=i;
    break;
  }

  ll res=0LL;
  ll num=9LL;
  for (int i=0;i<10;++i) {
    if (i==notfirst) continue;
    else res+=cnt[i].cnt*(num--);
  }

  std::cout << res;

  return 0;
}

