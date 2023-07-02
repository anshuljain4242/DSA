#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        // if the first element of the queue is null means one level completed,
        //  this is to print the traversal in a tree like structure

        if (temp == NULL)
        {
            cout << endl;
            // if queue is not empty means that all children of the node are in the queue, and
            //  now a separator(NULL) is pushed in the q, which tells the start of next level
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
void reverseLevelOrderTraversal(node *root)
{
    queue<node *> q;
    stack<node *> s;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        s.push(temp);
        q.pop();

        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
    }

    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}

// INORDER - RECURSIVE
void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// PREORDER - RECURSIVE
void preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// POSTORDER - RECURSIVE
void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// PRE-IN-POST ORDER - ITERATIVE
void preInPostTraversal(node *root)
{
    stack<pair<node *, int> > st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
        return;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1})
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
            post.push_back(it.first->data);
    }
}

int noOfLeafNodes(node *root)
{

    int count = 0;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left == NULL && temp->right == NULL)
            count++;
    }
    return count;
}
int height(node *node)
{

    if (node == NULL)
        return 0;

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;
}

// CHECK FOR BALANCED BINARY TREE

// BRUTE FORCE : TC -> O(N^2)

bool isBalanced(node *root)
{

    // base case
    if (root == NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if (left == true && right == true && diff == true)
        return true;
    else
        return false;
}

// OPTIMAL 1

pair<bool, int> isBalancedFast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (left.first && right.first && diff)
        ans.first = true;
    else
        ans.first = false;
    return ans;
}

// OPTIMAL 2

int dfsHeight(node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return max(leftHeight, rightHeight) + 1;
}

bool isTreeBalanced(node *root)
{
    // if dfsHeight returns a binary tree then true else false
    return dfsHeight(root) != -1;
}

// DIAMETER OF BINARY TREE (longest distance between two end nodes)

