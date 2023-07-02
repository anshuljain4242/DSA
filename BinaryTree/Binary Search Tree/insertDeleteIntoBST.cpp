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

class Solution
{
public:

    // Insert a node in a BST
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {

        if (root == NULL)
            return new TreeNode(val);
        TreeNode *curr = root;
        while (true)
        {
            if (val < curr->val)
            {
                if (curr->left != NULL)
                    curr = curr->left;
                else
                {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (curr->right != NULL)
                    curr = curr->right;
                else
                {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }

    // Delete a node from BST

    TreeNode *findLastRight(TreeNode *root)
    {
        if (root->right == NULL)
            return root;
        return findLastRight(root->right);
    }

    TreeNode *helper(TreeNode *root)
    {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;

        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;

        if (root->val == key)
            return helper(root);

        TreeNode *dumy = root;
        while (root != NULL)
        {
            if (root->val > key)
            {
                if (root->left != NULL && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                    root = root->left;
            }
            else
            {
                if (root->right != NULL && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                    root = root->right;
            }
        }
        return dumy;
    }
};