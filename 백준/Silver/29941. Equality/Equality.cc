// 29941

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

constexpr char op[3]={'+', '-', '*'};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;  std::cin >> s;
  int n=s.size();

  std::vector<int> num(4);
  std::string tmp;
  for (int i=0, j=0;i<=n;++i) {
    if (i==n || s[i]=='?') {
      num[j++]=std::stoi(tmp);
      tmp="";
    }
    else tmp+=s[i];
  }

  // for (int &x:num)  std::cout << x << ' ';

  // Case 1: x = x ? x ? x
  for (int p=0;p<3;++p) for (int q=0;q<3;++q) {
    int tmp=0;
    if (p==0) {
      if (q==0) tmp=num[1]+num[2]+num[3];
      else if (q==1) tmp=num[1]+num[2]-num[3];
      else if (q==2) tmp=num[1]+num[2]*num[3];
    }
    else if (p==1) {
      if (q==0) tmp=num[1]-num[2]+num[3];
      else if (q==1) tmp=num[1]-num[2]-num[3];
      else if (q==2) tmp=num[1]-num[2]*num[3];
    }
    else if (p==2) {
      if (q==0) tmp=num[1]*num[2]+num[3];
      else if (q==1) tmp=num[1]*num[2]-num[3];
      else if (q==2) tmp=num[1]*num[2]*num[3];
    }

    if (tmp==num[0]) {
      std::cout << num[0] << '=' << num[1] << op[p] << num[2] << op[q] << num[3];
      return 0;
    }
  }
  
  // Case 2: x ? x ? x = x
  for (int p=0;p<3;++p) for (int q=0;q<3;++q) {
    int tmp=0;
    if (p==0) {
      if (q==0) tmp=num[0]+num[1]+num[2];
      else if (q==1) tmp=num[0]+num[1]-num[2];
      else if (q==2) tmp=num[0]+num[1]*num[2];
    }
    else if (p==1) {
      if (q==0) tmp=num[0]-num[1]+num[2];
      else if (q==1) tmp=num[0]-num[1]-num[2];
      else if (q==2) tmp=num[0]-num[1]*num[2];
    }
    else if (p==2) {
      if (q==0) tmp=num[0]*num[1]+num[2];
      else if (q==1) tmp=num[0]*num[1]-num[2];
      else if (q==2) tmp=num[0]*num[1]*num[2];
    }

    if (tmp==num[3]) {
      std::cout << num[0] << op[p] << num[1] << op[q] << num[2] << '=' << num[3];
      return 0;
    }
  }

  // Case 3: x ? x = x ? x
  for (int p=0;p<3;++p) {
    int tmp1;
    if (p==0) tmp1=num[0]+num[1];
    else if (p==1) tmp1=num[0]-num[1];
    else if (p==2) tmp1=num[0]*num[1];

    for (int q=0;q<3;++q) {
      int tmp2;
      if (q==0) tmp2=num[2]+num[3];
      else if (q==1) tmp2=num[2]-num[3];
      else if (q==2) tmp2=num[2]*num[3];

      if (tmp1==tmp2) {
        std::cout << num[0] << op[p] << num[1] << '=' << num[2] << op[q] << num[3];
        return 0;
      }
    }
  }

  std::cout << "EI SAA";
  return 0;
}

