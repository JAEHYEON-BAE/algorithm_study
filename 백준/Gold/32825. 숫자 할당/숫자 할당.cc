// 32825

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

class _32825
{
  const std::array<int, 8> &a;
  std::array<bool, 14> used;
  std::array<int, 13> perm;

  int ans=0;

  void dfs(int idx) {
    if (idx==2) {
      for (int c=1;c<=13;++c) if (!used[c]) {
        perm[2]=c;
        used[c]=1;
        
        int d=a[4]-(perm[0]+perm[1]+perm[2]);
        if (d<1 || d>13 || used[d]) {
          used[c]=0;
          continue;
        }
        perm[3]=d;
        used[d]=1;

        dfs(4);

        used[d]=0;
        used[c]=0;
      }
    }
    else if (idx==6) {
      for (int g=1;g<=13;++g) if (!used[g]) {
        perm[6]=g;
        used[g]=1;
        
        int h=a[5]-(perm[4]+perm[5]+perm[6]);
        if (h<1 || h>13 || used[h] || h+perm[3]!=a[3]) {
          used[g]=0;
          continue;
        }

        perm[7]=h;
        used[h]=1;

        dfs(8);

        used[h]=0;
        used[g]=0;
      }
    }
    else if (idx==9) {
      for (int j=1;j<=13;++j) if (!used[j]) {
        perm[9]=j;
        used[j]=1;

        int k=a[6]-(perm[8]+perm[9]);
        if (k<1 || k>13 || used[k] || k+perm[2]+perm[6]!=a[2]) {
          used[j]=0;
          continue;
        }

        perm[10]=k;
        used[k]=1;
        
        int l=a[0]-(perm[0]+perm[4]+perm[8]);
        if (l<1 || l>13 || used[l]) {
          used[j]=used[k]=0;
          continue;
        }

        perm[11]=l;
        used[l]=1;

        int m=a[1]-(perm[1]+perm[5]+perm[9]);
        if (m<1 || m>13 || used[m] || l+m!=a[7]) {
          used[j]=used[k]=used[l]=0;
          continue;
        }
        perm[12]=m;
        used[m]=1;

        ++ans;
        
        used[j]=used[k]=used[l]=used[m]=0;
      }
    }
    else {
      for (int x=1;x<=13;++x) if (!used[x]) {
        perm[idx]=x;
        used[x]=1;

        dfs(idx+1);

        used[x]=0;
      }
    }
  }

public:
  _32825(const std::array<int, 8> &a): a(a) {
    std::fill(used.begin(), used.end(), 0);
    dfs(0);
  }

  int result() const {
    return ans;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::array<int, 8> a;
  for (int &x:a) std::cin >> x;
  if (a[0]+a[1]+a[2]+a[3]!=91 || a[4]+a[5]+a[6]+a[7]!=91) {
    std::cout << "0"; 
    return 0;
  }

  _32825 x(a);
  std::cout << x.result();

  return 0;
}

