#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class NodeValue{
    public:
    // maxNode is the largest node in the left subtree which should be smaller than the root node
    // minNode is the smallest node in the right subtree which should be larger than the root node
        int maxNode, minNode, maxSize;
        NodeValue(int largest, int smallest, int size){
            maxNode = largest;
            minNode = smallest;
            maxSize = size;
        }
};
class Solution{
    private:
    NodeValue largestBstHelper(Node* root){
        if(!root)
            return NodeValue(INT_MIN, INT_MAX, 0);
        
        // get values from left and right subtree of current tree
        auto left = largestBstHelper(root -> left);
        auto right = largestBstHelper(root -> right);
        
        // valid BST
        if(left.maxNode < root -> data && root -> data < right.minNode)
            return NodeValue(max(root -> data, right.maxNode), min(root -> data, left.minNode), left.maxSize + right.maxSize + 1);
            
        return NodeValue(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));
    }
    
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return largestBstHelper(root).maxSize;
    }
};