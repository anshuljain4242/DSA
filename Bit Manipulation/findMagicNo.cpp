#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n = 6;

    int i = 1;
    int ans = 0;
    int cnt = 0;
    while(n > 0){
        int lastdig = n & 1;
        cnt++;
        ans += lastdig * pow(5,i);
        n = n >> 1;
        i++;
    }
    cout << "Nth magic No - " << ans;
    cout<<endl;
    cout <<"Number of time while loop is running : " << cnt <<endl;
     
}