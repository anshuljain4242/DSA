#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int val = this -> data;
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory is free for node with data " << val << endl;
    }
};

void insertAtHead(Node* &head,int item){
    Node* temp = new Node(item);
    temp -> next =  head;
    head = temp;
}

void insertAtEnd(Node* &tail, int item){
    Node* temp = new Node(item);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int item){
    
    if(pos == 1){
        insertAtHead(head,item);
        return;
    }
    
    int n = 1;
    Node* curr = head;
    Node* temp = new Node(item);
    while(n != pos-1){
        curr = curr -> next;
        n++;
    }

    if(curr -> next == NULL){
        insertAtEnd(tail,item);
        return;
    }
    temp -> next = curr -> next;
    curr -> next = temp;

}

void deleteNode(int pos, Node* &head){
    

    //if node to be deleted is the first one
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        /*Node* curr = head;
        Node* prev = NULL;

        int n = 1;
        while(n < pos){
            prev = curr;
            curr = curr -> next;
            n++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
*/
        int n = 1;
        Node* temp = head;
        while(n < pos-1){
            temp = temp -> next;
            n++;
        }

        Node* curr = temp -> next;

        temp -> next = curr -> next ;
        curr -> next = NULL;
        delete curr;
    }
        
    
}

void print(Node* &head){
    Node*  temp = head;
    while(temp != NULL){
        cout << temp -> data <<" -> ";
        temp = temp ->  next;
    }
    cout << endl;
}

int main(){
    
    Node* node1 = new Node(10);
    
    // cout << node1 -> data << " -> ";
    // cout << node1 -> next <<endl; 

    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    //print(head);

    //insertAtHead(head,20);
    insertAtEnd(tail,20);
    //print(head);

    //insertAtHead(head,30);
    insertAtEnd(tail,30);
    //print(head);

    insertAtPosition(head, tail, 4, 25);
    print(head);

    deleteNode(4, head);
    print(head);
    cout<<"Head: " << head -> data << endl;
    cout<<"Tail: " << tail -> data << endl;

    return 0;
}