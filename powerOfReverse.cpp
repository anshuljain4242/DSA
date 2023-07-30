#include<iostream>
using namespace std;

int mod=1000000007;
long long power(int N,int R)
{
    if(R==1) return N;
    if(R==0) return 1;
    
    long long val=power(N,R/2)%mod;
    val=(val*val)%mod;
    
    if(R&1) val=(val*N)%mod;
    
    return val;
}
