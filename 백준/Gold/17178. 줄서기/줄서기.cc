// 17178

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl


struct Ticket
{
  char c;
  int x;
  Ticket(){}
  bool operator<(const Ticket &o) const {
    if (c==o.c) return x<o.x;
    return c<o.c;
  }
  bool operator==(const Ticket &o) const {
    return c==o.c && x==o.x;
  }
  void print() const {
    std::cout << c << '-' << x;
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;

  std::vector<Ticket> v(n*5);
  for (int i=0;i<n*5;++i) {
    std::string s;  std::cin >> s;
    v[i].c=s[0];
    v[i].x=std::stoi(s.substr(2));
  }
  auto order=v;
  std::sort(order.begin(), order.end());

  std::stack<Ticket> stk;

  int index=0;
  for (int i=0;i<n*5;++i) {
    while (!stk.empty() && stk.top()==order[index]) {
      // std::cout << "STK.top() is "; stk.top().print();
      // std::cout << ":\tenter\n";
      stk.pop(); ++index;
    }

    if (v[i]==order[index]) {
      // std::cout << "V[i] is "; v[i].print();
      // std::cout << ":\t\tenter\n";
      ++index;
      while (!stk.empty() && stk.top()==order[index]) {
        // std::cout << "STK.top() is "; stk.top().print();
        // std::cout << ":\tenter\n";
        stk.pop(); ++index;
      }
    }
    else {
      stk.push(v[i]);
    }
  }
  while (!stk.empty() && stk.top()==order[index]) {
    // std::cout << "STK.top() is "; stk.top().print();
    // std::cout << ":\tenter\n";
    stk.pop(); ++index;
  }
  // DEBUG(index);

  if (index==n*5) std::cout << "GOOD";
  else std::cout << "BAD";

  return 0;
}
