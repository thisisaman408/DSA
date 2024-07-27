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

int levels(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void levelOrderQueue(Node *root, int n)
{
    int count = 0;
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (q.size() == 0)
            count++;
        if (temp == NULL)
        {
            if (count < n)
                cout << "null ";
        }
        else
        {
            cout << temp->val << " ";
            q.push(temp->left);
            q.push(temp->right);
        }
    }
}

void postOrderIterative(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (st.size() > 0)
    {
        Node *temp = st.top();
        st.pop();

        cout << temp->val << " ";
        if (temp && temp->left)
            st.push(temp->left);
        if (temp && temp->right)
            st.push(temp->right);
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
void preOrderIterative(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (st.size() > 0)
    {
        Node *temp = st.top();
        st.pop();

        cout << temp->val << " ";
        if (temp && temp->right)
            st.push(temp->right);
        if (temp && temp->left)
            st.push(temp->left);
    }
}
void inOrderIterative(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (st.size() > 0)
    {
        Node *temp = st.top();
        st.pop();
        cout << temp->val << " ";
        if (temp && temp->right)
            st.push(temp->right);
        if (temp && temp->left)
            st.push(temp->left);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = construct(arr, n);
    int p = levels(root);
    levelOrderQueue(root, p);
    cout << endl;
    preOrderIterative(root);
    cout << endl;
    postOrderIterative(root);
    cout << endl;
}