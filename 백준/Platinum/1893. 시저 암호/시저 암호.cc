// 13220

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int KMP(const std::string& t, const int& tlen, const std::string& p, const int& plen) 
{
  std::vector<int> fail(plen);
  for (int i=1,j=0;i<plen;++i) {
    while (j>0 && p[i]!=p[j]) j=fail[j-1];
    if (p[i]==p[j]) fail[i]=++j;
  }

  int cnt=0;
  for (int i=0,j=0;i<tlen;++i) {
    while (j>0 && t[i]!=p[j]) j=fail[j-1];
    if (t[i]==p[j]) {
      if (j==plen-1) {
        ++cnt;
        j=fail[j];
      }
      else ++j;
    }
  }
  return cnt;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  while (n--) {
    std::string a, w, s;
    std::cin >> a >> w >> s;

    int alen=a.size(), wlen=w.size(), slen=s.size();

    std::unordered_map<char, int> map;
    for (int i=0;i<alen;++i) {map[a[i]] = i;}
    
    std::string shift_w=w;
    std::vector<int> result;
    for (int shift=0;shift<alen;++shift) {
      for (int i=0;i<wlen;++i) {
        shift_w[i] = a[(map[w[i]]+shift)%alen];
      }
      if (KMP(s, slen, shift_w, wlen)==1) result.push_back(shift);
    }
    if (result.size()==0) {
      std::cout << "no solution\n";
    } else if (result.size()==1) {
      std::cout << "unique: " << result[0] << '\n';
    } else {
      std::cout << "ambiguous: ";
      for (const int& x: result) std::cout << x << ' ';
      std::cout << '\n';
    }
  }
  
  return 0; 
}
