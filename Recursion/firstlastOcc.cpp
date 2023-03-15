#include<iostream>
using namespace std;

int firstocc(int arr[7],int s, int e,int k){
    if(e>=s){
        int mid = s + (e-s)/2;
        if(((e==s || k > arr[mid-1]) && k == arr[mid]))
        return mid;
    
   
        if(k>arr[mid]){
            return firstocc(arr,mid+1,e,k);
        }
        else{
            return firstocc(arr,s,mid-1,k);
        }
    }
    return -1;
    
}

int lastocc(int arr[7],int s, int e,int n,int k){
    if(e>=s){
        int mid = s + (e-s)/2;
        if(((mid == n-1 || k < arr[mid+1]) && k == arr[mid]))
            return mid;
    
        else if(k>=arr[mid]){
            return lastocc(arr,mid+1,e,n,k);
        }
        else{
            return lastocc(arr,s,mid-1,n,k);
        }
    }
    return -1;
}

int main()
{   
    int arr[15] = {1,2}; 
    int n, k;
    cin>>n;
    cin>>k;
    int s=0;
    int e=n-1;
    int first = firstocc(arr,s,e,k);
    int second = lastocc(arr,s,e,n,k);
    
    cout<< first<< " "<<second;
            
}
