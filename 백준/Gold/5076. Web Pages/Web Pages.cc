// 5076

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <stack>


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string line;
  while (std::getline(std::cin, line)) {
    if (line=="#") break;
    else if (line.empty()) {
      std::cout << "legal\n";
      continue;
    }
    std::vector<std::string> tags;
    std::string tmp;
    bool TAG_FLAG=0;
    for (const char &c:line) {
      if (c=='<') TAG_FLAG=1;
      if (TAG_FLAG) tmp+=c;
      if (c=='>') {
        TAG_FLAG=0;
        tags.push_back(tmp);
        tmp.clear();
      }
    }

    if (TAG_FLAG) {
      std::cout << "illegal\n";
      continue;
    }

    bool ILLEGAL=0;

    std::stack<std::string> stk;
    for (const auto &tag:tags) {
      if (tag[tag.size()-2]=='/') continue;
      else if (tag[1]!='/') {
        std::string tag_name;
        bool NAME_FLAG=0;
  
        for (const char &c:tag) {
          if (c=='<') NAME_FLAG=1;
          else if (c==' ' || c=='/' || c=='>') {NAME_FLAG=0; break;}
          else if (NAME_FLAG) tag_name+=c;
        }

        stk.push(tag_name);
      }
      else {
        if (stk.empty() || tag!="</"+stk.top()+">") {
          ILLEGAL=1;
          break;
        }
        stk.pop();
      }
    }
    if (!stk.empty()) ILLEGAL=1;
    std::cout << (ILLEGAL?"illegal\n":"legal\n");
  }
  return 0;
}