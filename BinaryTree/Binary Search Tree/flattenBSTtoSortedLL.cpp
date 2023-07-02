#include <iostream>
#include<vector>
using namespace std;

template <class T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
TreeNode<int> *flattenBST(int &i, vector<int> &in)
{
    if (i >= in.size())
        return NULL;

    TreeNode<int> *node = new TreeNode<int>(in[i++]);

    node->right = flattenBST(i, in);
    node->left = NULL;
    return node;
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> in;
    inorder(root, in);
    int i = 0;
    return flattenBST(i, in);
}