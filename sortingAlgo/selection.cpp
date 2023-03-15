#include<iostream>
using namespace std;
int selec(int A[5], int n){
    int temp=0,i,j;
    for(i=0; i<n-1; i++){
        int minindex=i;
        for(j=i+1; j<n; j++){
            if(A[j]<A[minindex]){
                minindex=j;
                
            }      
        }
         temp = A[minindex];
            A[minindex] = A[i];
            A[i] = temp;    
      
        }
        cout<<"Sorted array is:- "<<endl;
        for(i=0;i<n;i++){
            cout<<A[i]<<" ";
        }
        
    }

int main(){
    int n,i,A[5];
    cout<<"Enter size of array- ";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    selec(A,n);
}