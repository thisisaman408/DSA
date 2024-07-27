#include <iostream>
#include <queue>
#include <climits>
#include <stack>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int value) : val(value), left(NULL), right(NULL) {}
};
Node *construct(int arr[], int n)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    while (q.size() > 0 && i < n)
    {
        Node *temp = q.front();
        q.pop();
        Node *left;
        Node *right;

        if (arr[i] != INT_MIN)
            left = new Node(arr[i]);
        else
            left = NULL;
        if ((i + 1) != n && arr[i + 1] != INT_MIN)
            right = new Node(arr[i + 1]);
        else
            right = NULL;

        temp->left = left;
        temp->right = right;

        if (left != NULL)
            q.push(left);
        if (right != NULL)
            q.push(right);
        i += 2;
    }
    return root;
}
void leftBoundary(Node *root)
{
    if (!root || (!root->left && !root->right))
        return;

    cout << root->val << " ";
    leftBoundary(root->left);
    if (!root->left)
        leftBoundary(root->right);
}

void leafNodes(Node *root)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
        cout << root->val << " ";
    leafNodes(root->left);
    leafNodes(root->right);
}

void rightBoundary(Node *root)
{
    if (!root || (!root->left && !root->right))
        return;

    rightBoundary(root->right);
    if (!root->right)
        rightBoundary(root->left);
    cout << root->val << " ";
}
void levelOrderQueue(Node *root)
{
    leftBoundary(root);
    leafNodes(root);
    rightBoundary(root->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17, INT_MIN, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23,
                 INT_MIN, 24, 25, 26, 27, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = construct(arr, n);
    // levelOrderQueue(root);

    levelOrderQueue(root);
}
