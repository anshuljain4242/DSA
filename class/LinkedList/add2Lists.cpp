#include <iostream>
#include <map>
#include<vector>
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
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

Node* reverseLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forw = NULL;
    
    while(curr != NULL){
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

Node* add(Node* &first, Node* &second){

    Node* head = NULL;
    int dig = 0;
    int carry = 0;
    int sum = 0;
    while(first != NULL || second != NULL || carry != 0){

        int val1 = 0;
        if(first != NULL)
            val1 = first -> data;

        int val2 = 0;
        if(second != NULL)
            val2 = second -> data;    


        sum = carry + val1 + val2;

        dig = sum % 10;

        insertAtEnd(head,dig);  
        carry = sum/10;
  
        if(first != NULL)
            first = first -> next;

        if(second != NULL)    
            second = second -> next;
    }

    return head;
}

Node* addTwoLists(Node* &first, Node* &second){

    //step1 : reverse both the LL
    first = reverseLL(first);
    second = reverseLL(second);
    

    //step2 : traverse both the list and add the corresponding elements
    Node* ans = add(first,second);

    //step3:
    ans = reverseLL(ans);

    return ans;
  
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

    Node *node1 = new Node(4);
    Node *head1 = node1;
    insertAtEnd(head1, 5);

    Node *node2 = new Node(3);
    Node *head2 = node2;
    insertAtEnd(head2, 4);
    insertAtEnd(head2, 5);
    insertAtEnd(head2, 6);

    
    print(head1);
    print(head2);
    // cout<< getMiddle(head) -> data;

    
   Node* ans = addTwoLists(head1, head2);
   print(ans);
    return 0;
}