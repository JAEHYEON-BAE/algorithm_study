// 2503

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

bool valid(int x)
{
  int x1=x/100%10, x2=x/10%10, x3=x%10;
  return (x1!=x2 && x2!=x3 && x1!=x3 && x1 && x2 && x3);
}

void query(int q, const int &a, int &strike, int &ball)
{
  strike=0;
  ball=0;

  int q1=q/100, q2=q/10%10, q3=q%10;
  int a1=a/100, a2=a/10%10, a3=a%10;

  if (q1==a1) ++strike;
  else if (q1==a2 || q1==a3) ++ball;
  if (q2==a2) ++strike;
  else if (q2==a1 || q2==a3) ++ball;
  if (q3==a3) ++strike;
  else if (q3==a1 || q3==a2) ++ball;

  return;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::array<bool, 1000> a{};
  for (int x=123;x<1000;++x) if (valid(x)) a[x]=true;
  
  for (int i=0;i<n;++i) {
    int q, s, b;  std::cin >> q >> s >> b;
  
    int strike, ball;
    for (int x=123;x<1000;++x) if (a[x]) {
      query(q, x, strike, ball);
      if (strike!=s || ball!=b) a[x]=false;
    }
  }
  int cnt=0;
  for (int x=123;x<1000;++x) if (a[x]) ++cnt;
  std::cout << cnt;
  return 0;
}