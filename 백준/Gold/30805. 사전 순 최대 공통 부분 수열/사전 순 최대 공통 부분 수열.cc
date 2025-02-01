// 30805

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

int n, m;
int *a_end, *b_end;

int* kth(int *a, int k) 
{
  int size=a_end-a;
  int* tmp = (int*)malloc(size*sizeof(int));
  for (int i=0;i<size;++i) tmp[i]=*(a+i); 
  std::nth_element(tmp, tmp+k, tmp+size, std::greater<int>());
  int result=*(tmp+k);
  free(tmp);
  for (int* i=a;i<a_end;++i) {
    if (*i==result) return i;
  }
  assert(0);
}

void recurr(int *a, int *b, std::vector<int> &answer)
{
  int size=a_end-a;
  int k=0;
  for (;k<size;++k) {
    int *pos_a=kth(a, k);
    for (int *i=b;i<b_end;++i) {
      if (*i==*pos_a) {
        answer.push_back(*i);
        recurr(pos_a+1, i+1, answer);
        return;
      }
    }
  }
  if (k==size) return;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> n;
  int* a=(int*)malloc(n*sizeof(int));
  a_end=a+n;
  for (int i=0;i<n;++i) std::cin >> a[i];
  std::cin >> m;
  int* b=(int*)malloc(m*sizeof(int));
  b_end=b+m;
  for (int i=0;i<m;++i) std::cin >> b[i];

  std::vector<int> answer;
  recurr(a, b, answer);

  std::cout << answer.size() << '\n';
  for (int x:answer) std::cout << x << ' ';
  free(a), free(b);

  return 0; 
}
