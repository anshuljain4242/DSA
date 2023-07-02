#include<iostream>
#include<stack>
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

class BSTIterator{
    stack<TreeNode* > st;
    // reverse -> true - before
    // reverse -> false - next
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse)
            pushAll(temp -> right);
        else
            pushAll(temp -> left);
        return temp -> val;        
    }

private:
    void pushAll(TreeNode* node)
    {
        for(; node != NULL; )
        {
            st.push(node);
            if(!reverse)
                node = node -> left;
            else
                node = node -> right;    
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)
            return false;
        // next 
        BSTIterator l(root,false);
        // before
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while(i<j)
        {
            if(i + j == k)
                return true;
            else if(i + j < k)
                i = l.next();
            else
                j = r.next();    
        }
        return false;
    }
};
