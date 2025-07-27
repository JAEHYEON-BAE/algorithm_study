// 26502

#include <iostream>
#include <vector>

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
  void readline(std::string &s, int size=0)
  {
    static char c; s="";
    if (size) s.reserve(size);
    for (c=get();c!='\n'&&c!=EOF;c=get()) s+=c;
  }

  /* OUTPUT */
  char obuf[OUTPUT_BUFFER_SIZE];
  int opos=0;
  inline void flush() 
  {
    fwrite(obuf, 1, opos, stdout);
    opos=0;
  }
  inline void put(char c)
  {
    if (opos==OUTPUT_BUFFER_SIZE) flush();
    obuf[opos++]=c;
  }
  inline void write(const std::string &s)
  {
    for (const char& c:s) put(c);
  }
  inline void write(const char &c) 
  {
    put(c);
  }
  struct FASTIO_FLUSHER
  {
    ~FASTIO_FLUSHER() {flush();}
  } fastio_flusher;
}

#endif

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  using namespace fastio;
  int n; read(n);
  std::string s;
  for (int i=0;i<n;++i) {
    readline(s);
    for (char &c:s) {
      if (c=='a') c='e';
      else if (c=='e') c='i';
      else if (c=='i') c='o';
      else if (c=='o') c='u';
      else if (c=='u') c='y';
      else if (c=='y') c='a';
      else if (c=='A') c='E';
      else if (c=='E') c='I';
      else if (c=='I') c='O';
      else if (c=='O') c='U';
      else if (c=='U') c='Y';
      else if (c=='Y') c='A';
    }
    write(s);
    write('\n');
  }
 
  return 0;
}