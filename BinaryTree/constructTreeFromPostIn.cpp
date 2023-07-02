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

TreeNode* constructTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> inMap)
    {
        if(postStart > postEnd || inStart > inEnd)  
            return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRootIdx = inMap[root -> val];
        int numsLeft = inRootIdx - inStart;

        root -> left = constructTree(postorder, postStart, postStart + numsLeft-1, inorder, inStart, inRootIdx -1, inMap);
        root -> right = constructTree(postorder, postStart + numsLeft, postEnd-1, inorder, inRootIdx+1, inEnd, inMap);
    
        return root;
    }
    

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++)
            inMap[inorder[i]] = i;

        TreeNode* root = constructTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;    
    }