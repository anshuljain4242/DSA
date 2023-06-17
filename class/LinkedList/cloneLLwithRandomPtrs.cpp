#include <iostream>
using namespace std;
#include<unordered_map> 

class Node
		{
		public:
		    int data;
		    Node *next;
		    Node *random;
		    Node(int data)
		    {
		        this->data = data;
		        this->next = NULL;
		        this->random = NULL;
		    }
		    ~Node()
		    {
		        if (next)
		        {
		            delete next;
		        }
		    }
		};


void insertAtTail(Node* &head, Node* &tail, int data){
	Node* newNode = new Node(data);
	if(head == NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	else{
		tail -> next = newNode;
		tail = newNode;
	}
}
Node *cloneLL(Node *head)
{
    
    
	// //step 1 : creat a clone list
	// Node* cloneHead = NULL;
	// Node* cloneTail = NULL;

	// Node* temp = head; 

	// while(temp != NULL){
	// 	int val = temp -> data;
	// 	insertAtTail(cloneHead, cloneTail, val);
	// 	temp = temp -> next;
	// }	

	// //step 2 : create a map

	// unordered_map<Node*, Node*> orgToNew;

	// Node* originalNode = head;
	// Node* cloneNode = cloneHead;

	// while(originalNode != NULL){
	// 	orgToNew[originalNode] = cloneNode;
	// 	originalNode = originalNode -> next;
	// 	cloneNode = cloneNode -> next;
	// }

	// originalNode = head;
	// cloneNode = cloneHead;

	// while(originalNode != NULL){
	// 	cloneNode -> random = orgToNew[originalNode -> random];
	// 	originalNode = originalNode -> next;
	// 	cloneNode = cloneNode -> next;
	// }

	// return cloneHead;
    


    //using O(1) SC

    //step 1 : creat a clone list
	Node* cloneHead = NULL;
	Node* cloneTail = NULL;

	Node* temp = head; 

	while(temp != NULL){
		int val = temp -> data;
		insertAtTail(cloneHead, cloneTail, val);
		temp = temp -> next;
	}

    //step 2: clone nodes add in between original nodes
	Node* originalNode = head;
	Node* cloneNode = cloneHead;
	

	while(originalNode != NULL && cloneNode != NULL){
		Node* saveOrg = originalNode -> next;
		originalNode -> next  = cloneNode;
		originalNode = saveOrg;

		Node* saveClone = cloneNode -> next;
		cloneNode -> next = originalNode;
		cloneNode = saveClone;
	
	}

	//step 3: random pointer copy
	temp = head;
	while(temp != NULL){
		if(temp -> next != NULL){

			temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
			
		}
		temp = temp -> next -> next;
		
	}
	
	//step 4: revert changes done in step2
	originalNode = head;
	cloneNode = cloneHead;
	while(originalNode != NULL && cloneNode != NULL){
		
		originalNode -> next = cloneNode -> next;
		originalNode = originalNode -> next;

		if(originalNode != NULL){
			cloneNode -> next = originalNode -> next;
		}
		
		cloneNode = cloneNode -> next;
	}

	//step 5: return ans
	return cloneHead;

}

int main(){



    return 0;
}