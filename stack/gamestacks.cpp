/*
Alexa has two stacks of non-negative integers, stack a[n] and stack b[m]  where index 0 denotes the top of the stack. 
Alexa challenges Nick to play the following game:

In each move, Nick can remove one integer from the top of either stack a or stack b.
Nick keeps a running sum of the integers he removes from the two stacks.
Nick is disqualified from the game if, at any point, his running sum becomes greater than some integer maxSum given at the beginning of the game.
Nick's final score is the total number of integers he has removed from the two stacks.
Given a, b, and maxSum for g games, find the maximum possible score Nick can achieve.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int twoStacks(int maxSum, std::vector<int> a, std::vector<int> b) {
    int sum=0;
    int i=0,j=0,k=0;
    int cnt = 0;
    std::vector<int> c;
    while(sum < maxSum && i<a.size() && j<b.size()){
        if(a[i] <= b[j]){
            c.push_back(a[i]);
            cnt++;
            sum += c[k];
            i++;
            
            k++;
            cout<<"k at"<<k<<endl;
            
        }
        else{
            c.push_back(b[j]);
            cnt++;
            sum += c[k];
            j++;
            k++;
            cout<<"k at"<<k<<endl;
        }

    }
    while(sum<maxSum && a.size()){
        c.push_back(a[i]);
        sum += c[k];
        i++;
        k++;
        cnt++;
        cout<<"k at"<<k<<endl;
    }
    while(sum<maxSum && b.size()){
        c.push_back(b[j]);
        sum += c[k];
        j++;
        k++;
        cnt++;
        cout<<"k at"<<k<<endl;
    }

    for(int k=0;k<c.size(); k++){
        cout<<c[k]<<" ";
    }
    cout<<endl;
    return cnt-1;
}

int main(){
    int maxSum;
    cin>>maxSum;
    int len1,len2;

    cout<<"Enter size of h1: ";
    cin>>len1;
    std::vector<int> h1;
    int k;
    for(int i=0; i<len1; i++){
        cin>>k;
        h1.push_back(k);
    }
    cout<<"h1 is: - "<<endl;
    for(int i=0; i<len1; i++){
        cout<<h1.at(i)<<" ";
    }
    cout<<endl;

    cout<<"Enter size of h2: ";
    cin>>len2;
    std::vector<int> h2;

    for(int i=0; i<len2; i++){
        cin>>k;
        h2.push_back(k);
    }
    cout<<"h2 is: - "<<endl;
    for(int i=0; i<len2; i++){
        cout<<h2.at(i)<<" ";
    }
    cout<<endl;


    cout<<twoStacks(maxSum, h1, h2);
    cout<<endl;
}