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

Node* solve(Node* first, Node* second){

    //if only one element
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }

    Node* prev1 = first;
    Node* curr1 = prev1 -> next;
    Node* curr2 = second;
    Node* next2 = NULL;
    
    while(curr1 != NULL && curr2 != NULL){
        
        if((curr2 -> data >= prev1 -> data) && (curr2 -> data <= curr1 -> data)){
            prev1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = curr1;

            prev1 = curr2;
            curr2 = next2;
        }
        else{
            prev1 = curr1;
            curr1 = curr1 -> next;

            if(curr1 == NULL){
                prev1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}


Node* sortTwoLists(Node* first, Node* second)
{
    // Write your code here.
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    

    if(first -> data <= second -> data){
        solve(first,second);
    }
    else{
        solve(second, first);
    }
    
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

int main(){
    Node* first = new Node(2);
    Node* second = new Node(4);
    sortTwoLists(first,second);
    print(first);
    return 0;
}