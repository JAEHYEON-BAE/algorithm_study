// 15678

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>

namespace fastio
{
  #define INPUT_BUFFER_SIZE (1<<20)
  
  /* INPUT */
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
  void read(long long int &x)
  {
    static char c; x=0;
    bool MINUS_FLAG=0;
    for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
    if (c=='-') {MINUS_FLAG=1;c=get();}
    for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
    if (MINUS_FLAG) x*=-1;
  }
}

#endif

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  
  int n, d;  read(n), read(d);

  // dp[i]=max(0, dp[j])+v[i] for i-d <= j < i
  long long int x;  read(x);

  std::deque<int> dq;
  std::vector<long long int> dp(n, 0);
  long long int max=x;

  dp[0]=x;
  dq.push_back(0);
  max=std::max(max, dp[0]);
  for (int i=1;i<n;++i) {
    read(x);
    
    while (!dq.empty() && dq.front()<i-d) dq.pop_front();
    dp[i]=std::max(dp[dq.front()], 0LL)+x;
    while (!dq.empty() && dp[dq.back()]<=dp[i]) dq.pop_back();
    dq.push_back(i);

    max=std::max(max, dp[i]);
  }
  std::cout << max;
  return 0;
}