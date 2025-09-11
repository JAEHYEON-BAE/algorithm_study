// 27989

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <unordered_map>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

/* INPUT */
#define INPUT_BUFFER_SIZE (1<<20)

char get()
{
  static char buf[INPUT_BUFFER_SIZE], *S=buf, *T=buf;
  if (S==T) {
    T=(S=buf)+fread(buf, 1, INPUT_BUFFER_SIZE, stdin);
    if (S==T) return EOF;
  }
  return *S++;
}
void read(int &x)
{
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}
void read(long long int &x)
{
  static char c; x=0;
  bool MINUS_FLAG=0;
  for (c=get();(c<'0'||c>'9')&&c!='-';c=get());
  if (c=='-') {MINUS_FLAG=1;c=get();}
  for (;c>='0'&&c<='9';c=get()) x=x*10+(c-'0');
  if (MINUS_FLAG) x*=-1;
}

class Fenwick
{
  int n;
  std::vector<long long int> tree;

public:
  Fenwick(int n): n(n), tree(n+1, 0) {}

  void insert(int i, const long long int &x) {
    for (;i<=n;i+=i&-i) tree[i]=std::max(tree[i], x);
  }

  long long int query(int i) const {
    long long int res=0LL;
    for (;i>0;i-=i&-i) res=std::max(res, tree[i]);
    return res;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  std::vector<long long int> a(n);
  for (auto &x:a)  read(x);

  auto cpy=a;
  std::sort(cpy.begin(), cpy.end());

  Fenwick fw(n);
  long long int ans=0;
  for (int i=0;i<n;++i) {
    int pos=1+std::lower_bound(cpy.begin(), cpy.end(), a[i])-cpy.begin();
    long long int k=fw.query(pos-1)+a[i];
    fw.insert(pos, k);
    ans=std::max(ans, k);
  }
  std::cout << ans;
  return 0;
}