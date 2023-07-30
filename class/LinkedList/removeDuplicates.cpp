#include <iostream>
#include <map>
#include<unordered_set>

using namespace std::chrono;
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
//from sorted list
Node* removeDuplicates(Node* &head){
    if(head == NULL)
        return NULL;
    
    Node* temp = head;
    
    while(temp != NULL){
        if((temp -> next != NULL) && (temp -> data == temp -> next -> data) ){
            Node* next_next = temp -> next -> next;
            Node* node_to_delete = temp -> next;
            delete(node_to_delete);
            temp -> next = next_next;
        }
        else{
            temp = temp -> next;
            
        }
        
    }
    
    return head;
}
//from unsorted list
Node* removeUnDuplicates(Node* &head){
    // if(head == NULL)
    //     return NULL;

    // Node* temp = head;
    // set< int> visited;

    // while(temp -> next != NULL){
    //     visited[temp -> data] = true;

    //     if(visited[temp -> next -> data] == true){
    //         // Node* nodeToDelete = temp -> next;
    //         Node* next_next = temp -> next -> next;
    //         temp -> next = next_next;

    //     }
    //     else{
    //         temp = temp -> next;
    //     }
        
    // }
    // return head;

    if(head -> next == NULL)
        return head;

    unordered_set<int> mp;
    
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        Node* forw = curr -> next;
        // if element exixts in map
        if(mp.find(curr -> data) != mp.end()){
            prev -> next = forw;
            curr = forw;
        }
        else{
            mp.insert(curr -> data);
            prev = curr;
            curr = forw;
            
        }
    }
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

    Node *node1 = new Node(20);

    Node *head = node1;

    insertAtEnd(head, 10);

    insertAtEnd(head, 20);

    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    // print(head);

    // cout<<"Head: " << head -> data << endl;
    // cout<<endl<<endl;

    removeUnDuplicates(head);
    print(head);
    
}