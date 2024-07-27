#include <iostream>
#include <queue>

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
    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n)
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
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        i += 2;
    }
    return root;
}
int sizeOfTree(Node *root)
{
    if (!root)
        return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}
bool isMax(Node *root)
{
    if (!root)
        return true;
    if (root->left && root->val < root->left->val)
        return false;
    if (root->right && root->val < root->right->val)
        return false;
    return (isMax(root->left) && isMax(root->right));
}
bool isCBT(Node *root)
{
    int size = sizeOfTree(root);
    int count = 0;
    queue<Node *> q;
    q.push(root);
    while (count < size)
    {
        Node *temp = q.front();
        q.pop();

        count++;

        if (temp)
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp != NULL)
            return false;
        q.pop();
    }
    return true;
}
int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, INT_MIN};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = construct(arr, n);
    if (isCBT(root) && isMax(root))
        cout << "Yes it is a max heap";
    else
        cout << "No it is not a max heap";
}