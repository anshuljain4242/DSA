#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 vector<TreeNode*> helper(int n){
        if(n % 2 == 0)
            return {};

        if(n == 1)
            return {new TreeNode()};


        vector<TreeNode*> ans;
        for(int i=1; i<n; i+=2){
            vector<TreeNode*> left = helper(i);
            vector<TreeNode*> right = helper(n-i-1);

            for(auto l:left){
                for(auto r:right){
                    TreeNode* root = new TreeNode(0, l, r);
                    ans.push_back(root);
                }
            }  
        }   
        return ans;     
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        // vector<TreeNode*> dp(n, NULL);
        return helper(n);
    }