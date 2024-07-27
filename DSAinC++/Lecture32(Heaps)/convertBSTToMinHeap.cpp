#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int value) : val(value) {}
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
void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    Node *curr = root;

    while (curr)
    {
        if (!curr->left)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of curr
            Node *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            // Make curr as the right child of its inorder predecessor
            if (!pred->right)
            { // if pred->right is NULL, thus it's not linked with curr so link it
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // Revert the changes made in the 'if' part to restore the original tree
                // here pred->right is not NULL, thus it can be only curr, so unlink it
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
}
void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void preorder(Node *root, vector<int> &arr, int &i)
{
    if (!root)
        return;
    root->val = arr[i++];
    preorder(root->left, arr, i);
    preorder(root->right, arr, i);
}
int main()
{
    int arr[] = {10, 5, 16, 1, 8, 12, 20};
    int n = sizeof(arr) / 4;
    Node *root = construct(arr, n);
    levelOrderQueue(root);
    cout << endl;
    vector<int> ino;
    inorder(root, ino);
    print(ino);
    // now we will make this array a min Heap using preorder
    int i = 0;
    preorder(root, ino, i);
    levelOrderQueue(root);
}
