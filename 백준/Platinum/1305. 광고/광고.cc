// 1305

#include <iostream>
#include <vector>
#include <string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::string str;  std::cin >> str;
  
  std::vector<int> fail(n);
  for (int i=1,j=0;i<n;++i) {
    while (j>0 && str[i]!=str[j]) j=fail[j-1];
    if (str[i]==str[j]) fail[i]=++j;
  }

  std::cout << n-fail[n-1];
  return 0; 
}
