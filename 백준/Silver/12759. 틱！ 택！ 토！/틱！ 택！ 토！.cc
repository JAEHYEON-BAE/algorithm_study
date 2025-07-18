// 12759

#include <iostream>
#include <vector>
#include <algorithm>

inline bool is_done(const int &board) 
{
  return (
    (board&0b111'000'000)==0b111'000'000 || 
    (board&0b000'111'000)==0b000'111'000 || 
    (board&0b000'000'111)==0b000'000'111 || 
    (board&0b100'100'100)==0b100'100'100 || 
    (board&0b010'010'010)==0b010'010'010 || 
    (board&0b001'001'001)==0b001'001'001 || 
    (board&0b100'010'001)==0b100'010'001 || 
    (board&0b001'010'100)==0b001'010'100
  );
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int first;  std::cin >> first;
  int r, c;

  int first_board=0, second_board=0;


  bool TOGGLE_FIRST=1;
  while (std::cin >> r >> c) {
    --r;--c;
    r=2-r;c=2-c;
    int pos=r*3+c;
    if (TOGGLE_FIRST) {
      first_board|=1<<pos;
      if (is_done(first_board)) {
        std::cout << first;
        return 0;
      }
    }
    else {
      second_board|=1<<pos;
      if (is_done(second_board)) {
        std::cout << 3-first;
        return 0;
      }
    }
    TOGGLE_FIRST^=1;
  }
  std::cout << 0;
  return 0;
}