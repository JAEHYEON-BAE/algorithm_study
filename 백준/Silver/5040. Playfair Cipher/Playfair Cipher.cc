// 5040

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  std::string key;  std::getline(std::cin, key);
  std::string text;  std::getline(std::cin, text);

  char encrypt[5][5];
  bool used[26];  std::fill(used, used+26, 0);
  int idx=0;
  for (const char &c:key) {
    if (c==' ' || used[c-'a']) continue;
    used[c-'a']=1;
    encrypt[idx/5][idx%5]=c;
    ++idx;
  }
  if (idx<25) for (char c='a';c<='z';++c) {
    if (used[c-'a'] || c=='q') continue;
    encrypt[idx/5][idx%5]=c;
    ++idx;
  }

  std::unordered_map<char, std::pair<int, int>> map;
  for (int i=0;i<5;++i) for (int j=0;j<5;++j) {
    map[encrypt[i][j]]={i, j};
  }

  std::string res="";
  char tmp[2]={'_', '_'};
  int n=text.size();
  for (int i=0;i<n;) {
    char c=text[i];
    if (c==' ') {++i;continue;}
    if (tmp[0]=='_') {tmp[0]=c; ++i;}
    else if (tmp[0]==c) tmp[1]='x';
    else {tmp[1]=c;++i;}

    if (tmp[1]!='_') {
      int r1=map[tmp[0]].first, c1=map[tmp[0]].second;
      int r2=map[tmp[1]].first, c2=map[tmp[1]].second;

      if (r1==r2) {
        res.push_back(encrypt[r1][(c1+1)%5]);
        res.push_back(encrypt[r2][(c2+1)%5]);
      }
      else if (c1==c2) {
        res.push_back(encrypt[(r1+1)%5][c1]);
        res.push_back(encrypt[(r2+1)%5][c2]);
      }
      else {
        res.push_back(encrypt[r1][c2]);
        res.push_back(encrypt[r2][c1]);
      }

      // std::cout << tmp[0] << tmp[1] << " -> " << res.substr(res.size()-2) << '\n';

      tmp[0]=tmp[1]='_';
    }
  }
  if (tmp[0]!='_') {
    tmp[1]='x';
    
    int r1=map[tmp[0]].first, c1=map[tmp[0]].second;
    int r2=map[tmp[1]].first, c2=map[tmp[1]].second;

    if (r1==r2) {
      res.push_back(encrypt[r1][(c1+1)%5]);
      res.push_back(encrypt[r2][(c2+1)%5]);
    }
    else if (c1==c2) {
      res.push_back(encrypt[(r1+1)%5][c1]);
      res.push_back(encrypt[(r2+1)%5][c2]);
    }
    else {
      res.push_back(encrypt[r1][c2]);
      res.push_back(encrypt[r2][c1]);
    }
  }
  for (char &c:res) c-=32;
  std::cout << res;

  return 0;
}
