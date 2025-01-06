// 9250 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

struct Node
{
  std::unordered_map<char, Node*> children;
  Node* fail;
  bool is_end = false;
};

class Trie
{
  Node* root = new Node;

  void deleteTrie(Node* node) {
    if (node==nullptr)  return;
    for (auto &pair: node->children) {
      deleteTrie(pair.second);
    }
    delete node;
  }

public:
  void insert(const std::string& str) {
    Node* current = root;
    for (const char& c: str) {
      if (current->children.find(c)==current->children.end()) {
        current->children[c] = new Node;
      }
      current = current->children[c];
    }
    current->is_end = true;
  }

  void build_fail() {
    std::queue<Node*> q;
    root->fail = root;
    q.push(root);
    
    while (!q.empty()) {
      Node* current = q.front();  q.pop();
    
      for (const auto& next: current->children) {
        if (!next.second) continue;
        
        if (current==root) next.second->fail = root;
        else {
          Node* anc = current->fail;
          while (anc!=root && anc->children.find(next.first)==anc->children.end()) {
            anc = anc->fail;
          }
          if (anc->children.find(next.first)!=anc->children.end()) {
            anc = anc->children[next.first];
          }
          next.second->fail = anc;
        }

        if (next.second->fail->is_end) next.second->is_end = true;
        q.push(next.second);
      }
    }
  }

  bool explore(const std::string& str) {
    Node* current = root;
    for (int i=0;i<str.size();++i) {
      char c = str[i];
      while (current!=root && current->children.find(c)==current->children.end()) {
        current = current->fail;
      }
      if (current->children.find(c)!=current->children.end()) {
        current = current->children[c];
      }

      if (current->is_end) return true;
    }
    return false;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;  std::cin >> n;
  Trie trie;
  while (n--) {
    std::string str;  std::cin >> str;
    trie.insert(str);
  }

  trie.build_fail();
  
  int q;  std::cin >> q;
  while (q--) {
    std::string str;  std::cin >> str;
    if (trie.explore(str)) std::cout << "YES\n";
    else std::cout << "NO\n";
  }

  return 0;
}
