// 15740

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
bool bigger(const std::string &a, const std::string &b);

std::string plus(std::string &a, std::string &b)
{
  while (a.size()>b.size()) b.push_back('0');
  while (a.size()<b.size()) a.push_back('0');

  int n=a.size();
  std::string answer="";
  int sum, carry=0;
  for (int i=0;i<n;++i) {
    sum=carry+static_cast<int>(a[i]-'0')+static_cast<int>(b[i]-'0');
    carry=0;
    if (sum>9) {
      carry=1; sum-=10;
    } 
    answer.push_back(static_cast<char>(sum+'0'));
  }
  if (carry) answer.push_back('1');
  std::reverse(answer.begin(), answer.end());
  return answer;  
}

std::string minus(std::string &a, std::string &b, bool neg)
{
  
  while (a.size()<b.size()) a.push_back('0');
  while (b.size()<a.size()) b.push_back('0');

  if (!bigger(a, b)) std::swap(a, b);
  int n=a.size();
  std::string answer="";
  int sub, carry=0;

  for (int i=0;i<n;++i) {
    int x=static_cast<int>(a[i]-'0')-carry;
    int y=static_cast<int>(b[i]-'0');
    if (x>=y) sub=x-y, carry=0;
    else sub=x+10-y, carry=1;
    answer.push_back(static_cast<char>(sub+'0'));
  }
  while (answer.size()>1 && answer.back()=='0') answer.pop_back(); 
  if (neg && answer!="0") answer.push_back('-');
  std::reverse(answer.begin(), answer.end());
  
  return answer;
}

bool bigger(const std::string &a, const std::string &b)
{
  if (a.size()!=b.size()) return a.size()>b.size();
  else {
    int n=a.size();
    for (int i=n-1;i>=0;--i) {
      if (a[i]!=b[i]) return a[i]>b[i];
    }
  }
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string a, b;  std::cin >> a >> b;  
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());

  
  if (a.back()=='-') {
    if (b.back()=='-') {
      a.pop_back();b.pop_back();
      std::cout << '-' << plus(a, b);
      return 0;
    }
    else {
      a.pop_back(); 
      bool neg=bigger(a, b);
      std::cout << minus(a, b, neg);
      return 0;
    }
  } else {
    if (b.back()=='-') {
      b.pop_back();
      bool neg=!bigger(a, b);
      std::cout << minus(a, b, neg);
      return 0;
    }
    else { 
      std::cout << plus(a, b);
      return 0;
    }
  }
  return 0; 
}