// 5446 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>

struct Node
{
  std::unordered_map<char, Node*> children;  
  bool x = false;
  bool is_end = false;
};

class Trie
{
  Node* root = new Node;
  void deleteTrie(Node* node) {
    if (!node) return;
    for (auto& p: node->children) {
      deleteTrie(p.second);
    }
    delete node;
  }

public:
  ~Trie() {deleteTrie(root);}
  void insert(const std::string& s) {
    Node* current = root;
    for (const char& c: s) {
      if (current->children.find(c)==current->children.end()) {
        current->children[c] = new Node;
      }
      current = current->children[c];
    }
    current->is_end = true;
  }

  void marking(const std::string& s) {
    Node* current = root;
    for (const char& c: s) {
      if (current->children.find(c)!=current->children.end()) {
        current = current->children[c];
        current->x = true;
      }
      else return;
    }
  }

  int rm() {
    int result = 0;
    std::stack<Node*> stk;
    stk.push(root);

    while (!stk.empty()) {
      Node* current = stk.top();
      stk.pop();
      for (const auto &p: current->children) {
        if (p.second->x) {
          if (p.second->is_end) ++result;
          stk.push(p.second);
        } else {
          ++result;
        }
      }
    }
    return result;
  }
};


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tc;  std::cin >> tc;
  while (tc--) {
    Trie trie;
    int n;  std::cin >> n;
    std::string file;
    while (n--) {
      std::cin >> file;
      trie.insert(file);
    }
    std::cin >> n;
    if (n==0) std::cout << '1' << '\n';
    else {
      while (n--) {
        std::cin >> file;
        trie.marking(file);
      }
      std::cout << trie.rm() << '\n';
    }
    // trie.print_trie(nullptr, 0);
  }

  return 0;
}
