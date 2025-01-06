// 16906
/**
* IDEA: use TRIE
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
  Node* children[2] = {nullptr, nullptr};
  Node* parent = nullptr;
  bool is_full = false;
};

class Trie
{
Node* root = new Node{{nullptr, nullptr}, nullptr, false};
void deleteTrie(Node* node)
{
  if (node==nullptr) return;
  deleteTrie(node->children[0]);
  deleteTrie(node->children[1]);
  delete node;
}
public:
~Trie() {deleteTrie(root);}
  bool insert(const int& l, std::string& word)
  {
    // std::cerr << "\n-------------\nCHECKPOINT #1: l=" << l << std::endl;
    Node* current = root;

    int depth = 0;
    for (;depth<l && depth>=0;++depth) {
      // std::cerr << "Depth = " << depth << std::endl;
            
      Node* left = current->children[0];
      Node* right = current->children[1];

      if (left==nullptr) {
        current->children[0] = new Node{{nullptr, nullptr}, current, false};
        current = current->children[0];
        word.push_back('0');
        // std::cerr << "\tLeft is nullptr: go to left(0)" << std::endl;
      } 
      else if (left->is_full) {
        if (right==nullptr) {
          current->children[1] = new Node{{nullptr, nullptr}, current, false};
          current = current->children[1];
          
          word.push_back('1');
          // std::cerr << "\tLeft is full and Right is nullptr: go to right(1)" << std::endl;
        }
        else if (right->is_full) {
          current->is_full = true;
          // std::cerr << "\tLeft and Right both are full: fail" << std::endl;
          depth -= 2;
          current = current->parent;
          word.pop_back();
          // std::cerr << "\tTry backtracking" << std::endl;
          continue;
        }
        else {
          current = right;
          word.push_back('1');
          // std::cerr << "\tLeft is full & Right is not full: go to right(1)" << std::endl;
        }
      }
      else {
        current = left;
        word.push_back('0');
        // std::cerr << "\tLeft is not full: go to left(0)" << std::endl;
      }
    }
    if (depth==-1) return false;
    current->is_full = true;
    return true;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;  std::cin >> n;
  std::vector<std::pair<int, int>> v(n);
  for (int i=0;i<n;++i) {
    std::cin >> v[i].first;
    v[i].second = i;
  }

  Trie trie;
  std::sort(v.begin(), v.end());

  std::vector<int> mapping(n);
  for (int i=0;i<n;++i) {
    mapping[v[i].second] = i;
  }
  
  std::vector<std::string> result;
  for (const std::pair<int, int>& p: v) {
    int x = p.first;
    std::string word;
    if (trie.insert(x, word)) {
      result.push_back(word);
    } else {
      std::cout << -1;
      return 0;
    }
  }
  std::cout << 1 << '\n';
  for (const int& idx: mapping) {
    std::cout << result[idx] << '\n';
  }
  
  
  return 0;
}