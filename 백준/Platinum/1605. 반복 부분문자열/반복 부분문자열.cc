// 1605

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

int lcp(const std::string &s, const int &l)
{
  std::vector<int> sa(l), rank(l);
  for (int i=0;i<l;++i) sa[i]=i, rank[i]=s[i]-'a';

  std::vector<int> tmp(l);
  for (int k=1;k<l;k<<=1) {
    auto cmp=[&](const int &a, const int &b) -> bool {
      if (rank[a]==rank[b]) {
        int ra=a+k<l?rank[a+k]:-1;
        int rb=b+k<l?rank[b+k]:-1;
        return ra<rb;
      }
      else return rank[a]<rank[b];
    };
    std::sort(sa.begin(), sa.end(), cmp);
    tmp[sa[0]]=0;
    for (int i=1;i<l;++i) tmp[sa[i]]=tmp[sa[i-1]]+cmp(sa[i-1], sa[i]);
    std::swap(rank, tmp);

    if (rank[sa[l-1]]==l-1) break;
  }
  // return sa;

  int h=0, ans=0;

  /** KASAI Algorithm: 
    *     A_{i-1}과 인접 접미사의 lcp를 h라 하면, 
    *     A_{i}와 인접 접미사의 lcp는 h-1보다 크거나 같다.
    */
  for (int i=0;i<l;++i) if (rank[i]) {
    int j=sa[rank[i]-1];
    if (h) --h;
    while (i+h<l && j+h<l && s[i+h]==s[j+h]) ++h;
    ans=std::max(ans, h);
  }
  return ans;
}


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int l;  std::cin >> l;
  std::string s;  std::cin >> s;
  std::cout << lcp(s, l);
  
  return 0;
}