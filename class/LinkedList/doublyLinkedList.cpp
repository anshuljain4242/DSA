#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

    ~Node(){
        int item  = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data: "<< item << endl;
    }

};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<" -> ";
        temp = temp -> next; 
    }
    cout<<endl;
}

int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head, int data){

    if(head == NULL){
        Node* node = new Node(data);
        head = node; 
    }
    else{
         Node* node = new Node(data);
        node -> next = head;
        head -> prev = node;
        head = node;
        //node -> prev = NULL;
    }
}

void insertAtEnd(Node* &head, int data){
    if(head == NULL){
        Node* node = new Node(data);
        head = node; 
    }
    else{
        Node* node = new Node(data);
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = node;
        node -> prev = temp;
    }
}

void insertAtPosiiton(Node* &head, int pos, int data){
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }
    int n = 1;
    Node*  temp = head;
    while(n != pos-1){
        n++;
        temp = temp -> next;
    }
    if(temp -> next == NULL){
        insertAtEnd(head,data);
        return;
    }
    else{
        Node* node = new Node(data);
        node -> next = temp -> next;
        temp -> next -> prev = node;
        temp -> next = node;
        node -> prev = temp;
        
    }
}

void deleteNode(Node* &head, int pos){
    if(pos == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;

        delete temp;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        int n = 1;
        while(n < pos){
            n++;
            prev = curr;
            curr = curr -> next;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtHead(head, 20);
    //print(head);
    insertAtEnd(head,30);
    insertAtHead(head, 40);
    insertAtPosiiton(head, 2, 15);
    print(head);
    deleteNode(head, 1);

    print(head);
    cout<< endl;

    cout<<"Length of list is: "<<getLength(head);
}