// 1918
#include <iostream>
#include <vector>
#include <stack>
#include <string>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string str;  std::cin >> str;
  for (int i=0;i<str.size();++i) {
    if (str[i]=='*' || str[i]=='/') {      
      if (str[i-1]!=')') str.insert(i-1, 1, '(');
      else {
        int open=1;
        for (int j=i-2;j>=0;--j) {
          if (str[j]==')') ++open;
          else if (str[j]=='(') --open;

          if (open==0) {
            str.insert(j, 1, '('); break;
          }
        }
      }
      ++i;
      if (str[i+1]!='(') str.insert(i+2, 1, ')');
      else {
        int open=1;
        for (int j=i+2;j<str.size();++j) {
          if (str[j]=='(') ++open;
          else if (str[j]==')') --open;

          if (open==0) {
            str.insert(j+1, 1, ')'); break;
          }
        }
      }
    }
  }

  for (int i=0;i<str.size();++i) {
    if (str[i]=='+' || str[i]=='-') {
      if (str[i-1]!=')') str.insert(i-1, 1, '(');
      else {
        int open=1;
        for (int j=i-2;j>=0;--j) {
          if (str[j]==')') ++open;
          else if (str[j]=='(') --open;

          if (open==0) {
            str.insert(j, 1, '('); break;
          }
        }
      }
      ++i;
      if (str[i+1]!='(') str.insert(i+2, 1, ')');
      else {
        int open=1;
        for (int j=i+2;j<str.size();++j) {
          if (str[j]=='(') ++open;
          else if (str[j]==')') --open;

          if (open==0) {
            str.insert(j+1, 1, ')'); break;
          }
        }
      }
    }
  }


  std::stack<char> stk;
  std::stack<char> op_stk;
  std::stack<int> open_idx, oper_idx;
  for (int i=0;i<str.size();++i) {
    const char &c = str[i];
    if (c=='(') {
      open_idx.push(i);
    } else if (c==')') {
      if (!oper_idx.empty() && oper_idx.top()>open_idx.top()){
        stk.push(op_stk.top());
        op_stk.pop();
        oper_idx.pop();
      }
      open_idx.pop();
    } else if (c=='+' || c=='-' || c=='*' || c=='/') {
      op_stk.push(c);
      oper_idx.push(i);
    } else {
      stk.push(c);
    }
  }

  std::string result;
  while (!stk.empty()) {
    result.push_back(stk.top());
    stk.pop();
  }
  for (int i=result.size()-1;i>=0;--i) std::cout << result[i];

  return 0; 
}
