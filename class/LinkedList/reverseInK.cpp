// Linked list : 1 -> 2 -> 3 -> 4 -> 5 
// Array B : 3 3 5
// if B[i] > no.of nodes then reverse remaining list and ignore rest of the array

// output : 3 -> 2 -> 1 -> 5 -> 4




//Reverse list in K groups
// [1,2,3,4,5,6]  K = 2

// [2,1,4,3,6,5]
#include <iostream>
using namespace std;

//RECURSIVE APPROACH

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
    };
Node* kReverse(Node* head, int k){

    //base case
    if(head == NULL){
        return NULL;
    }

    //step1 : reverse 1st K node
    Node* forw =  NULL;
    Node* prev = NULL;
    Node* curr = head;
    int cnt = 0;

    while(curr != NULL && cnt < k){
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
        cnt++;
    }

    //step2 ; Recursion will solve the rest

    if(forw != NULL){
        head -> next = kReverse(forw,k);
    }

    //step3 : return head of reversed list
    return prev;

}

//ITERATIVE APPROACH

Node* kReverseGroup(Node* head, int k){

    //base case
    if(head == NULL || k == 1){
        return head;
    }

    Node* dummy = new Node(0);
    dummy -> next = head;

    Node* curr = dummy, *forw = dummy, *prev = dummy;

    int count = 0;

    while(curr -> next != NULL){
        curr = curr -> next;
        count++;
    }

    while(count >= k){
        curr = prev -> next;
        forw = curr -> next;
        for(int i = 1; i < k; i++){
            curr -> next = forw -> next;
            forw -> next = prev -> next;
            prev -> next = forw;
            forw = curr -> next;
        }
        prev = curr;
        count -= k;
    }

    return dummy -> next;
}