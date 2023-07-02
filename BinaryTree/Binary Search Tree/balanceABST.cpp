#include <iostream>
#include <vector>
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

class Solution
{
public:
    void inorderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    TreeNode *balanceBSThelper(int s, int e, vector<int> inorder)
    {
        if (s > e)
            return NULL;

        int mid = (s + e) / 2;
        TreeNode *node = new TreeNode(inorder[mid]);
        node->left = balanceBSThelper(s, mid - 1, inorder);
        node->right = balanceBSThelper(mid + 1, e, inorder);
        return node;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        vector<int> inorder;
        inorderTraversal(root, inorder);
        int start = 0;
        int end = inorder.size() - 1;
        return balanceBSThelper(start, end, inorder);
    }
};