// 19585

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

struct Node
{
  Node *children[26]={};
  bool is_end;
};

class Trie
{
  Node *root=new Node{{}, 0};

  void deleteTrie(Node *node) {
    if (!node) return;
    for (int i=0;i<26;++i) if (node->children[i]) deleteTrie(node->children[i]);
    delete node;
  }

public:
  ~Trie() {deleteTrie(root);}

  void insert(const std::string &word) {
    Node *current=root;
    int n=word.size();
    for (int i=0;i<n;++i) {
      int c=word[i]-'a';
      if (!current->children[c]) current->children[c]=new Node{{}, 0};
      current=current->children[c];
      if (i==n-1) current->is_end=1;
    }
  }

  bool find(const std::string &word, std::vector<int> &pos) {
    Node *current=root;
    int n=word.size();

    bool FLAG=0;
    for (int i=0;i<n;++i) {
      int c=word[i]-'a';
      if (!current->children[c]) break;
      current=current->children[c];
      if (current->is_end) {
        FLAG=1;
        pos.push_back(i);
      }
    }
    return FLAG;
  }
};

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  int c, n, q;  std::cin >> c >> n;

  Trie c_trie;
  for (int i=0;i<c;++i) {
    std::string color;  std::cin >> color;
    c_trie.insert(color);
  }

  std::unordered_set<std::string> names;
  for (int i=0;i<n;++i) {
    std::string name;  std::cin >> name;
    names.insert(name);
  }
  std::cin >> q;
  for (int i=0;i<q;++i) {
    std::string team;  std::cin >> team;
    std::vector<int> pos;
    if (!c_trie.find(team, pos)) {
      std::cout << "No\n";
      continue;
    }
    else {
      bool FLAG=0;
      for (const int &p:pos) if (p+1<=team.size()-1) {
        std::string name=team.substr(p+1);
        if (names.find(name)!=names.end()) {
          FLAG=1;
          std::cout << "Yes\n";
          break;
        }
      }
      if (FLAG) continue;
      else std::cout << "No\n";
    }
  }

  return 0;
}
