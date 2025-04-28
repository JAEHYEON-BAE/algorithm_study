// 26110

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int check(const std::string &s, int l, int r, int k)
{
  while (l<r) {
    if (s[l]==s[r]) ++l, --r;
    else {
      if (k==0) return -1;
      int rml=check(s, l+1, r, k-1);
      int rmr=check(s, l, r-1, k-1);
      if (rml==-1 && rmr==-1) return -1;
      if (rml==-1) return rmr+1;
      if (rmr==-1) return rml+1;
      return std::min(rmr, rml)+1;
    }
  }
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string s;  std::cin >> s;
  std::cout << check(s, 0, s.size()-1, 3);
  return 0;
}