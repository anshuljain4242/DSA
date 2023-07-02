#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void create_parentmap(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left)
            {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track;
        create_parentmap(root, parent_track);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> que;
        que.push(target);
        visited[target] = true;
        int dis = 0;
        while (!que.empty())
        {
            int size = que.size();
            if (dis++ == k)
                break;

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = que.front();
                que.pop();

                if (curr->left && !visited[curr->left])
                {
                    que.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right])
                {
                    que.push(curr->right);
                    visited[curr->right] = true;
                }

                if (parent_track[curr] && !visited[parent_track[curr]])
                {
                    que.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }

        vector<int> ans;
        while (!que.empty())
        {
            TreeNode *curr = que.front();
            que.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};