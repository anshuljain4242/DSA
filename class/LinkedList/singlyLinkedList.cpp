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

void insertAtHead(Node *&head, int item)
{
    Node *temp = new Node(item);
    temp->next = head;
    head = temp;
}

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

void insertAtPosition(Node *&head, Node *&tail, int pos, int item)
{

    if (pos == 1)
    {
        insertAtHead(head, item);
        return;
    }

    int n = 1;
    Node *curr = head;
    Node *temp = new Node(item);
    while (n != pos - 1)
    {
        curr = curr->next;
        n++;
    }

    if (curr->next == NULL)
    {
        insertAtEnd(tail, item);
        return;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void deleteNode(int pos, Node *&head)
{

    // if node to be deleted is the first one
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
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
        Node *temp = head;
        while (n < pos - 1)
        {
            temp = temp->next;
            n++;
        }

        Node *curr = temp->next;

        temp->next = curr->next;
        curr->next = NULL;
        delete curr;
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
void swapNodesAtK(Node *&head, int k)
{
    int n = getLength(head);
    int pos1 = 1;
    Node *node1 = head;
    Node *node2 = head;
    Node *prev2 = NULL;
    if (k == 1)
    {

        int pos2 = 1;
        while (pos2 < (n - k + 1))
        {
            pos2++;
            prev2 = node2;
            node2 = node2->next;
        }
        Node *temp = node1->next;
        node1->next = node2->next;
        prev2->next = node1;
        node2->next = temp;
        head = node2;
    }
    else
    {
        Node *prev1 = NULL;

        while (pos1 < k)
        {
            pos1++;
            prev1 = node1;
            node1 = node1->next;
        }

        int pos2 = 1;
        while (pos2 < (n - k + 1))
        {
            pos2++;
            prev2 = node2;
            node2 = node2->next;
        }
        Node *temp = node1->next;

        node1->next = node2->next;
        node2->next = temp;
        prev1->next = node2;
        prev2->next = node1;
    }
}
void swapValuesAtK(Node *&head, int k)
{
    int n = getLength(head);
    int pos1 = 1;
    Node *node1 = head;
    Node *node2 = head;
    // Node* prev2 = NULL;

    while (pos1 < k)
    {
        pos1++;
        node1 = node1->next;
    }

    int pos2 = 1;
    while (pos2 < (n - k + 1))
    {
        pos2++;
        node2 = node2->next;
    }

    swap(node1->data, node2->data);
}

void reverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    head = prev;
}

bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            cout << "Cycle is present at " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floydDetectLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *fast = head;
    Node *slow = head;

    while ((fast != NULL) && (slow != NULL))
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (fast == slow)
            return slow;
    }

    return NULL;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *intersection = floydDetectLoop(head);

    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void RemoveLoop(Node *head)
{
    if (head == NULL)
        return;

    Node *start = getStartingNode(head);

    Node *temp = start;

    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

Node *removeLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *fast = head;
    Node *slow = head;
    Node *now = head;
    Node *prev;

    while (fast != NULL && fast->next != NULL)
    {   
        //FCD
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;

        //starting node of loop using now pointer as head and prev pointer as previous of starting node
        if (fast == slow)
        {
            while (now != slow)
            {
                prev = slow;
                slow = slow->next;
                now = now->next;
            }
            
            //loop removal
            prev->next = NULL;
            break;
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

    Node *node1 = new Node(10);

    // cout << node1 -> data << " -> ";
    // cout << node1 -> next <<endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);

    // insertAtHead(head,20);
    insertAtEnd(head, 20);
    // print(head);

    // insertAtHead(head,30);
    insertAtEnd(head, 30);
    // print(head);

    // insertAtPosition(head, tail, 4, 25);
    // print(head);

    // deleteNode(4, head);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    // cout<<"Length is : "<<getLength(head)<<endl;
    // print(head);
    //  cout<<"Head: " << head -> data << endl;
    //  cout<<endl<<endl;

    // swapNodesAtK(head,1);
    // print(head);
    // swapValuesAtK(head,1);
    // print(head);
    // cout<<"Tail: " << tail -> data << endl;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;

    tail->next = head->next;
    if (detectLoop(head))
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "cycle is not present" << endl;
    }

    Node *loop = getStartingNode(head);
    cout << "Loop starting at : " << loop->data << endl;

    RemoveLoop(head);

    print(head);
    // reverseLL(head);
    // print(head);

    return 0;
}