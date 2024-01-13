#include <ios>
#include <unordered_map>
using namespace std;
unordered_map<char, pair<char, char>> tree;

void preorder(char parent) 
{
        if (parent == '.') {return;}
        printf("%c", parent);
        preorder(tree[parent].first);
        preorder(tree[parent].second);
        return;
}
void inorder(char parent)
{
        if (parent == '.') {return;}
        inorder(tree[parent].first);
        printf("%c", parent);
        inorder(tree[parent].second);
        return;
}
void postorder(char parent) 
{
        if (parent == '.') {return;}
        postorder(tree[parent].first);
        postorder(tree[parent].second);
        printf("%c", parent);
        return;
}

int main()
{
        int n; scanf("%d", &n);
        for (int i=0;i<n;i++) {
                char a, b, c;
                scanf(" %c %c %c", &a, &b, &c);
                tree[a] = {b, c};
        }
        preorder('A');
        printf("\n");
        inorder('A');
        printf("\n");
        postorder('A');
        return 0;
}