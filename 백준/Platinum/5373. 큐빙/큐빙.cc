// 5373

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

void rt(char d, std::string &s) {
  if (d=='-') {
    char t=s[0];
    s[0]=s[2], s[2]=s[8], s[8]=s[6], s[6]=t;
    t=s[1];
    s[1]=s[5], s[5]=s[7], s[7]=s[3], s[3]=t;
  }
  else {
    char t=s[0];
    s[0]=s[6], s[6]=s[8], s[8]=s[2], s[2]=t;
    t=s[1];
    s[1]=s[3], s[3]=s[7], s[7]=s[5], s[5]=t;
  }
}

struct Cube
{
  std::string U, D, F, B, L, R;
  Cube() {
    U="wwwwwwwww";
    D="yyyyyyyyy";
    F="rrrrrrrrr";
    B="ooooooooo";
    L="ggggggggg";
    R="bbbbbbbbb";
  }
  void rotate(const std::string &cmd) {
    std::string t;
    if (cmd[0]=='U') {
      if (cmd[1]=='-') {
        t=F;
        for (int i=0;i<3;++i) {
          F[i]=L[i];
          L[i]=B[i];
          B[i]=R[i];
          R[i]=t[i];
        }
      }
      else {
        t=F;
        for (int i=0;i<3;++i) {
          F[i]=R[i];
          R[i]=B[i];
          B[i]=L[i];
          L[i]=t[i];
        }
      }
      rt(cmd[1], U);
    }
    else if (cmd[0]=='D') {
      if (cmd[1]=='-') {
        t=F;
        for (int i=6;i<9;++i) {
          F[i]=R[i];
          R[i]=B[i];
          B[i]=L[i];
          L[i]=t[i];
        }
      }
      else {
        t=F;
        for (int i=6;i<9;++i) {
          F[i]=L[i];
          L[i]=B[i];
          B[i]=R[i];
          R[i]=t[i];
        }
      }
      rt(cmd[1], D);
    }
    else if (cmd[0]=='F') {
      t=U;
      if (cmd[1]=='-') {
        U[6]=R[0], U[7]=R[3], U[8]=R[6];
        R[0]=D[2], R[3]=D[1], R[6]=D[0];
        D[0]=L[2], D[1]=L[5], D[2]=L[8];
        L[2]=t[8], L[5]=t[7], L[8]=t[6];
      }
      else {
        U[6]=L[8], U[7]=L[5], U[8]=L[2];
        L[2]=D[0], L[5]=D[1], L[8]=D[2];
        D[0]=R[6], D[1]=R[3], D[2]=R[0];
        R[0]=t[6], R[3]=t[7], R[6]=t[8];
      }
      rt(cmd[1], F);
    }
    else if (cmd[0]=='B') {
      t=U;
      if (cmd[1]=='-') {
        U[0]=L[6], U[1]=L[3], U[2]=L[0];
        L[0]=D[6], L[3]=D[7], L[6]=D[8];
        D[6]=R[8], D[7]=R[5], D[8]=R[2];
        R[2]=t[0], R[5]=t[1], R[8]=t[2];
      }
      else {
        U[0]=R[2], U[1]=R[5], U[2]=R[8];
        R[2]=D[8], R[5]=D[7], R[8]=D[6];
        D[6]=L[0], D[7]=L[3], D[8]=L[6];
        L[0]=t[2], L[3]=t[1], L[6]=t[0];
      }
      rt(cmd[1], B);
    }
    else if (cmd[0]=='L') {
      t=U;
      if (cmd[1]=='-') {
        U[0]=F[0], U[3]=F[3], U[6]=F[6];
        F[0]=D[0], F[3]=D[3], F[6]=D[6];
        D[0]=B[8], D[3]=B[5], D[6]=B[2];
        B[2]=t[6], B[5]=t[3], B[8]=t[0];
      }
      else {
        U[0]=B[8], U[3]=B[5], U[6]=B[2];
        B[2]=D[6], B[5]=D[3], B[8]=D[0];
        D[0]=F[0], D[3]=F[3], D[6]=F[6];
        F[0]=t[0], F[3]=t[3], F[6]=t[6];
      }
      rt(cmd[1], L);
    }
    else if (cmd[0]=='R') {
      t=U;
      if (cmd[1]=='-') {
        U[2]=B[6], U[5]=B[3], U[8]=B[0];
        B[0]=D[8], B[3]=D[5], B[6]=D[2];
        D[2]=F[2], D[5]=F[5], D[8]=F[8];
        F[2]=t[2], F[5]=t[5], F[8]=t[8];
      }
      else {
        U[2]=F[2], U[5]=F[5], U[8]=F[8];
        F[2]=D[2], F[5]=D[5], F[8]=D[8];
        D[2]=B[6], D[5]=B[3], D[8]=B[0];
        B[0]=t[8], B[3]=t[5], B[6]=t[2];
      }
      rt(cmd[1], R);
    }
    else assert(!"INVALID COMMAND");
  }
  void print() const {
    for (int i=0;i<3;++i) {
      for (int j=0;j<3;++j) std::cout << U[i*3+j];
      std::cout << '\n';
    }
  }
  void full_print() const {
    std::cout << "\n\n    " << U[0]<<U[1]<<U[2]<< "\n    "<<U[3]<<U[4]<<U[5]<<"\n    "<<U[6]<<U[7]<<U[8]<<'\n'<<'\n';
    for (int i=0;i<3;++i)
    std::cout<<L[3*i+0]<<L[3*i+1]<<L[3*i+2]<<' '<<F[3*i+0]<<F[3*i+1]<<F[3*i+2]<<' '<<R[3*i+0]<<R[3*i+1]<<R[3*i+2]<<' '<<B[3*i+0]<<B[3*i+1]<<B[3*i+2]<<'\n';
    std::cout << "\n    " << D[0]<<D[1]<<D[2]<< "\n    "<<D[3]<<D[4]<<D[5]<<"\n    "<<D[6]<<D[7]<<D[8]<<'\n'<<'\n';
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int t;  std::cin >> t;
  while (t--) {
    Cube cube;
    int n;  std::cin >> n;
    std::string s;
    while (n--) {
      std::cin >> s; cube.rotate(s);
      // cube.full_print();
      // std::cout << std::endl;
    }
    cube.print();
  }

  return 0;
}