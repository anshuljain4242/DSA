#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(a==0)
        return b;

    return gcd(b%a,a); 
}
int commonFactors(int a, int b) {
        int max = gcd(a,b);
        cout<<max<<endl;
        int count = 0;
        for(int i=1; i <= max; i++){
            if(max%i ==0){
                count += 1;
            }
        }
        return count;
    }
int main(){
    int a,b;
    cin>>a;
    cin>>b;
    cout<<commonFactors(a,b);
}