// 32789

#include <iostream>
#include <vector>
#include <algorithm>


int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, m;  std::cin >> n >> m;
  std::vector<std::vector<int>> v(n, std::vector<int>(m, 0));
  
  for (int i=0;i<n;++i) for (int j=0;j<m;++j) std::cin >> v[i][j];

  int answer=0;

  if (n<m) {
    for (int rs=0;rs<n;++rs) {
      // rs ~ re까지의 열을 한 열로 압축하여 Kadane's Algorithm 활용
      std::vector<int> tmp(m, 0);
      for (int re=rs;re<n;++re) {
        for (int c=0;c<m;++c) tmp[c]+=v[re][c];
  
        int sum=tmp[0], max=tmp[0];
  
        for (int i=1;i<m;++i) {
          sum=std::max(tmp[i], sum+tmp[i]);
          max=std::max(max, sum);
        }
  
        answer=std::max(answer, max);
      }
    }
  }
  else {
    for (int cs=0;cs<m;++cs) {
      std::vector<int> tmp(n, 0);
      for (int ce=cs;ce<m;++ce) {
        for (int r=0;r<m;++r) tmp[r]+=v[r][ce];

        int sum=tmp[0], max=tmp[0];

        for (int i=1;i<n;++i) {
          sum=std::max(tmp[i], sum+tmp[i]);
          max=std::max(max, sum);
        }

        answer=std::max(answer, max);
      }
    }
  }
  std::cout << answer;
  
  return 0;
}
