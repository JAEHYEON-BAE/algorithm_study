// 1082

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

struct inf_number
{
  std::string number;
  
  bool operator<(const inf_number& other) const {
    if (number.size()==other.number.size()) return number < other.number;
    return number.size()<other.number.size();
  }

  bool operator>(const inf_number& other) const {
    if (number.size()==other.number.size()) return number > other.number;
    return number.size()>other.number.size();
  }
  
  bool operator==(const inf_number& other) const {
    return number==other.number;
  }
  
  bool operator!=(const inf_number& other) const {
    return number!=other.number;
  }

  inf_number push_front(const char& c) const {
    inf_number result = {c+ this->number};
    return result;
  }

  inf_number push_back(const char& c) const {
    inf_number result = {this->number + c};
    return result;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n;
  std::unordered_map<int, char> P(n); // {cost, number}
  for (int i = 0; i < n; ++i) {
    int x;    std::cin >> x;
    if (P.find(x)==P.end()) P[x]=i+'0';
    else P[x] = (P[x]-'0'<i)? i+'0': P[x];
  }
  std::cin >> m;

  // dynamic programming: dp[i] = largest number with budget i
  std::vector<inf_number> dp(m + 1);
  dp[0] = {""};

  for (int i = 1; i <= m; ++i) {
    for (const auto& p: P) {
      if (i-p.first>=0) {        
        if (p.second=='0') {
          // std::cout << "\tCHECKPOINT #1" << std::endl;
          dp[i] = std::max(dp[i], dp[i-p.first].push_back(p.second));
          if (dp[i].number=="0") dp[i].number="";
        }
        else {
          // std::cout << "\tCHECKPOINT #2" << std::endl;
          dp[i] = std::max(dp[i], std::max(dp[i-p.first].push_back(p.second), dp[i-p.first].push_front(p.second)));
        }
      }
    }
  }

  std::string result = dp[m].number;
  if (result=="") std::cout << '0';
  else std::cout << result;
  return 0;
}
