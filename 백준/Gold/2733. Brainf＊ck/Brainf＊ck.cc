// 2733

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <stack>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int t;  std::cin >> t;
  for (int i=1;i<=t;++i) {
    std::string str;
    while (true) {
      std::string line;
      std::getline(std::cin, line);
      if (line=="end") break;

      // ignore comments (after '%')
      size_t pos = line.find('%');
      if (pos!=std::string::npos) {
        line = line.substr(0, pos);
      }

      // ignore blank space
      line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
      
      str.append(line);
    }
    std::cout << "PROGRAM #" << i << ": \n";
    // std::cout << str << std::endl;

    std::stack<size_t> stk;
    std::unordered_map<int, int> map;
    bool failure = false;
    for (size_t pos=0;pos<str.size();++pos) {
      if (str[pos]=='[') {
        stk.push(pos);
      }
      else if (str[pos]==']') {
        if (stk.empty()) {
          failure = true;
          break;
        }
        map[stk.top()] = pos;
        map[pos] = stk.top();
        stk.pop();
      }
    }
    if (failure || !stk.empty()) {
      std::cout << "COMPILE ERROR\n";
      continue;
    }

    int pointer = 0;
    std::vector<int> memory(32768, 0);
    for (size_t pos=0;pos<str.size();++pos) {
      const char c = str[pos];
      if (c=='>') 
        pointer = (pointer+1)%32768;
      else if (c=='<')
        pointer = (pointer-1+32768)%32768;
      else if (c=='+')
        memory[pointer] = (memory[pointer]+1)%256;
      else if (c=='-')
        memory[pointer] = (memory[pointer]-1+256)%256;
      else if (c=='.') {
        std::cout << static_cast<char>(memory[pointer]);
      }
      else if (c=='[') {
        if (memory[pointer]==0) pos = map[pos];
      }
      else if (c==']') {
        if (memory[pointer]!=0) pos = map[pos];
      }
    }
    std::cout << '\n';
  }
}