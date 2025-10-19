// 34567

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

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
void write(int x)
{
  if (x==0) return put('0');
  char tmp[11]; int len=0;
  if (x<0) {put('-');x*=-1;}
  while (x) {tmp[len++]='0'+(x%10); x/=10;}
  while (len--) put(tmp[len]);
}
inline void write(const char *s)
{
  while (*s) put(*s++);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int r, c;  std::cin >> r >> c;

    if (r==1 || c==1) {
      write("0\n");
      continue;
    }

    // I. 2x2만 이용
    if (!(r&1) && !(c&1)) {
      write((r>>1)*(c>>1)), put('\n');
      // std::cout << (r>>1)*(c>>1) << '\n';
      for (int i=0;i<r;i+=2) for (int j=0;j<c;j+=2) {
        write("1 " ), write(i+1), put(' '), write(j+1), put('\n');
        // std::cout << "1 " << i+1 << ' ' << j+1 << '\n';
      }
      continue;
    }

    // II. 3x3만 이용
    if (r%3==0 && c%3==0) {
      write((r/3)*(c/3)), put('\n');
      // std::cout << (r/3)*(c/3) << '\n';
      for (int i=0;i<r;i+=3) for (int j=0;j<c;j+=3) {
        write("2 "), write(i+1), put(' '), write(j+1), put('\n');
        // std::cout << "2 " << i+1 << ' ' << j+1 << '\n';
      }
      continue;
    }

    // III. 섞어서 이용
    if (r%6 && c%6) {
      write("0\n");
      // std::cout << "0\n";
      continue;
    }
    else if (r%6==0) {
      int p=c/6, q=c%6;
      int cnt=9*p+(q==1?-1:5);
      write(cnt*(r/6)), put('\n');
      // std::cout << cnt*(r/6) << '\n';
      for (int i=0;i<r;i+=6) {
        for (int x=0;x<c-3;x+=2) {
          write("1 "), write(i+1), put(' '), write(x+1), put('\n');
          write("1 "), write(i+3), put(' '), write(x+1), put('\n');
          write("1 "), write(i+5), put(' '), write(x+1), put('\n');
          // std::cout << "1 " << i+1 << ' ' << x+1 << '\n';
          // std::cout << "1 " << i+3 << ' ' << x+1 << '\n';
          // std::cout << "1 " << i+5 << ' ' << x+1 << '\n';
        }
        write("2 "), write(i+1), put(' '), write(c-2), put('\n');
        write("2 "), write(i+4), put(' '), write(c-2), put('\n');
        // std::cout << "2 " << i+1 << ' ' << c-2 << '\n';
        // std::cout << "2 " << i+4 << ' ' << c-2 << '\n';
      }
      continue;
    }
    else if (c%6==0) {
      int p=r/6, q=r%6;
      int cnt=9*p+(q==1?-1:5);
      write(cnt*(c/6)), put('\n');
      // std::cout << cnt*(c/6) << '\n';
      for (int i=0;i<c;i+=6) {
        for (int x=0;x<r-3;x+=2) {
          write("1 "), write(x+1), put(' '), write(i+1), put('\n');
          write("1 "), write(x+1), put(' '), write(i+3), put('\n');
          write("1 "), write(x+1), put(' '), write(i+5), put('\n');
          // std::cout << "1 " << x+1 << ' ' << i+1 << '\n';
          // std::cout << "1 " << x+1 << ' ' << i+3 << '\n';
          // std::cout << "1 " << x+1 << ' ' << i+5 << '\n';
        }
        write("2 "), write(r-2), put(' '), write(i+1), put('\n');
        write("2 "), write(r-2), put(' '), write(i+4), put('\n');
        // std::cout << "2 " << r-2 << ' ' << i+1 << '\n';
        // std::cout << "2 " << r-2 << ' ' << i+4 << '\n';
      }
      continue;
    }
  }
  flush();
  return 0;
}