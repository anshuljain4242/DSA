#include<iostream>
using namespace std;

int main(){
    int power = 6;
    int base = 3;

    int ans = 1;

    while(power > 0){
        if((power & 1) == 1)
            ans *= base;

        base *= base;
        power = power >> 1;    
    }
    cout << "3 ^ 6 = "<< ans <<endl;
}