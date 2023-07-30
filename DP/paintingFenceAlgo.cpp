#include<vector>
#include<iostream>
using namespace std;

/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have 
the same color. Since the answer can be large return it modulo 10^9 + 7.

Input : n = 2 k = 4
Output : 16
Explanation: We have 4 colors and 2 posts.
Ways when both posts have same color : 4 
Ways when both posts have diff color :4(choices for 1st post) * 3(choices for 2nd post) = 12
*/


int mod = 1e9+7;

int add(int a, int b){
    return (a%mod + b%mod)%mod;
}

int mul(int a, int b){
    return ((a%mod) * 1LL * (b%mod))%mod;
}

int f(int n, int k, vector<int>& dp){
    if(n == 1)
        return k;
    if(n == 2)
        return add(k, mul(k, k-1));

    if(dp[n] != -1) return dp[n]%mod;

    int ans = add(mul(f(n-2, k, dp), k-1), mul(f(n-1, k, dp), k-1));       
    return dp[n] = ans%mod;
}

int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);
    return f(n, k, dp);
}
