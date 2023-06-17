#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    Node* next;
    int data;

    Node(int data){
        this-> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int item = this -> data;
        if (this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout <<"Memory free for node with data: "<< item << endl;
    }

};

//No need of head in circular list
void insertNode(Node* &tail, int ele, int data){
    //assuming that tail is present in the list
    
    //empty list
    if(tail == NULL){
        Node* node = new Node(data);
        tail = node;
        node -> next = node;
    }
    else{
        Node* curr = tail;
        while(curr -> data != ele){
            curr = curr -> next;
        }
        Node* node = new Node(data);
        node -> next = curr -> next;
        curr -> next = node;
    }
}

void deleteNode(Node* &tail, int val){
    if(tail == NULL){
        cout << "List is empty!!";
    }
    else{
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != val){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //if 1 node LL
        if(curr == prev){
            tail = NULL;
        }
        //>=2 node LL
        else if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

bool isCircular(Node* head){
    // Write your code here.

    //empty list
    if(head == NULL){
        return true;
    }

    //list with 1 or >1 nodes

    Node* temp = head -> next;
    while(temp != head && temp != NULL){
        temp = temp -> next;
    }    

    if(temp == head)
        return true;

    return false;
}    

bool detectLoop(Node* head){
    if(head == NULL)
        return false;

    map<Node* , bool> visited;

    Node* temp = head;

    while(temp != NULL){

        //cycle is present
        if(visited[temp] == true){
            return true;
        }

        visited[temp]  = true;
        temp = temp -> next;
    } 
    return false;   
}

Node* split(Node* &tail){
    
}

void print(Node* &tail){
    Node* temp = tail;
    if(tail == NULL){
        cout<<"List is empty"<< endl;
        return;
    }
    do{
        cout << tail -> data << " -> ";
        tail = tail -> next;
    }while(tail != temp);
    cout<<endl;
}

int main(){
    
    Node* tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);
    
    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);
    
    insertNode(tail, 5, 6);
    print(tail);

    deleteNode(tail, 3);
    print(tail);


    return 0;
}