// 31827

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int mv(const std::vector<bool> &a, const std::vector<bool> &b)
{
  int n=a.size();
  std::vector<int> _a, _b;
  for (int i=0;i<n;++i) {
    if (a[i]) _a.push_back(i);
    if (b[i]) _b.push_back(i);
  }
  int cnt=0;
  for (int i=0;i<_a.size();++i) {
    cnt+=abs(_a[i]-_b[i]);
  }
  return cnt;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<bool> bs(n, 0);
  int cnt1=0, cnt0=0;

  for (int i=0;i<n;++i) {
    int x;  std::cin >> x;
    bs[i]=x;
    if (x) ++cnt1;
  }
  cnt0=n-cnt1;

  std::vector<int> v(m);
  int seq_a=0, seq_b=0;
  for (int i=0;i<m;++i) {
    std::cin >> v[i];
    if (i&1) seq_b+=v[i];
  }
  seq_a=n-seq_b;


  int min=INF;
  if (cnt0==seq_a) {
    std::vector<bool> seq(n, 0);
    bool bit=0;
    int pos=0;
    for (int i=0;i<m;++i) {
      for (int j=0;j<v[i];++j) seq[pos+j]=bit;
      pos+=v[i];
      bit^=1;
    }
    min=std::min(min, mv(bs, seq));
  }
  if (cnt0==seq_b) {
    std::vector<bool> seq(n, 0);
    bool bit=1;
    int pos=0;
    for (int i=0;i<m;++i) {
      for (int j=0;j<v[i];++j) seq[pos+j]=bit;
      pos+=v[i];
      bit^=1;
    }
    min=std::min(min, mv(bs, seq));
  }
  std::cout << min;

  return 0;
}