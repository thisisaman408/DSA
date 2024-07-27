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
int levels(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void nthLevel(Node *root, int count, int n)
{
    if (root == NULL)
        return;
    if (count == n)
    {
        cout << root->val << " ";
        return;
    }

    nthLevel(root->left, count + 1, n);
    nthLevel(root->right, count + 1, n);
}

void nthLevelR(Node *root, int count, int n)
{
    if (root == NULL)
        return;
    if (count == n)
    {
        cout << root->val << " ";
        return;
    }

    nthLevelR(root->right, count + 1, n);
    nthLevelR(root->left, count + 1, n);
}
void levelOrder(Node *root)
{
    int n = levels(root);
    for (int i = 1; i <= n; i++)
    {
        nthLevel(root, 1, i);
        cout << endl;
    }
}
void levelOrderR(Node *root)
{
    int n = levels(root);
    for (int i = 1; i <= n; i++)
    {
        nthLevelR(root, 1, i);
        cout << endl;
    }
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
    levelOrder(a);
    levelOrderR(a);
}