#include<iostream>
using namespace std;

int countdistinctwaystoreachstairs(int n){
    if(n<0)
        return 0;

    if(n==0)
        return 1;

    int ways = countdistinctwaystoreachstairs(n-1) + countdistinctwaystoreachstairs(n-2);
    return ways;      

}

void saydigits(int num, string arr[]){

    
    if(num==0)
        return ;

    int digit = num % 10;
    num = num/10;

    saydigits(num,arr);

    cout<<arr[digit]<<" ";

}
int main(){
    /*
    int n;
    cin>>n;
    cout<<countdistinctwaystoreachstairs(n);
    */

   string arr[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

    int n;
    cin>>n;
    cout<<endl;
    saydigits(n,arr);
    cout<<endl;



}