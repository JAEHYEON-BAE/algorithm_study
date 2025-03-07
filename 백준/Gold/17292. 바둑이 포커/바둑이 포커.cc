// 17290

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

struct Pair
{
  std::string s1, s2;
  int num1, num2;
  bool color1, color2;

  Pair(std::string s1, std::string s2) {
    this->s1=s1; this->s2=s2;
    if (s1[0]>='1' && s1[0]<='9') num1=s1[0]-'0';
    else num1=s1[0]-'a'+10;

    if (s2[0]>='1' && s2[0]<='9') num2=s2[0]-'0';
    else num2=s2[0]-'a'+10;

    color1=(s1[1]=='b'); color2=(s2[1]=='b');
  }

  bool seq() const {
    int gap=abs(num1-num2);
    return (gap==1 || gap==14);
  }
  bool n_same() const {return num1==num2;}
  bool c_same() const {return color1==color2;}

  bool operator<(const Pair& other) const {
    if (seq() != other.seq()) return seq() > other.seq();
    if (n_same() != other.n_same()) return n_same() > other.n_same();

    if (c_same() != other.c_same()) return c_same() > other.c_same(); 
    int max1 = std::max(num1, num2), min1 = std::min(num1, num2);
    int max2 = std::max(other.num1, other.num2), min2 = std::min(other.num1, other.num2);

    if (max1 != max2) return max1 > max2; 
    if (min1 != min2) return min1 > min2; 
    return (max1 == num1 ? color1 : color2) > (max2 == other.num1 ? other.color1 : other.color2);
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string s;  std::cin >> s;
  std::vector<std::string> cards(6, "");
  for (int i=0;i<17;++i) {
    if (i%3==0) cards[i/3].push_back(s[i]);
    else if (i%3==1) cards[i/3].push_back(s[i]);
  }

  std::vector<Pair> pairs;
  std::vector<bool> used={1, 1, 0, 0, 0, 0};
  do {
    std::string s1="", s2="";
    for (int i=0;i<6;++i) if (used[i]) {
      if (s1=="") s1=cards[i];
      else {s2=cards[i]; break;}
    }
    pairs.push_back(Pair(s1, s2));
  } while (std::prev_permutation(used.begin(), used.end()));
  std::sort(pairs.begin(), pairs.end());
  for (const Pair p:pairs) {
    std::cout << p.s1 << p.s2 << '\n';
  }

  return 0;
}