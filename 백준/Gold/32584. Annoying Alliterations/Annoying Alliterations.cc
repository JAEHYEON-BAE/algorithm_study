// 32584

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

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
void read(std::string &s, int size=0)
{
  static char c; s="";
  if (size) s.reserve(size);
  for (c=get();c<'!';c=get());
  for (;c>='!';c=get()) s+=c;
}

struct Node
{
  Node *child[27];
  int size=0;
  Node() {
    for (int i=0;i<27;++i) child[i]=nullptr;
  }

};

class Trie
{
  Node *root;

public:
  Trie() {
    root=new Node;
  }
  void insert(const std::string &s) {
    Node *node=root;
    for (const char &c:s) {
      int idx=c=='#'?26:c-'a';
      if (!node->child[idx]) node->child[idx]=new Node, ++(node->size);
      node=node->child[idx];
    }
  }

  void adjust_root() {
    Node *node=root;
    while (node->size==1) {
      for (int i=0;i<27;++i) if (node->child[i]) {
        node=node->child[i];
        break;
      }
    }
    root=node;
  }

  int DFS(Node *node, int &diameter) {
    if (!node) return 0;
    int max1=0, max2=0;
    for (int i=0;i<27;++i) {
      if (node->child[i]) {
        int depth=DFS(node->child[i], diameter);
        if (depth>max1) max2=max1, max1=depth;
        else if (depth>max2) max2=depth;
      }
    }
    diameter=std::max(diameter, max1+max2);
    return max1+1;
  }

  int solve() {
    int diameter=0;
    DFS(root, diameter);
    return diameter;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  read(n);
  Trie trie;
  std::vector<std::string> v(n);
  for (auto &s:v) {
    read(s);
    s+='#';
    trie.insert(s);
  }
  trie.adjust_root();
  int res=trie.solve();
  if (res>=2) res-=2;
  std::cout << res;
  
  return 0;
}