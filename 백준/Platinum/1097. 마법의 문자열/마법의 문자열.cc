// 1097

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int KMP(const std::string &s) 
{
  int n=s.size();
  std::string text=s+s;
  text=text.substr(1, (n<<1)-2);

  std::vector<int> pi(n, 0);
  int i=1, j=0;
  for (;i<n;++i) {
    while (j && s[i]!=s[j]) j=pi[j-1];
    if (s[i]==s[j]) pi[i]=++j;
  }

  int cnt=0;
  i=0, j=0;
  for (;i<text.size();++i) {
    while (j && text[i]!=s[j]) j=pi[j-1];
    if (text[i]==s[j]) {
      if (j==n-1) {
        ++cnt;
        j=pi[j];
      }
      else ++j;
    }
  }

  return 1+cnt;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k;  std::cin >> n;
  std::vector<std::string> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];
  std::cin >> k;

  std::vector<int> idx(n);
  for (int i=0;i<n;++i) idx[i]=i;

  int cnt=0;
  do {
    std::string s="";
    for (const int &i:idx) s+=v[i];

    if (KMP(s)==k) ++cnt;
  } while (std::next_permutation(idx.begin(), idx.end()));

  std::cout << cnt;
  return 0;
}