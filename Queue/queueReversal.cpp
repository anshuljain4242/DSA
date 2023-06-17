#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> rev(queue<int> &q)
{
    // add code here.
    stack<int> s;
    
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}
// using recursion
// void reverse(queue<int> &q){
//     if(q.empty())
//         return;
    
//     int k = q.front();
//     q.pop();
//     reverse(q);
//     q.push(k);
// }

int main(){

    queue<int> q;
    q.push(10);
    q.push(15);
    q.push(20);

    rev(q);

    cout<<q.front();

    return 0;
}