#include <iostream>


using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
        this -> child = NULL;
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

Node* merge(Node* left, Node* right){
	if(left == NULL)
        return right;
    if(right == NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> child = left;
            temp = temp -> child;
            left = left -> child;
        }
        else{
            temp -> child = right;
            temp = temp -> child;
            right = right -> child;
        }
    }   
    if(left != NULL){
        temp -> child = left;        
    } 
	else{
		temp -> child = right;
	}  
   
    ans = ans -> child;
    return ans;
}
Node* flattenLinkedList(Node* head) 
{
	if(head == NULL)
		return head;
	Node* left = head;
	Node* right = head -> next;
	left -> next = NULL;

	//recursive call to rest of the linked list
	
	right = flattenLinkedList(right);
	
	Node* ans = merge(left, right);
	return ans;

}