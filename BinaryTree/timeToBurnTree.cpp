#include<iostream> 
#include<map>
#include<unordered_map>
#include<queue> 
using namespace std;
template<class T>

 class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

int solve(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent_track, BinaryTreeNode<int>* target)
{
    unordered_map<BinaryTreeNode<int>*, bool> burned;
    queue< BinaryTreeNode<int>* > q;
    burned[target] = true;
    q.push(target);
    int time = 0;
    while(!q.empty())
    {
        int size = q.size();
        bool flag = false;
        for(int i=0; i<size; i++)
        {
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            if(node -> left && !burned[node -> left])
            {
                flag = true;
                burned[node -> left] = true;
                q.push(node -> left);
            }
            if(node -> right && !burned[node -> right])
            {
                flag = true;
                burned[node -> right] = true;
                q.push(node -> right);
            }
            if(parent_track[node] && !burned[parent_track[node]])
            {
                flag = true;
                burned[parent_track[node]] = true;
                q.push(parent_track[node]);
            }
        }
        if(flag) 
            time++; 
    }
    return time;
}

BinaryTreeNode<int>* create_parentmap(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent_track, int start)
{
    queue<BinaryTreeNode<int>* > q;
    q.push(root);
    BinaryTreeNode<int>* target;
    while(!q.empty())
    {
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        
        if(start == node -> data)
            target = node;

        if(node -> left)
        {
            parent_track[node -> left] = node;
            q.push(node -> left);
        }    
        if(node -> right)
        {
            parent_track[node -> right] = node;
            q.push(node -> right);
        } 
    }
    return target;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent_track;
    BinaryTreeNode<int>* target = create_parentmap(root, parent_track, start);
    int time = solve(parent_track, target);
    return time;
}
