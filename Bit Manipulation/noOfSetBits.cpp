#include<iostream>
using namespace std;

int main(){

    int n = 7;
    int cnt = 0;
    while(n > 0){
        n = (n & (n-1));
        cnt++;
    }
    cout << "Number of set bits in n : " << cnt << endl;
}