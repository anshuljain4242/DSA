#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode *constructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> inMap)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    TreeNode *root = new TreeNode(preorder[preStart]);

    int inRootIdx = inMap[root->val];
    int numsLeft = inRootIdx - inStart;

    root->left = constructTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRootIdx - 1, inMap);
    root->right = constructTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRootIdx + 1, inEnd, inMap);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> inMap;

    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }

    TreeNode *root = constructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    return root;
}