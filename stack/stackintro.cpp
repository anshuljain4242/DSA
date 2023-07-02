#include<iostream>
#include<stack>
using namespace std;

class Stack{

    public:
        int top;
        int *arr;
        int size;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    
    void push(int ele){
        if(size - top > 1){
            top++;
            arr[top] = ele;
        }
        else{
            cout << "Stack Overflow!" <<endl;
        }
    }
    
    void pop(){
        if(top >= 0){
            top--; 
        }
        else{
            cout << "Stack Underflow!" << endl;
        }
    }

    int peek(){
        if(top >= 0 && top < size){
            return arr[top];
        }
        else{
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;    
    }
};
void print(stack<int> s){
    if(s.empty())
        return;

    int x = s.top();
    s.pop();
    print(s);

    cout<<x<<" ";
    s.push(x);    
}


void deleteMiddle(stack<int>&inputStack,int count, int size) {
   if(count == size/2){
      inputStack.pop();
      return;
   }

   int num = inputStack.top();
   inputStack.pop();

   deleteMiddle(inputStack, count+1, size);
   inputStack.push(num);

}

void insertAtBottom(stack<int> &stack, int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }

    int k = stack.top();
    stack.pop();

    insertAtBottom(stack, num);
    stack.push(k);

}

void reverseStack(stack<int> &stack) {
    // Write your code here

    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, num);

}

void sortedInsert(stack<int> &stack, int num){
     if(stack.empty() || (!stack.empty() && stack.top() < num)){
        stack.push(num);
        return;
     }

     int n = stack.top();
     stack.pop();
      
    sortedInsert(stack,num);
    stack.push(n);

}

void sortStack(stack<int> &stack)
{
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    sortedInsert(stack, num);
}

int main(){

    //STL
    stack<int> s;

    // s.push(2);
    // s.push(4);
    // s.pop();
    // cout << "Printing top element: " << s.top() << endl;
    
    // if(s.empty()){
    //     cout << "stack is empty" << endl;
    // }
    // else{
    //     cout << "stack is not empty" << endl;
    // }
    // cout<<"Size of stack is: " << s.size() << endl;


    // Stack st(5);
    s.push(8);
    s.push(22);
    s.push(25);
    s.push(50);
    print(s);
    cout<<endl;
    // st.pop();
    int count = 0;
    int N = s.size();
    // deleteMiddle(s, count, N);
    // cout<<st.isEmpty() <<endl;
    // cout << st.peek() << endl;
    // cout<<"After deleting the middle element"<<endl;
    reverseStack(s);
    print(s);
    cout<<endl;
    sortStack(s);
    print(s);
    return 0;
}