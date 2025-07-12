// 15659

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>

static constexpr int INF=(~0u)>>2;
int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> v(n);
  for (int i=0;i<n;++i) std::cin >> v[i];

  std::string operators="";
  operators.reserve(n-1);
  int p, m, x, d;  std::cin >> p >> m >> x >> d;
  while (p--) operators+='+';
  while (m--) operators+='-';
  while (x--) operators+='*';
  while (d--) operators+='/';

  int min=INF, max=-INF;
  std::sort(operators.begin(), operators.end());
  do {
    std::vector<int> numbers;
    /* true: +, false: - */
    std::vector<bool> op; 

    numbers.push_back(v[0]);
    for (int i=0;i<n-1;++i) {
      if (operators[i]=='+' || operators[i]=='-') {
        op.push_back(operators[i]=='+');
        numbers.push_back(v[i+1]);
      }
      else {
        int tmp=numbers.back();
        if (operators[i]=='*') tmp*=v[i+1];
        else tmp/=v[i+1];
        numbers.pop_back();
        numbers.push_back(tmp);
      }
    }

    assert(numbers.size()==op.size()+1);
    int result=numbers[0];
    for (int i=0;i<op.size();++i) {
      if (op[i]) result+=numbers[i+1];
      else result-=numbers[i+1];
    }

    min=std::min(min, result);
    max=std::max(max, result);
  } while (std::next_permutation(operators.begin(), operators.end()));

  std::cout << max << '\n' << min;
  
  return 0;
}