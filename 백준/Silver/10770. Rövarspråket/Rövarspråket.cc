// 10770

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

inline bool is_cons(const char &c)
{
  return (c!='a' && c!='e' && c!='i' && c!='o' && c!='u');
}
/*
a b c d e f g h i j k l m n o p q r s t u v w x y z
0       4       8           14          20
*/
inline char close_vow(const char &c) 
{
  if (c<='c') return 'a';
  else if (c<='g') return 'e';
  else if (c<='l') return 'i';
  else if (c<='r') return 'o';
  else return 'u';
}
inline char next_cons(const char &c) 
{
  char tmp=c+1<='z'?c+1:'z';
  if (is_cons(tmp)) return tmp;
  else return tmp+1;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string s;  std::cin >> s;
  for (const char &c:s) {
    std::cout << c;
    if (is_cons(c)) {
      std::cout << close_vow(c) << next_cons(c);
    }
  }
  
  return 0;
}