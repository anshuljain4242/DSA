/*
Interleave first half of the queue with the second half.
i.e. {11,12,13,14,15,16,17,18} -> {11,15,12,16,13,17,14,18}
*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> interleave(queue<int> &q){
    
    //USING QUEUE
    // int half = q.size()/2;
    // queue<int> newq;

    // for(int i=0; i<half; i++){
    //     newq.push(q.front());
    //     q.pop();
    // }

    // while(!newq.empty()){
    //     q.push(newq.front());
    //     q.push(q.front());
    //     newq.pop();
    //     q.pop();
    // }
    // return q;

    //USING STACK
    int half = q.size()/2;
    stack<int> s;
    //1. first half of q into stack
    for(int i=0; i<half; i++){
        s.push(q.front());
        q.pop();
    }

    //2. push stack elements into q 
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    //3. push and pop q elements into q
    for(int i=0; i<half; i++){
        q.push(q.front());
        q.pop();
    }

    //4. first half of q into stack 
    for(int i=0; i<half; i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        q.push(q.front());
        s.pop();
        q.pop();
    }
    return q;
}

void print(queue<int> q){
    while (!q.empty()){
		cout<<" "<<q.front();
		q.pop();
	}
	cout<<endl;
}

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    print(q);
    cout<<"After interleaving"<<endl;
    interleave(q);
    print(q);

    return 0;
}