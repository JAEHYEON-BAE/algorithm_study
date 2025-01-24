// 1786

#include <iostream>
#include <vector>
#include <string>
#include <sys/resource.h>

void print_memory_usage() {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        std::cout << "Memory usage: " << usage.ru_maxrss << " KB\n";
    }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  std::string t, p;
  
  std::getline(std::cin, t);
  std::getline(std::cin, p);
  
  std::vector<int> fail(p.size());
  std::vector<int> results;

  fail[0] = 0;
  int i=1, j=0;
  while (i<p.size()) {
    if (p[i]==p[j]) {
      fail[i]=j+1;
      ++i;++j;
    } else if (j>0) {
      j=fail[j-1];
    } else {
      fail[i]=0;
      ++i;
    }
  }

  i=0; j=0;

  while (i<t.size()) {
    if (t[i]==p[j]) {
      if (j==p.size()-1) {
        results.push_back(i-p.size()+1);
        if (j==0) ++i;
        j=fail[j]-1;
        if (j<0) j=0;
      }
      else {++i, ++j;}
    }
    else {
      if (j>0)  j=fail[j-1];
      else ++i;
    }
  }
  
  std::cout << results.size() << '\n';
  for (int& x: results) std::cout << 1+x << ' ';
  
  return 0;  
}
