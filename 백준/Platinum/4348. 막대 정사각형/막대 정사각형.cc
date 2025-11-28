// 4348

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#include <bitset>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

void DFS(int bit, int i, int s, const std::vector<int> &v, std::vector<int> &sum)
{
  if (i==v.size()) {
    sum[bit]=s;
    return;
  }

  bit<<=1;
  DFS(bit+1, i+1, s+v[i], v, sum);
  DFS(bit, i+1, s, v, sum);
}

int DP(int bit, int i, int j, const std::vector<int> &bits, const int &n)
{
  // std::cerr << i << ' ' << j << '\t' << std::bitset<8>(bit) << std::endl;

  if (bit+1==(1<<n) && j==4) return 1;
  else if (bit+1==(1<<n) || i==bits.size() || j==4) return 0;
  
  if ((bits[i]&bit)==0 && j<4 && DP(bit|bits[i], i+1, j+1, bits, n)) return 1;
  return DP(bit, i+1, j, bits, n);
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    int n;  std::cin >> n;
    std::vector<int> v(n);
    int tot=0;
    for (int &x:v) {
      std::cin >> x;
      tot+=x;
    }
    if (tot%4) {
      std::cout << "no\n";
      continue;
    }
    std::sort(v.begin(), v.end());


    std::vector<int> sum(1<<n, 0);
    DFS(0, 0, 0, v, sum);

    std::vector<int> bits;
    for (int i=0;i<(1<<n);++i) {
      if (sum[i]==tot/4) bits.push_back(i);
    }

    if (bits.size()<4) {
      std::cout << "no\n";
      continue;
    }
    
    // for (int &i:bits) std::cout << std::bitset<8>(i) << '\n';
    // std::cout << std::endl;

    // std::vector<std::vector<int>> dp(bits.size()+1, std::vector<int>(5, -1));
    std::cout << (DP(0, 0, 0, bits, n)?"yes":"no") << '\n';
  }

  return 0;
}