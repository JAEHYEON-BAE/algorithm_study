// 6677

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int x, y;
  while (1) {
    std::cin >> x >> y;
    if (x==0 && y==0) break;
    std::vector<std::vector<char>> plot(y+2, std::vector<char>(x+2, ' '));
    for (int i=0;i<x+2;++i) {
      plot[0][i]='-';
      plot[y+1][i]='-';
    }
    for (int i=0;i<y+2;++i) {
      plot[i][0]='|';
      plot[i][x+1]='|';
    }
    plot[0][0]=plot[0][x+1]=plot[y+1][0]=plot[y+1][x+1]='+';
    while (1) {
      std::string cmd; std::cin >> cmd;
      if (cmd=="PRINT") {
        for (auto line:plot) {
          for (char p:line) std::cout << p;
          std::cout << '\n';
        }
        // std::cout << '\n';
        std::cout << std::endl;
        break;
      }
      else if (cmd=="POINT") {
        int _x, _y;  std::cin >> _x >> _y;
        char &tmp=plot[_y][_x];
        if (tmp=='o') continue;
        else {
          if (tmp==' ') tmp='o';
          else tmp='*';
        }
      }
      else if (cmd=="LINE") {
        int _x1, _y1, _x2, _y2;
        std::cin >> _x1 >> _y1 >> _x2 >> _y2;
        int dx, dy;
        if (_x1==_x2) dx=0;
        else dx=(_x1<_x2)?1:-1;
  
        if (_y1==_y2) dy=0;
        else dy=(_y1<_y2)?1:-1;
  
        if (dx==0) {
          for (int i=_y1;i!=_y2+dy;i+=dy) {
            char &tmp=plot[i][_x1];
            if (tmp=='|' || tmp=='+') continue;
            else {
              if (tmp==' ') tmp='|';
              else if (tmp=='-') tmp='+';
              else tmp='*';
            }
          }
        }
        else if (dy==0) {
          for (int i=_x1;i!=_x2+dx;i+=dx) {
            char &tmp=plot[_y1][i];
            if (tmp=='-' || tmp=='+') continue;
            else {
              if (tmp==' ') tmp='-';
              else if (tmp=='|') tmp='+';
              else tmp='*';
            }
          }
        }
        else {
          char c;
          if (dx*dy>0) c='\\';
          else c='/';
          
          for (int i=_x1, j=_y1;i!=_x2+dx;i+=dx, j+=dy) {
            char &tmp=plot[j][i];
            if (c=='\\') {
              if (tmp==c || tmp=='x') continue;
              else {
                if (tmp==' ') tmp=c;
                else if (tmp=='/') tmp='x';
                else tmp='*';
              }
            }
            else {
              if (tmp==c || tmp=='x') continue;
              else {
                if (tmp==' ') tmp=c;
                else if (tmp=='\\') tmp='x';
                else tmp='*';
              }
            }
          }
        }
      }
      else if (cmd=="TEXT") {
        int _x, _y; std::string text;  std::cin >> _x >> _y >> text;
        int size=std::min(static_cast<int>(text.size()), x+1-_x);
        for (int i=0;i<size;++i) {
          char &tmp=plot[_y][_x+i];
          if (tmp==' ' || tmp==text[i]) tmp=text[i];
          else tmp='*';
        }      
      }
      else if (cmd=="CLEAR") {
        int _x1, _y1, _x2, _y2;
        std::cin >> _x1 >> _y1 >> _x2 >> _y2;

        int dx, dy;
        if (_x1==_x2) dx=0;
        else dx=(_x1<_x2)?1:-1;

        if (_y1==_y2) dy=0;
        else dy=(_y1<_y2)?1:-1;
        
        if (dx==0 && dy==0) plot[_y1][_x1]=' ';
        else if (dx==0) {
          for (int i=_y1;i!=_y2+dy;i+=dy) {
            plot[i][_x1]=' ';
          }
        }
        else if (dy==0) {
          for (int i=_x1;i!=_x2+dx;i+=dx) 
            plot[_y1][i]=' ';
        }
        else for (int i=_x1;i!=_x2+dx;i+=dx) for (int j=_y1;j!=_y2+dy;j+=dy) {
          plot[j][i]=' ';
        } 
      }
    }
  }

  return 0;
}