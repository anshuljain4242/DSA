#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> modifyQueue(queue<int> &q, int k) {
    stack<int> s;

    for(int i=0; i<k; i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    for(int i=0; i<q.size()-k; i++){
        q.push(q.front());
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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    modifyQueue(q,k);
    print(q);

    // cout<<"Size of queue is: "<<q.size()<<endl;
    // cout<<"Front of queue is: "<<q.front()<<endl;

    // q.pop();
    // cout<<"Size of queue is: "<<q.size()<<endl;
    // cout<<"Front of queue is: "<<q.front()<<endl;
    // if(q.empty()){
    //     cout<<"Queue is empty"<<endl;
    // }
    // else{
    //     cout<<"Not empty"<<endl;
    // }

    

    return 0;
}


