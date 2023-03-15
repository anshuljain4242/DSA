#include<iostream>
using namespace std;

int bubble(int A[6],int n){
    int temp,i,j;
    for(i=1;i<n;i++){
        //for round 1 to n-1
        for(j=0;j<n-i;j++){
           if(A[j]>A[j+1]){
                temp = A[j];
                A[j]= A[j+1];
                A[j+1] = temp; 
            }
        }
    } 
    cout<<"Sorted array is:- "<<endl;
    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
        
}

int main(){
    int n,i,A[6];
    cout<<"Enter size of array- ";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    bubble(A,n);
}