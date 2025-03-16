// 8980

#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, c, m;  std::cin >> n >> c >> m;
  std::vector<std::vector<int>> send(n, std::vector<int>(n, 0));
  while (m--) {
    int u, v, boxes;
    std::cin >> u >> v >> boxes;
    send[--u][--v]+=boxes;
  }

  std::vector<int> truck(n, 0);
  int cnt=0;
  for (int i=0;i<n;++i) {
    cnt+=truck[i]; 
    truck[i]=0; 
    
    for (int j=i+1;j<n;++j) truck[j]+=send[i][j];

    int sum=0;
    for (int j=i+1;j<n;++j) {
      if (sum==c) truck[j]=0;
      else if (sum+truck[j]<=c) sum+=truck[j];
      else {
        truck[j]=c-sum;
        sum=c;
      }
    }
  }
  std::cout << cnt;
  
  return 0;
}