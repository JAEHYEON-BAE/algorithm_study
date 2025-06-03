// 2263

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <unordered_map>

#define DEBUG(a) std::cerr << #a << " = " << a << std::endl

static constexpr int INF=(~0u)>>2;
static constexpr int nINF=(1<<31);
static constexpr long long int power10[19]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000, 10'000'000'000, 100'000'000'000, 1'000'000'000'000, 10'000'000'000'000, 100'000'000'000'000, 1'000'000'000'000'000, 10'000'000'000'000'000, 100'000'000'000'000'000, 1'000'000'000'000'000'000};

template <typename T>
inline void print_v(const std::vector<std::vector<T>> &v)
{
  for (auto x:v) {
    for (auto y:x) std::cout << y << ' ';
    std::cout << '\n';
  }
  std::cout << std::endl;
  return;
}
template <typename T, size_t N>
inline void print_v(const T (&v)[N][N])
{
  for (int i=0;i<N;++i) {
    for (int j=0;j<N;++j) std::cout << v[i][j] << ' ';
    std::cout << '\n';
  }
  std::cout << std::endl;
}

void build(int in_l, int in_r, int post_l, int post_r, const std::vector<int> &inorder, const std::vector<int> &postorder, const std::unordered_map<int, int> &inorder_idx)
{
  if (in_l>in_r || post_l>post_r) return;
  if (in_l==in_r) {
    std::cout << postorder[post_r] << ' ';
    return;
  }

  int root=postorder[post_r];
  std::cout << root << ' ';

  int idx=inorder_idx.at(root);
  int left_size=idx-in_l;

  build(in_l, idx-1, post_l, post_l+left_size-1, inorder, postorder, inorder_idx);
  build(idx+1, in_r, post_l+left_size, post_r-1, inorder, postorder, inorder_idx);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::vector<int> inorder(n), postorder(n);
  // inorder:   left -> root -> right
  // preorder:  root -> left -> right
  // postorder: left -> right -> root

  std::unordered_map<int, int> inorder_idx;
  for (int i=0;i<n;++i) {
    std::cin >> inorder[i];
    inorder_idx[inorder[i]]=i;
  }
  for (int i=0;i<n;++i) std::cin >> postorder[i];

  build(0, n-1, 0, n-1, inorder, postorder, inorder_idx);
  return 0;
}