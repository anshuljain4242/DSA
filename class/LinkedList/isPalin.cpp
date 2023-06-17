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
Node* getMiddle(Node* &head){
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
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

bool isPalin(Node* &head){

    if(head == NULL || head -> next == NULL){
        return true;
    }

     
    // vector<int> arr;
    // Node *temp = head;
    // while(temp != NULL){
    //     arr.push_back(temp -> data);
    //     temp = temp -> next;
    // }

    // int s = 0;
    // int e = arr.size() - 1;

    // while(s <= e){
    //     if(arr[s] != arr[e]){
    //         return false;
    //     }
    //     s++;
    //     e--;
    // }
    // return true;

    //step 1: get middle node
    Node* mid = getMiddle(head);
    
    //step2 : reverse the list after the middle node
    Node* temp2 = mid -> next;
    mid -> next = reverseLL(temp2);

    //step 3 : Compare the 2 halves
    Node* head1 = head;
    Node* head2 = mid -> next;

    while(head2 != NULL){
        if(head1 -> data != head2 -> data){
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    //step 4 : reverse the reversed half back to normal(repeat step 2)
    temp2 = mid -> next;
    mid -> next = reverseLL(temp2);

    return true;
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
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);

    
    print(head);
    // cout<< getMiddle(head) -> data;

    cout << isPalin(head);
   
    return 0;
}