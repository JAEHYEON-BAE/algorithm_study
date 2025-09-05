// 4817

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

struct Node
{
  char type;
  char var;
  std::vector<Node*> child;
  Node(char t, char v=0): type(t), var(v) {}
};


std::string s;
int pos;
Node *parseE();
Node *parseP();
Node *parseF();

Node *parseE() {
  Node *left=parseP();
  if (pos<s.size() && s[pos]=='+') {
    ++pos;
    Node *right=parseE();
    Node *node=new Node('+');

    if (left->type=='+') node->child.insert(node->child.end(), left->child.begin(), left->child.end());
    else node->child.push_back(left);

    if (right->type=='+') node->child.insert(node->child.end(), right->child.begin(), right->child.end());
    else node->child.push_back(right);

    return node;
  }
  return left;
}

Node *parseP() {
  std::vector<Node*> factors;
  while (pos<s.size() && (isalpha(s[pos]) || s[pos]=='(')) {
    Node *f=parseF();
    factors.push_back(f);
  }
  if (factors.size()==1) return factors[0];
  Node *node=new Node('*');
  for (Node *f:factors) {
    if (f->type=='*') node->child.insert(node->child.end(), f->child.begin(), f->child.end());
    else node->child.push_back(f);
  }
  return node;
}

Node *parseF() {
  if (s[pos]=='(') {
    ++pos;
    Node *e=parseE();
    ++pos;
    return e;
  }
  else {
    return new Node('v', s[pos++]);
  }
}

int prev(char t) {
  if (t=='+') return 0;
  else if (t=='*') return 1;
  else if (t=='v') return 2;
  else return -1;
}


void print(Node *curr, char parent) {
  bool FLAG=(prev(curr->type)<prev(parent));
  if (FLAG) std::cout << '(';
  
  if (curr->type=='v') {
    std::cout << curr->var;
  }
  else if (curr->type=='+') {
    for (int i=0;i<curr->child.size();++i) {
      if (i) std::cout << '+';
      print(curr->child[i], '+');
    }
  }
  else if (curr->type=='*') {
    for (Node *c:curr->child) {
      print(c, '*');
    }
  }
  if (FLAG) std::cout << ')';
}

void deleteNode(Node *r) {
  if (!r) return;
  for (Node *c:r->child) deleteNode(c);
  delete r;
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr); 
  std::cout.tie(nullptr);

  while (std::cin >> s) {
    pos=0;
    Node *root=parseE();
    print(root, 0);
    deleteNode(root);
    std::cout << '\n';
  }
  
  return 0;
}