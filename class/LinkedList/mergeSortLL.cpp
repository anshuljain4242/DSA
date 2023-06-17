#include <iostream>


using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << val << endl;
    }
};

void insertAtEnd(Node *&head, int item)
{
    if (head == NULL)
    {
        Node *node = new Node(item);
        head = node;
    }
    else
    {
        Node *node = new Node(item);
        Node *temp = head;
        while (temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

Node* findMid(Node* &head){
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }    
    return slow;
}

Node* merge(Node* left, Node* right){
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }   
    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }   
    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }  

    ans = ans -> next;
    return ans;
}

Node* mergeSort(Node* &head) {

    //base case
    if(head == NULL || head -> next == NULL){
        return head;
    }

    //break linked list into 2 halves, after finding mid
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both right and left halves
    Node* result = merge(left,right);
    return result;

}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *node1 = new Node(15);

    Node *head = node1;

    insertAtEnd(head, 10);

    insertAtEnd(head, 20);

    insertAtEnd(head, 50);
    insertAtEnd(head, 40);
    
    
    print(head);
    Node* ans = mergeSort(head);
    print(ans);
    
}