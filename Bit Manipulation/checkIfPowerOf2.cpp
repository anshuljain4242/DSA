#include<iostream>
using namespace std;

int main(){
    int n = 1023;
    // fix for n = 0 

    bool ans = (n & (n-1)) == 0;
    cout << ans << endl;
}