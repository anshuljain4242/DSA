#include<vector>
#include<iostream>
using namespace std;

/*
You are given N balls numbered from 1 to N and there are N baskets numbered from 1 to N in 
front of you, the ith basket is 
meant for the ith ball. Calculate the number of ways in which no ball goes into its 
respective basket.
No element should be placed at the same index.
ex - arr[0,1,2]
Possible Derangements are - [2,0,1] and [1,2,0] i.e. 2
*/

// Memoization
int mod =1e9+7;
long long int f(int i, vector<int>& dp){
    if(i == 1)  return 0;
    if(i == 2)  return 1;

    if(dp[i] != -1) return dp[i];
    long long int ans = (i-1) * (f(i-1, dp) + f(i-2, dp));

    return dp[i] = ans%mod;
        
}

long long int countDerangements(int n) {
    vector<int> dp(n+1, -1);
    return f(n, dp);
}

// Tabulation
long long int countDerangementsT(int n) {
    vector<long long int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i= 3; i<=n; i++){
        long long int ans = ((i-1) * ((dp[i-1]%mod + dp[i-2]%mod)%mod)%mod);
        dp[i] = ans;
    }
    return dp[n];
}

// Space Optimization
long long int countDerangementsS(int n) {
    
    long long int a = 0;
    long long int b = 1;
    
    for(int i= 3; i<=n; i++){
        long long int curr = ((i-1) * ((a%mod + b%mod)%mod)%mod);
        a = b;
        b = curr;
    }
    return b%mod;
}