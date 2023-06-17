#include <iostream>
#include <map>
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

int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void addToList(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node* &head){

    //updating the nodes' data
    // int zerocount = 0, onecount = 0, twocount = 0;
    // Node* temp  = head;
    // while(temp != NULL){
    //     if(temp -> data == 0)
    //         zerocount++;
    //     else if(temp -> data == 1)
    //         onecount++;
    //     else if(temp -> data == 2)    
    //         twocount++;

    //     temp = temp -> next;            
    // }
    
    // temp  = head;
    // while(temp != NULL){
    //     if(zerocount != 0){
    //         temp -> data = 0;
    //         zerocount--;
    //     }
    //     else if(onecount != 0){
    //         temp -> data = 1;
    //         onecount--;
    //     }
    //     else if(twocount != 0){
    //         temp -> data = 2;
    //         twocount--;
    //     }
    //     temp = temp -> next;
            
    // }
    // return head;
    
    //data replacement not allowed

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    //created separate list for 0s,1s,2s
    while(curr != NULL){
        int val = curr -> data;
        if(val == 0){
            addToList(zeroTail, curr);
        }
        else if(val == 1){
            addToList(oneTail,curr);
        }
        else if(val == 2){
            addToList(twoTail,curr);
        }

        curr = curr -> next;
    }

    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }
    else{
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    head = zeroHead -> next;
    // delete(zeroHead);
    // delete(oneHead);
    // delete(twoHead);
    return head;
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

    Node *node1 = new Node(1);
    
    Node *head = node1;    
    insertAtEnd(head, 0);
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 2);

    
    print(head);
    
    sortList(head);
    print(head);
    return 0;
}