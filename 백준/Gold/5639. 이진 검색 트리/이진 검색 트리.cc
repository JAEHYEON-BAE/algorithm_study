// 5639
#include <iostream>
#include <vector>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

void print(int idx, const std::vector<int> &v, std::vector<bool> &done) 
{
  int left=-1, right=-1;
  for (int i=idx+1;i<v.size();++i) {
    if (done[i]) break;
    if (left==-1 && v[i]<v[idx]) left=i;
    if (right==-1 && v[i]>v[idx]) right=i;
  }
  if (left==-1 && right==-1) {
    std::cout << v[idx] << '\n';
    return;
  }
  if (left!=-1) done[left]=true;
  if (right!=-1) done[right]=true;
  
  if (left!=-1) print(left, v, done);  
  if (right!=-1) print(right, v, done);  
  std::cout << v[idx] << '\n';
  return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int x;
  std::vector<int> v;
  while (std::cin >> x) v.push_back(x);
  
  std::vector<bool> done(v.size(), false);
  done[0]=true;

  print(0, v, done);
  
  return 0; 
}
