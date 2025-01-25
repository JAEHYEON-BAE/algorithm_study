// 13220

#include <iostream>
#include <vector>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::string a, b;
  std::cin >> n;
  std::cin.ignore();
  std::getline(std::cin, a);
  std::getline(std::cin, b);

  a+=' '+a;
  int alen=a.size(), blen=b.size();
  std::vector<int> fail(blen);
  
  for (int i=1,j=0;i<blen;++i) {
    while (j>0 && b[i]!=b[j]) j=fail[j-1];
    if (b[i]==b[j]) fail[i]=++j;
  }
  for (int i=0,j=0;i<alen;++i) {
    while (j>0 && a[i]!=b[j]) j=fail[j-1];
    if (a[i]==b[j]) {
      if (j==blen-1) {
        std::cout << "YES";
        return 0;
      }
      else ++j;
    }
  }
  std::cout << "NO";
  return 0; 
}
