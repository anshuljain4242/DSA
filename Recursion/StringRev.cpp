#include<iostream>
using namespace std;

string StringRev(string str, int s, int n){
    if(s==n/2)
        return str;

    swap(str[s],str[n-s-1]);
    return  StringRev(str, s+1,n);   
}

int main(){
    string str = "abbcdee";
    int n = str.length();
    cout<<StringRev(str,0,n);
}