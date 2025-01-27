// 10266

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool KMP(const std::vector<int>& t, const std::vector<int>& p)
{
  int tlen=t.size(), plen=p.size();

  std::vector<int> pi(plen, 0);
  for (int i=1,j=0;i<plen;++i) {
    while (j>0 && p[i]!=p[j]) j=pi[j-1];
    if (p[i]==p[j]) pi[i]=++j;
  }

  for (int i=0,j=0;i<tlen;++i) {
    while (j>0 && t[i]!=p[j]) j=pi[j-1];
    if (t[i]==p[j]) {
      if (j==plen-1)  return true;
      else ++j;
    }
  }

  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> c1(n), c2(n);
  for (int i=0;i<n;++i) std::cin >> c1[i];
  for (int i=0;i<n;++i) std::cin >> c2[i];

  std::sort(c1.begin(), c1.end());
  std::sort(c2.begin(), c2.end());

  int tmp1=c1[0], tmp2=c2[0];
  for (int i=0;i<n-1;++i) {
    c1[i]=(c1[(i+1)%n]-c1[i]+360'000)%360'000;
    c2[i]=(c2[(i+1)%n]-c2[i]+360'000)%360'000;
  }
  c1[n-1]=(tmp1-c1[n-1]+360'000)%360'000;
  c2[n-1]=(tmp2-c2[n-1]+360'000)%360'000;

  c1.insert(c1.end(), c1.begin(), c1.end());

  if (KMP(c1, c2)) std::cout << "possible";
  else std::cout << "impossible";
  
  return 0; 
}
