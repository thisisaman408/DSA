#include <iostream>

using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int value) : val(value), left(NULL), right(NULL) {}
};

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    preOrder(a);
}