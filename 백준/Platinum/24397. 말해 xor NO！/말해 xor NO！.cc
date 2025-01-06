// 24397

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Node
{
  Node* children[2] = {nullptr, nullptr};
  int count = 0;
};

class Trie
{
  Node* root = new Node;

public:
  void insert(int num) {
    Node* current = root;
    for (int i=31;i>=0;--i) {
      int bit = (num>>i) & 1;

      if (!current->children[bit]) {
        current->children[bit] = new Node;
      }
      current = current->children[bit];
      current->count++;
    }
  }

  long long int check(int num, int k) {
    Node* current = root;
    long long int result = 0;
    
    for (int i=31;i>=0;--i) {
      if (!current) break;

      int bit = (num>>i) & 1;
      int k_bit = (k>>i) & 1;

      /**
      * k_bit가 1이라면, bit와 같은 방향은 모두 가능하고, 
        다른 방향의 서브트리 탐색해봐야 함
      * k_bit가 0이라면, bit와 다른 방향은 탐색 불가능하고, 
        같은 방향의 서브트리만 탐색함
      */
      if (k_bit) {
        if (current->children[bit])
          {result += current->children[bit]->count;}
        current = current->children[1-bit];
      }
      else {
        current = current->children[bit];
      }      
    }
    return result;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m, k;  std::cin >> n >> m >> k;
  Trie trie;
  while (n--) {
    int a;  std::cin >> a;
    trie.insert(a);
  }
  
  long long int result = 0;
  while (m--) {
    int b;  std::cin >> b;
    result += trie.check(b, k);
  }

  std::cout << result;
}