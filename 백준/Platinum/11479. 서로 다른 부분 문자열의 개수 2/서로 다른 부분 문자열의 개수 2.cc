// 11479

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

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
void read(int &x)
{
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}
void read(std::string &s, int size=0)
{
  static char c; s="";
  if (size) s.reserve(size);
  for (c=get();c<'!';c=get());
  for (;c>='!';c=get()) s+=c;
}



int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string s;  read(s);
  int n=s.size();
  std::vector<int> rank(n+1), sa(n), tmp(n+1);
  for (int i=0;i<n;++i) {
    sa[i]=i;
    rank[i]=s[i]-'a';
  }
  rank.back()=-1;

  for (int k=1;k<n;k<<=1) {
    auto cmp=[&rank, &k, &n] (const int &i, const int &j) -> bool {
      if (rank[i]!=rank[j]) return rank[i]<rank[j];
      return rank[std::min(i+k, n)]<rank[std::min(j+k, n)];
    };
    std::sort(sa.begin(), sa.end(), cmp);

    std::fill(tmp.begin(), tmp.end(), 0);
    tmp.back()=-1;

    for (int i=1;i<n;++i) {
      if ((rank[sa[i-1]]!=rank[sa[i]] || rank[std::min(sa[i-1]+k, n)]!=rank[std::min(sa[i]+k, n)]))
        tmp[sa[i]]=tmp[sa[i-1]]+1;
      else
        tmp[sa[i]]=tmp[sa[i-1]];
    }
    
    rank=tmp;
  }

  std::vector<int> height(n, 0);
  int h=0;
  for (int i=0;i<n;++i) {
    if (rank[i]>0) {
      int j=sa[rank[i]-1];
      while (s[i+h]==s[j+h]) ++h;
      height[rank[i]]=h;
      if (h) --h;
    }
  }

  long long int tot=0;
  for (int i=0;i<n;++i) {
    tot+=n-sa[i]-height[i];
  }
  std::cout << tot;
  return 0;
}