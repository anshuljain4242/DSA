#include<iostream>
using namespace std;

template<class T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ceil = -1;
    while (node != NULL)
    {
        if (node->data > x)
        {
            ceil = node->data;
            node = node->left;
        }
        else if (node->data < x)
        {
            node = node->right;
        }
        else if (node->data == x)
            return node->data;
    }
    return ceil;
}