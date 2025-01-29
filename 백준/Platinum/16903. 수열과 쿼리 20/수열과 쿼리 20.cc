// 14897

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

struct Node
{
  Node* parent=nullptr;
  Node* children[2]={nullptr, nullptr};

  bool is_leaf() {
    return this->children[0]==nullptr && this->children[1]==nullptr;
  }
};

class Trie
{
  Node* root = new Node;
  void delete_trie(Node* node) {
    if (!node) return;
    if (node->children[0]) delete_trie(node->children[0]);
    if (node->children[1]) delete_trie(node->children[1]);
    delete node;
  }

public:
  ~Trie() {delete_trie(root);}

  void insert(const int &num) {
    Node* curr = root;
    for (int i=31;i>=0;--i) {
      bool b=num>>i & 1;
      if (!curr->children[b]) curr->children[b] = new Node;
      curr->children[b]->parent = curr;
      curr = curr->children[b];
    }
  }

  void _remove(Node* node, const int &num, int depth) {
    if (depth<0) return;
    
    bool b=num>>(31-depth) & 1;
    if (node->children[b]->is_leaf()) {
      delete node->children[b];
      node->children[b]=nullptr;
    }
    if (node->parent) _remove(node->parent, num, depth-1);
  }

  void remove(const int &num) {
    Node* curr=root;
    for (int i=31;i>=0;--i) {
      bool b=num>>i & 1;
      curr = curr->children[b];
    }
    _remove(curr->parent, num, 31);
  }

  int search(const int &num) {
    Node* curr=root;
    int result=0;
    for (int i=31;i>=0;--i) {
      bool b=num>>i & 1;
      if (curr->children[!b]) {
        curr=curr->children[!b];
        result += 1<<i;
      } else {
        curr=curr->children[b];
      }
    }
    return result;
  }

};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int m;  std::cin >> m;
  int type, x;
  std::unordered_map<int, int> cnt;
  Trie trie;
  trie.insert(0);
  while (m--) {
    std::cin >> type >> x;
    if (type==1) {
      if (cnt[x]++==0) trie.insert(x);
    }
    else if (type==2) {
      if (--cnt[x]==0) trie.remove(x);
    }
    else if (type==3) {
      std::cout << trie.search(x) << '\n';
    }
  }
  

  return 0; 
}
