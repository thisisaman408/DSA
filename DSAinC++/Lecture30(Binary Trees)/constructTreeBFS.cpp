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
int main()
{
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = construct(arr, n);
    levelOrderQueue(root);
}