int helperHeight(node *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int leftHeight = helperHeight(root->left, diameter);
    int rightHeight = helperHeight(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(node *root)
{
    int diameter = 0;
    helperHeight(root, diameter);
    return diameter;
}

// Maximum Path Sum

int solve(node *root, int &maxiSum)
{
    if (root == NULL)
        return 0;

    int leftSum = max(0, solve(root->left, maxiSum));
    int rightSum = max(0, solve(root->right, maxiSum));
    maxiSum = max(maxiSum, leftSum + rightSum + root->data);
    return root->data + max(leftSum, rightSum);
}
int maxPathSum(node *root)
{
    int maxiSum = INT_MIN;
    solve(root, maxiSum);
    return maxiSum;
}

// SUM TREE OR NOT(every node is a sum of its left or right subtree)

pair<bool, int> isSum(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = isSum(root->left);
    pair<bool, int> right = isSum(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool sum = root->data == left.second + right.second;

    pair<bool, int> ans;
    if (leftAns && rightAns && sum)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

// ZIGZAG OR SPIRAL TRAVERSAL
vector<int> zigZagTraversal(node *root)
{

    vector<int> result;

    if (root == NULL)
        return result;

    queue<node *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {

            node *frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
        leftToRight = !leftToRight;
        // for(auto i: ans){
        //     result.push_back(i);
        // }
    }
    return result;
}

// BOUNDARY TRAVERSAL
void traverseLeft(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseLeft(root->left, ans);

    ans.push_back(root->data);
}
vector<int> boundary(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // traverse left part
    traverseLeft(root->left, ans);

    // traverse leaf nodes;

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);

    return ans;
}

// VERTICAL ORDER TRAVERSAL
vector<int> verticalOrder(node *root)
{
    map<int, map<int, vector<int> > > nodes;
    queue<pair<node *, pair<int, int> > > q; // second pair is of(horizontal distance, level)
    vector<int> ans;
    // vector<int> arr;
    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int> > temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        nodes[hd][level].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
    }
    // for(auto i : nodes){

    //     for(auto j : i.second){

    //         for(auto k : j.second){

    //             ans.push_back(k);
    //         }
    //     }
    // }
    return ans;
}

// TOP VIEW OF BINARY TREE
vector<int> topView(node *root)
{

    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> m;
    queue<pair<node *, int> > q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second;

        if (m.find(hd) == m.end())
        {
            m[hd] = frontNode->data;
        }

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }
    // for(auto i : m){
    //     ans.push_back(i.second);
    // }
    return ans;
}

// LEFT VIEW OF BINARY TREE
void solveLeft(node *root, vector<int> &ans, int level)
{

    if (root == NULL)
        return;

    // we entered a new level
    if (level == ans.size())
        ans.push_back(root->data);

    solveLeft(root->left, ans, level + 1);
    solveLeft(root->right, ans, level + 1);
}

vector<int> leftView(node *root)
{
    // Your code here
    vector<int> ans;
    solveLeft(root, ans, 0);
    return ans;
}

// RIGHT VIEW OF BINARY TREE
void solveRight(node *root, vector<int> &ans, int level)
{

    if (root == NULL)
        return;

    // we entered a new level
    if (level == ans.size())
        ans.push_back(root->data);

    solveRight(root->right, ans, level + 1);
    solveRight(root->left, ans, level + 1);
}

vector<int> rightView(node *root)
{
    // Your code here
    vector<int> ans;
    solveRight(root, ans, 0);
    return ans;
}

// DIAGONAL VIEW OF BINARY TREE

vector<int> diagonal(node *root)
{

    vector<int> ans;
    queue<node *> q;

    if (root == NULL)
        return ans;

    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        while (temp)
        {
            if (temp->left)
                q.push(temp->left);
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

// Symmetric Binary Tree
bool isSymmetricHelp(node *left, node *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    if (left->data != right->data)
        return false;

    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}
bool isSymmetric(node *root)
{
    return root == NULL || isSymmetricHelp(root->left, root->right);
}

// Path to given node
bool getPath(node *root, vector<int> &ans, int B)
{
    if (root == NULL)
        return false;

    ans.push_back(root->data);

    if (root->data == B)
        return true;
    if (getPath(root->left, ans, B) || getPath(root->right, ans, B))
        return true;

    ans.pop_back();
    return false;
}

vector<int> solve(node *A, int B)
{
    vector<int> ans;
    if (A == NULL)
        return ans;
    getPath(A, ans, B);
    return ans;
}

// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
void solve(node *root, int len, int &maxLen, int sum, int &maxSum)
{

    if (root == NULL)
    {

        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (maxLen == len)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;

    solve(root->left, len + 1, maxLen, sum, maxSum);
    solve(root->right, len + 1, maxLen, sum, maxSum);
}

int sumOfLongRootToLeafPath(node *root)
{
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, len, maxLen, sum, maxSum);

    return maxSum;
}

// LOWEST COMMON ANCESTOR IN A BINARY TREE
node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    node *leftAns = lca(root->left, n1, n2);
    node *rightAns = lca(root->right, n1, n2);

    if (leftAns == NULL)
        return rightAns;
    else if (rightAns == NULL)
        return leftAns;
    else
        return root;
}

// Width of Binary Tree
int widthOfBinaryTree(node *root)
{
    if (!root)
        return 0;

    int ans = 0;
    queue<pair<node *, int> > q;
    q.push({root, 0});
    while (!q.empty())
    {
        int minn = q.front().second;
        int size = q.size();
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int curr_idx = q.front().second - minn;
            node *node = q.front().first;
            q.pop();
            if (i == 0)
                first = curr_idx;
            if (i == size - 1)
                last = curr_idx;
            if (node->left)
                q.push({node->left, (long long)2 * curr_idx + 1});
            if (node->right)
                q.push({node->right, (long long)2 * curr_idx + 2});
        }
        ans = max(ans, last - first + 1);
    }

    return ans;
}

// CHILD SUM PROPERTY
void changeTree(node *root)
{
    if (root == NULL)
        return;

    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;
    if (root->left || root->right)
        root->data = total;
}

// COUNT COMPLETE TREE NODES 
int findRightHeight(node* node)
{
    int height = 0;
    while(node)
    {
        height++;
        node = node -> right;
    }
    return height;
}

int findLeftHeight(node* node)
{
    int height = 0;
    while(node)
    {
        height++;
        node = node -> left;
    }
    return height;
}
int countNodes(node* root) 
{
    if(root == NULL) return 0;

    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);
        
    if(lh == rh)
        return (1 << lh) - 1;  // left shift lh means 2^lh

    return 1 + countNodes(root -> left) + countNodes(root -> right);    
}

int countNodesEasy(node* root) 
{
    if(root == NULL) return 0;
        return 1 + countNodes(root -> left) + countNodes(root -> right);    
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1  -1

    // levelOrderTraversal(root);
    // reverseLevelOrderTraversal(root);
    cout << "Inorder Traversal" << endl;
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal" << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal" << endl;
    postorder(root);
    cout << endl;

    cout << "No of leaf nodes are - " << noOfLeafNodes(root) << endl;

    bool ans = isBalanced(root);
    cout << ans << endl;
    return 0;
}