#include<iostream>
using namespace std;

int inversionCount(int arr[10], int n){
    int count=0;
    for(int i=0; i<n; i++){
        int j=i+1;
        while(j<n){
            if((arr[i] <= arr[j]) && (i<j)){
                j++;
            }
            else{
                swap(arr[i],arr[j]);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int arr[3] = {1,10,20};
    int n = 3; 
    cout<<inversionCount(arr,n);
}