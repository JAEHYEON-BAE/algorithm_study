// 14572

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <bitset>

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

struct Student
{
  int a, d;
  Student(){}
  Student(int a, int d): a(a), d(d) {}
  bool operator<(const Student &other) const {
    return d<other.d;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n, k, D;  std::cin >> n >> k >> D;

  std::vector<Student> students;
  for (int i=0;i<n;++i) {
    int m, d;  std::cin >> m >> d;
    int a=0;
    for (int j=0;j<m;++j) {
      int x;  std::cin >> x;
      a|=1<<(--x);
    }
    students.push_back(Student(a, d));
  }

  std::sort(students.begin(), students.end());

  std::vector<int> cnt(k, 0);

  auto push=[&cnt, &students, &k](int x) {
    for (int i=0;i<k;++i) if (students[x].a&(1<<i)) {
      ++cnt[i];
    }
  };
  auto pop=[&cnt, &students, &k](int x) {
    for (int i=0;i<k;++i) if (students[x].a&(1<<i)) --cnt[i];
  };

  int l=0, r=0;
  push(0);
  int max=0;
  while (r+1<n) {
    push(++r);
    while (students[r].d-students[l].d>D && l<=r) {
      pop(l++);
    }

    int tot=0, all=0;
    for (int i=0;i<k;++i) {
      if (cnt[i]>0) {
        ++tot;
        if (cnt[i]==r-l+1) ++all;
      }
    }
    max=std::max(max, (tot-all)*(r-l+1));
  }
  std::cout << max;
  
  return 0;
}