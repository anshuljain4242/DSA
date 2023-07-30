#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Count number of ways an expression can yield a true

#define ll long long
int mod = 1000000007;
int f(int i, int j, int isTrue, string & exp, vector<vector<vector<ll> > >& dp){
    //Base Case
    if(i > j) return 0;

    if(i == j){
        if(isTrue == 1) return exp[i] == 'T';
        else return exp[i] == 'F';
    }

    if(dp[i][j][isTrue] != -1) 
        return dp[i][j][isTrue];

    // Ways
    ll ways = 0;
    for(int idx=i+1; idx<=j-1; idx+=2)
    {
        ll lT = f(i, idx-1, 1, exp, dp);
        ll lF = f(i, idx-1, 0, exp, dp);
        ll rT = f(idx+1, j, 1, exp, dp);
        ll rF = f(idx+1, j, 0, exp, dp);

        if(exp[idx] == '&'){
            if(isTrue)
                ways = (ways + (lT * rT)%mod)%mod;
            else    
                ways = (ways + (lT * rF)%mod + (lF * rT)%mod + (lF * rF)%mod)%mod;    
        }
        else if(exp[idx] == '|'){
            if(isTrue)
                ways = (ways + (lT * rT)%mod + (lT * rF)%mod + (lF * rT)%mod)%mod;
            else
                ways = (ways + (lF * rF)%mod)%mod;     
        }
        else if(exp[idx] == '^'){
            if(isTrue)
                ways = (ways + (lT * rF)%mod + (lF * rT)%mod)%mod;
            else 
                ways = (ways + (lT * rT)%mod + (lF * rF)%mod)%mod;    
        }
    }
    return dp[i][j][isTrue] = ways;  
}
int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<ll> > > dp(n, vector<vector<ll> >(n, vector<ll>(2, -1)));
    return f(0, n-1, 1, exp, dp);
}