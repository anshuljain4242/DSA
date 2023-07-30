#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Given a binary tree of size  N, a node, and a positive integer k., Your task is to 
complete the function kthAncestor(), the function should return the kth ancestor of 
the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note: It is guaranteed that the node exists in the tree.
*/

struct Node
{
	int data;
	struct Node *left, *right;
};
void create_parent(Node *root, unordered_map<int, int>& parent_track){
    parent_track[root -> data] = -1;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr -> left){
            parent_track[curr -> left -> data] = curr -> data;
            q.push(curr -> left);
        }
        if(curr -> right){
            parent_track[curr -> right -> data] = curr -> data;
            q.push(curr -> right);
        }
    }
}
int kthAncestor(Node *root, int k, int node)
{
    if(root -> data == node) return -1;
    
    unordered_map<int, int> parent_track;
    create_parent(root, parent_track);
    int count = 0;
    
    while(node != -1){
        node = parent_track[node];
        count++;
        if(count == k)
            break;
    }
    return node;

}