#include <iostream>
#include <vector>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int value) : left(NULL), right(NULL), val(value) {}
};
void preorder(TreeNode *root, vector<TreeNode *> &ans)
{
    if (!root)
        return;
    ans.push_back(root);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

void helper(TreeNode *root, vector<TreeNode *> &preOrder)
{
    preorder(root, preOrder);
    for (int i = 0; i < preOrder.size() - 1; ++i)
    {
        preOrder[i]->right = preOrder[i + 1];
        preOrder[i]->left = NULL;
    }
    if (!preOrder.empty())
    {
        preOrder.back()->right = NULL;
        preOrder.back()->left = NULL;
    }
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<TreeNode *> preOrder(v.size());
    TreeNode *root = new TreeNode(v[0]);
    helper(root, preOrder);
}
