#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == NULL)
        return NULL;

    TreeNode *ans;
    while (true)
    {
        int curr = root->val;
        if (p->val < curr && q->val < curr)
            root = root->left;
        else if (p->val > curr && q->val > curr)
            root = root->right;
        else
        {
            ans = root;
            break;
        }
    }
    return ans;
}