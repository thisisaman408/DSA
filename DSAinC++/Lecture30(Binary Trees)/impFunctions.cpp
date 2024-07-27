#include <iostream>
#include <queue>
#include <climits>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int value) : val(value), left(NULL), right(NULL) {}
};

void display(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

int sumOfTreeNodes(Node *root)
{
    if (root == NULL)
        return 0;
    int sum = root->val + sumOfTreeNodes(root->left) + sumOfTreeNodes(root->right);
    return sum;
}
int prodOfTreeNodes(Node *root)
{
    if (root == NULL)
        return 1;
    int prod = root->val * prodOfTreeNodes(root->left) * prodOfTreeNodes(root->right);
    return prod;
}
int size(Node *root)
{
    if (root == NULL)
        return 0;
    int count = 1 + size(root->left) + size(root->right);
    return count;
}
int maxVal(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    int leftMax = maxVal(root->left);
    int rightMax = maxVal(root->right);
    return max(root->val, max(leftMax, rightMax));
}
int minVal(Node *root)
{
    if (root == NULL)
        return INT_MAX;
    int leftMin = minVal(root->left);
    int rightMin = minVal(root->right);
    int min = INT_MAX;
    if (leftMin > rightMin)
    {
        min = rightMin;
    }
    else
        min = leftMin;
    int finalMin = min < root->val ? min : root->val;
    return finalMin;
}
int levels(Node *root)
{

    if (root == NULL)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
int height(Node *root)
{
    return (levels(root) - 1);
}

void levelOrderQueue(Node *root)
{
    // also called breadth first search
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << temp->val << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
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
    display(a);
    cout << endl;
    // cout << sumOfTreeNodes(a) << " " << endl;
    // cout << size(a) << endl;

    // cout << maxVal(a) << " " << endl;
    // cout << prodOfTreeNodes(a) << endl;
    // cout << minVal(a) << " " << endl;
    // cout << levels(a) << " " << endl;
    // cout << height(a) << " " << endl;
    levelOrderQueue(a);
}