// 1498

#include <iostream>
#include <vector>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string str;  std::cin >> str;
  int n=str.size();
  
  std::vector<int> pi(n);
  for (int i=1,j=0;i<n;++i) {
    while (j>0 && str[i]!=str[j]) j=pi[j-1];
    if (str[i]==str[j]) pi[i]=++j;
  }

  for (int i=1;i<n;i+=1) {
    if (2*pi[i]<(i+1)) continue;
    else {
      int x = i-pi[i];
      if ((i+1)%(x+1)==0) std::cout << i+1 << ' ' << (i+1)/(x+1) << '\n';
    }
  }
  return 0; 
}
