#include <iostream>
#include <queue>
#include <climits>
#include <unordered_map>
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
void topview(Node *root)
{
    if (!root)
        return;
    pair<Node *, int> r;
    queue<pair<Node *, int>> q; // first is for node and second is the level
    unordered_map<int, int> m;  // first is for levels and second for value of node
    // so first is put the values of root in the queue
    r.first = root;
    r.second = 0; // the level of root is 0
    // we do not need to push it to the map, we will now do bfs
    q.push(r);
    while (q.size() > 0)
    {
        Node *temp = (q.front()).first;
        int level = (q.front()).second;
        // so now I have the pair of root, now my goal is to go left and write and then mark their level as -1 when the go left and +1 when they go right
        q.pop(); // pop it as we used to do in bfs simple

        // now just see if this node with this value is not present in the map then simply insert it in the map

        if (m.find(level) == m.end())
        {
            m[level] = temp->val;
        }

        if (temp->left)
        {
            q.push({temp->left, level - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, level + 1});
        }
    }
    // now when we are here so basically right now, we have our answer but in random order,
    // i mean, we have all the values which comes first (on basis of levels) and those are in  the map,
    // now to print the top view we have to print the values of the levels from most negative to most postive

    int minLevel = INT_MAX;
    int maxLevel = INT_MIN;
    for (auto c : m)
    {
        cout << c.second << " ";
        minLevel = min(minLevel, c.first);
        maxLevel = max(maxLevel, c.first);
    }

    cout << minLevel;
    cout << endl;
    cout << maxLevel;
    cout << endl;
    // now I have the values, and also the minimum level and the maximum level
    for (int i = minLevel; i <= maxLevel; i++)
    {
        cout << m[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = construct(arr, n);
    levelOrderQueue(root);
    cout << endl;
    topview(root);
}