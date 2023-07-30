#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
*/
int mod=1e9+7;

// Memoization
int helper(int i, int j , string s, string t, vector<vector<int> >& dp){
    if(j < 0) return 1;
    if(i < 0) return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    if(s[i] == t[j])
        return dp[i][j] = helper(i-1, j-1, s, t, dp) + helper(i-1, j, s, t, dp);
    else
        return dp[i][j] = helper(i-1, j, s, t, dp);        
}
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<vector<int> > dp(n, vector<int>(m, -1));
    return helper(n-1, m-1, s, t, dp);
}

// Tabulation
int numDistinctT(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    } 
    for(int j=1; j<=m; j++){
        dp[0][j] = 0; 
    }    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])% mod;
            else
                dp[i][j] = dp[i-1][j]; 
        }
    }
    return dp[n][m];        
}

// Space Optimization
int numDistinctS(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<int> prev(m+1, 0), curr(m+1, 0);

    prev[0] = curr[0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1])
                curr[j] = (prev[j-1] + prev[j])% mod;
            else
                curr[j] = prev[j]; 
        }
        prev = curr;
    }
    return prev[m];        
}

// Space Optimised to 1 arrray
int numDistinctSS(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<int> prev(m+1, 0);

    prev[0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=m; j>=1; j--){
            if(s[i-1] == t[j-1])
                prev[j] = (prev[j-1] + prev[j])% mod; 
        }
    }
    return prev[m];        
}
