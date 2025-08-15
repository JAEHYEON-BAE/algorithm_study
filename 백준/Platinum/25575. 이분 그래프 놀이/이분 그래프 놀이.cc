// 25575

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#ifndef FASTIO_HPP
#define FASTIO_HPP

#include <cstdio>
#include <string>

namespace fastio
{
  #define INPUT_BUFFER_SIZE (1<<20)
  #define OUTPUT_BUFFER_SIZE (1<<20)
  
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
}

#endif

struct Vertex
{
  int idx, freq;
  Vertex(): idx(0), freq(0) {}
  Vertex(int i, int f): idx(i), freq(f) {}

  bool operator<(const Vertex &o) const {
    return freq==o.freq?idx<o.idx:freq<o.freq;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  int t, n, m, k;  read(t);
  while (t--) {
    read(n), read(m), read(k);
    std::vector<std::pair<int, int>> edges(k);

    std::vector<int> x_freq(n), y_freq(m);
    
    for (auto &pair:edges) {
      read(pair.first), read(pair.second);
      ++x_freq[--pair.first]; 
      ++y_freq[--pair.second];
    }

    std::vector<Vertex> X(n), Y(m);
    for (int i=0;i<n;++i) {
      X[i].idx=i;
      X[i].freq=x_freq[i];
    }
    for (int i=0;i<m;++i) {
      Y[i].idx=i;
      Y[i].freq=y_freq[i];
    }

    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());

    // for (int i=0;i<m;++i) std::cout << Y[i].idx << ' ';
    // std::cout << std::endl;

    
    int max=0;
    for (int i=0;i<n;++i) max+=X[i].freq*(i+1);
    for (int i=0;i<m;++i) max+=Y[i].freq*(i+1);
    std::cout << max << ' ';

    std::vector<int> x_value_candidate(n), y_value_candidate(m);
    x_value_candidate[X[0].idx]=1;
    y_value_candidate[Y[0].idx]=1;

    for (int i=1;i<n;++i) {
      if (X[i].freq==X[i-1].freq) x_value_candidate[X[i].idx]=x_value_candidate[X[i-1].idx];
      else x_value_candidate[X[i].idx]=i+1;
    }
    
    for (int i=1;i<m;++i) {
      if (Y[i].freq==Y[i-1].freq) y_value_candidate[Y[i].idx]=y_value_candidate[Y[i-1].idx];
      else y_value_candidate[Y[i].idx]=i+1;
      // std::cout << "YCAND[" << Y[i].idx << "] = " << y_value_candidate[Y[i].idx] << '\n';
    }

    
    std::sort(edges.begin(), edges.end(),
      [&x_value_candidate, &y_value_candidate] (const std::pair<int, int> &a, const std::pair<int, int> &b) {
        int tmp_a=x_value_candidate[a.first]+y_value_candidate[a.second];
        int tmp_b=x_value_candidate[b.first]+y_value_candidate[b.second];
        return tmp_a<tmp_b;
      });

    int rm_x=edges[0].first;
    int rm_y=edges[0].second;

    std::cout << max-(x_value_candidate[rm_x]+y_value_candidate[rm_y]) << '\n';
  }
  
  return 0;
}

