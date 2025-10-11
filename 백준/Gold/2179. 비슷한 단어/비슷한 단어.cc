// 2179

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <queue>

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl;

inline int prefix(const std::string &a, const std::string &b) 
{
  int n=std::min(a.size(), b.size());
  int len=0;
  for (;len<n;++len) if (a[len]!=b[len]) break;
  return len;
}

struct Node
{
  Node *child[27];
  int cnt=0;
  int idx=-1;
  int depth=0;
  Node() {
    std::fill(child, child+27, nullptr);
  }
};

struct Trie
{
  Node *root;

  Trie() {
    root=new Node;
  }

  void insert(const std::string &s, int n) {
   
    Node *curr=root;
    for (const char &c:s) {
      int idx=(c=='$')?26:(c-'a');
      if (!curr->child[idx]) {
        curr->child[idx]=new Node;
        ++curr->cnt;
        curr->child[idx]->depth=1+curr->depth;
      }
      curr=curr->child[idx];

      if (c=='$') curr->idx=n;
    }
  }

  int reindex(Node *node) {
    if (node->idx!=-1) return node->idx;

    int tmp=(~0u)>>1;    
    for (int i=0;i<27;++i) if (node->child[i]) {
      tmp=std::min(tmp, reindex(node->child[i]));
    }
    return node->idx=tmp;
  }

  std::pair<int, int> find() {
    reindex(root);
    
    int len=0;
    std::pair<int, int> tmp{0, 1};
    
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      Node *curr=q.front();
      q.pop();
      int curr_depth=curr->depth;

      std::vector<int> v;
      for (int i=0;i<27;++i) if (curr->child[i]) {
        Node *next=curr->child[i];
        v.push_back(next->idx);
        q.push(next);
      }
      
      if (v.size()<2) continue;
      if (curr_depth>len) {
        std::sort(v.begin(), v.end());
        tmp={v[0], v[1]};
        len=curr_depth;
      }
      else if (curr_depth==len) {
        std::sort(v.begin(), v.end());
        if (v[0]<tmp.first || (v[0]==tmp.first && v[1]<tmp.second)) {
          tmp={v[0], v[1]};
        }
      }
    }
    return tmp;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int n;  std::cin >> n;
  std::unordered_map<int, std::string> map;

  Trie trie;
  std::string s;
  for (int i=0;i<n;++i) {
    std::cin >> s;
    map[i]=s;
    s+='$';
    trie.insert(s, i);
  }
  auto res=trie.find();
  std::cout << map[res.first] << '\n' << map[res.second];
 
  return 0;
}