#include<iostream>
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

class Solution {
  public:
    int countNodes(struct Node* tree)
    {
        if(tree == NULL)
            return 0;
        
        int ans = 1 + countNodes(tree -> left) + countNodes(tree -> right);
        return ans;
    }
    
    bool isCBT(struct Node* tree, int idx, int cnt)
    {
        if(tree == NULL)
            return true;
         
        if(idx >= cnt)
            return false;
            
        else
        {
            bool leftChild = isCBT(tree -> left, 2*idx+1, cnt);
            bool rightChild = isCBT(tree -> right, 2*idx+2, cnt);
            return leftChild && rightChild;
        }
    }
    
    bool isMaxOrder(struct Node* tree)
    {
        if(tree -> left == NULL && tree -> right == NULL)
            return true;
        
        if(tree -> right == NULL)
            return tree -> data > tree -> left -> data;
        else
        {
            return (tree -> data > tree -> left -> data) && (tree -> data > tree -> right -> data)
                && (isMaxOrder(tree -> left)) && (isMaxOrder(tree -> right));
        }
    }
    
    bool isHeap(struct Node* tree) {
        int nodeCount = countNodes(tree);
        return isCBT(tree,0, nodeCount) && isMaxOrder(tree);
    }
};