#include<iostream>
using namespace std;

bool checkPalindrome(int binarr[32],int s, int e){
    if(s>=e)
        return 1;
    if(binarr[s]!=binarr[e])
        return 0;
    else    
        checkPalindrome(binarr,s+1,e-1);
}

int main(){
    int num;
    cin>>num;
    int binarr[32];
    int i=0;
    while(num>0){
        binarr[i] = num%2;
        num = num/2;
        i++;
    }
    int count=0;
    int newarr[10];
    for(int j=i-1; j>=0; j--){
        cout<<binarr[j]<<" ";
        newarr[j] = binarr[j];
        
        count++;
    }
    cout<<checkPalindrome(newarr,0,count-1);
}