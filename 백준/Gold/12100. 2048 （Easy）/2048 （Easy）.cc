// 12100

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>

void up(std::vector<std::vector<int>> &v)
{
  int n=v.size();
  for (int i=0;i<n;++i) {
    std::queue<int> q;
    for (int j=0;j<n;++j) {
      if (v[j][i]) q.push(v[j][i]);
      v[j][i]=0;
    }

    std::vector<bool> dirty(n, 0);

    int j=0;
    while (!q.empty()) {
      if (j && v[j-1][i]==q.front() && !dirty[j-1]) {
        v[j-1][i]<<=1;
        dirty[j-1]=1;
      }
      else v[j][i]=q.front(), ++j;
      q.pop();
    }
  }
}
void down(std::vector<std::vector<int>> &v) 
{
  int n=v.size();
  for (int i=0;i<n;++i) {
    std::queue<int> q;
    for (int j=n-1;j>=0;--j) {
      if (v[j][i]) q.push(v[j][i]);
      v[j][i]=0;
    }

    std::vector<bool> dirty(n, 0);

    int j=n-1;
    while (!q.empty()) {
      if (j<n-1 && v[j+1][i]==q.front() && !dirty[j+1]) {
        v[j+1][i]<<=1;
        dirty[j+1]=1;
      }
      else v[j][i]=q.front(), --j;
      q.pop();
    }
  }
}
void right(std::vector<std::vector<int>> &v) 
{
  int n=v.size();
  for (int i=0;i<n;++i) {
    std::queue<int> q;
    for (int j=n-1;j>=0;--j) {
      if (v[i][j]) q.push(v[i][j]);
      v[i][j]=0;
    }
    
    std::vector<bool> dirty(n, 0);

    int j=n-1;
    while (!q.empty()) {
      if (j<n-1 && v[i][j+1]==q.front() && !dirty[j+1]) {
        v[i][j+1]<<=1;
        dirty[j+1]=1;
      }
      else v[i][j]=q.front(), --j;
      q.pop();
    }
  }
}
void left(std::vector<std::vector<int>> &v) 
{
  int n=v.size();
  for (int i=0;i<n;++i) {
    std::queue<int> q;
    for (int j=0;j<n;++j) {
      if (v[i][j]) q.push(v[i][j]);
      v[i][j]=0;
    }

    std::vector<bool> dirty(n, 0);

    int j=0;
    while (!q.empty()) {
      if (j && v[i][j-1]==q.front() && !dirty[j-1]) {
        v[i][j-1]<<=1;
        dirty[j-1]=1;
      }
      else v[i][j]=q.front(), ++j;
      q.pop();
    }
  }
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<std::vector<int>> v(n, std::vector<int>(n));
  for (int i=0;i<n;++i) for (int j=0;j<n;++j) std::cin >> v[i][j];

  int max=0;
  for (int bitmask=0;bitmask<(1<<10);++bitmask) {
    auto tmp=v;
    for (int i=0;i<5;++i) {
      int d=bitmask>>(i<<1)&0b11;

      if (d==0) up(tmp);
      else if (d==1) right(tmp);
      else if (d==2) down(tmp);
      else left(tmp);
    }

    int x=0;
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
      x=std::max(x, tmp[i][j]);
    }
    max=std::max(max, x);
  }
  std::cout << max;
  return 0;
}