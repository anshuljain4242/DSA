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

class Solution{
  public:
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* succ = NULL;
        while(root != NULL)
        {
            if(root -> data <= x -> data)
                root = root -> right;
            else
            {
                succ = root;
                root = root -> left;
            }
        }
        return succ;
    }

    Node * inOrderPredeccessor(Node *root, Node *x)
    {
        Node* pre = NULL;
        while(root != NULL)
        {
            if(root -> data <= x -> data)
            {
                pre = root;
                root = root -> right;
            }    
            else
                root = root -> left;
        }
        return pre;
    }
};