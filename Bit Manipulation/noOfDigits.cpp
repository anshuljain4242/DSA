#include<iostream>
#include<math.h>
using namespace std;

// number of digits of a number in  base b

int main(){
    int n = 34521;

    int b = 8;

    int ans = (int)(log(n) / log(b)) + 1;
    cout<<ans<<endl;
}