#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
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

// Optimal : TC ->

void convertIntoSortedDLL(TreeNode *root, TreeNode* &head)
{
    if(root == NULL)
        return;

    convertIntoSortedDLL(root -> right, head);

    root -> right = head;
    if(head != NULL)
        head -> left = root;

    head = root;

    convertIntoSortedDLL(root -> left, head);
}

TreeNode *mergeLL(TreeNode* &head1, TreeNode* &head2)
{
    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data < head2 -> data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1 -> right;
            }
            else
            {
                tail -> right = head1;
                head1 -> left = tail;
                tail = head1;
                head1 = head1 -> right;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2 -> right;
            }
            else
            {
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head2 = head2 -> right;
            }
        }
    }
    while(head1 != NULL)
    {
        tail -> right = head1;
        head1 -> left = tail;
        tail = head1;
        head1 = head1 -> right;
    }
    while(head2 != NULL)
    {
        tail -> right = head2;
        head2 -> left = tail;
        tail = head2;
        head2 = head2 -> right;
    }
    return head;
}

int countNodes(TreeNode* head)
{
    int cnt = 0;
    TreeNode* temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp -> right;
    }
    return cnt;
}

TreeNode * sortedLLintoBST(TreeNode* &head, int n)
{
    if(n <= 0  || head == NULL)
        return NULL;

    TreeNode* leftTree = sortedLLintoBST(head, n/2);

    TreeNode* root = head;
    root -> left = leftTree;

    head = head -> right;

    root -> right = sortedLLintoBST(head, n - n/2 - 1);
    return root;
}


TreeNode *mergeBSTusingLL(TreeNode *root1, TreeNode *root2){
    
    // Step1 : convert BSTs into sorted LL in place
    TreeNode *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1 -> left = NULL;

    TreeNode *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2 -> left = NULL;

    // Step2 : merge 2 sorted LL
    TreeNode *head = mergeLL(head1, head2);

    // Step3: convert sorted LL into BST
    int n = countNodes(head);
    return sortedLLintoBST(head, n);
}


// Better : TC -> O(m+n), SC -> O(m+n)

void inorderTraversal(TreeNode *root, vector<int> &inorder)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

void merge(vector<int> &inorder1, vector<int> &inorder2, vector<int> &mergedInorder)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int m = inorder1.size();
    int n = inorder2.size();
    while (i < m && j < n)
    {
        if (inorder1[i] <= inorder2[j])
            mergedInorder[k++] = inorder1[i++];
        else
            mergedInorder[k++] = inorder2[j++];
    }
    while (i < m)
    {
        mergedInorder[k++] = inorder1[i++];
    }

    while (j < n)
    {
        mergedInorder[k++] = inorder2[j++];
    }
}

TreeNode *mergeBSThelper(int s, int e, vector<int> &mergedInorder)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    TreeNode *node = new TreeNode(mergedInorder[mid]);
    node->left = mergeBSThelper(s, mid - 1, mergedInorder);
    node->right = mergeBSThelper(mid + 1, e, mergedInorder);
    return node;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL)
        return root2;
    else if (root2 == NULL)
        return root1;
    else if (root1 == NULL && root2 == NULL)
        return NULL;

    // Step1 : Store inorder
    vector<int> inorder1, inorder2;
    inorderTraversal(root1, inorder1);
    inorderTraversal(root2, inorder2);

    // Step2 : Merge 2 sorted arrays(inorder1 and inorder2)
    vector<int> mergedInorder(inorder1.size() + inorder2.size());
    merge(inorder1, inorder2, mergedInorder);

    // Step3 : inorder to BST
    return mergeBSThelper(0, mergedInorder.size() - 1, mergedInorder);
}