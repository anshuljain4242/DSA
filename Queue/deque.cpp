#include<iostream>
#include<queue>
using namespace std;

//Doubly ended queue

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size = n;
        front = rear = -1;
        arr = new int[n];
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Check Full
        if(isFull()){
            return false;
        }

        else if(isEmpty()){
            front = rear = 0;
        }

        else if(front == 0 && rear != size-1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Check Full
        if(isFull()){
            return false;
        }

        else if(isEmpty()){
            front = rear = 0;
        }

        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
        return true;

    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front == -1)
            return true;
        else
            return false;    
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }

    }
};
int main(){

    Deque *d = new Deque(4);
    d->pushFront(3);
    d->pushFront(8);
    d->pushRear(11);
    cout<<d->getRear()<<endl;


    // deque<int> d;

    // d.push_front(12);
    // // d.push_front(10);
    // d.push_back(14);
    // cout<< d.front() << endl;
    // cout<< d.back() << endl;

    // d.pop_front();
    // cout<< d.front() << endl;
    // cout<< d.back() << endl;
    
    // d.pop_back();
    // if(d.empty()){
    //     cout<<"queue is empty"<<endl;
    // }
    // else{
    //     cout<<"queue is not empty"<<endl;
    // }
    return 0;
}