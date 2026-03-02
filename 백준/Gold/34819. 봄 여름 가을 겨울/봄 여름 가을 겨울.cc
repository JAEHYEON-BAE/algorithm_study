// 34819

#include <iostream>
#include <vector>
#include <algorithm>

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

/* OUTPUT */
#define OUTPUT_BUFFER_SIZE (1<<20)

char obuf[OUTPUT_BUFFER_SIZE];
int opos=0;
inline void flush() 
{
  fwrite(obuf, 1, opos, stdout);
  opos=0;
}
inline void put(char c)
{
  if (opos==OUTPUT_BUFFER_SIZE) flush();
  obuf[opos++]=c;
}
inline void write(const char *s)
{
  while (*s) put(*s++);
}

struct Segtree
{
  int n;
  std::vector<int> &a;
  std::vector<int> tree;
  Segtree(int n, std::vector<int> &a): n(n), a(a) 
  {
    int k=1;
    while (k<n) k<<=1;
    k<<=1;
    ++k;
    tree.assign(k, 0);
  }

  void update(int node, int s, int e, int i) 
  {
    if (i<1 || i>=n) return;

    if (s==e) {
      tree[node]=a[i]==a[i-1]?0:i;
      return;
    }

    int m=(s+e)>>1;
    if (i<=m) update(node<<1, s, m, i);
    else update(node<<1|1, m+1, e, i);

    tree[node]=std::max(tree[node<<1], tree[node<<1|1]);
    return;  
  }

  int query(int node, int s, int e, int l, int r)
  {
    if (r<s || l>e) return 0;
    if (l<=s && e<=r) return tree[node];
    int m=(s+e)>>1;
    return std::max(query(node<<1, s, m, l, r), query(node<<1|1, m+1, e, l, r));
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, q; read(n), read(q);
  
  std::vector<int> a(n);
  for (int &x:a) read(x);

  Segtree st(n, a);
  for (int i=0;i<n;++i) st.update(1, 0, n-1, i);

  while (q--) {
    int cmd;  read(cmd);
    if (cmd==1) {
      int i, x; read(i); read(x); --i;
      // query 1
      a[i]=x;
      st.update(1, 0, n-1, i);
      st.update(1, 0, n-1, i+1);
    }
    else if (cmd==2){
      int i;  read(i);  --i;
      // query 2
      if (i==0) write("Spring\n");
      else if (a[i]>a[i-1]) write("Summer\n");
      else if (a[i]<a[i-1]) write("Winter\n");
      else if (a[i]==a[i-1]) {
        int j=st.query(1, 0, n-1, 1, i);
        if (j==0) write("Spring\n");
        else if (a[j]>a[j-1]) write("Autumn\n");
        else write("Spring\n");
      }
    }
  }

  flush();
  return 0;
}
