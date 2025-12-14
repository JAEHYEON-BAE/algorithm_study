// 26768 

#include <iostream>
#include <algorithm>
#include <vector>
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
void read(std::string &s, int size=0)
{
  static char c; s="";
  if (size) s.reserve(size);
  for (c=get();c<'!';c=get());
  for (;c>='!';c=get()) s+=c;
}
/* OUTPUT */
#define OUTPUT_BUFFER_SIZE (1<<20)

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


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;  read(s);
  for (char &c:s) {
    if (c=='a') put('4');
    else if (c=='e') put('3');
    else if (c=='i') put('1');
    else if (c=='o') put('0');
    else if (c=='s') put('5');
    else put(c);
  }
  flush();
  return 0;
}
