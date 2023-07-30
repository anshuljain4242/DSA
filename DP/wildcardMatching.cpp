#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).


*/

// Memoization
bool helper(int i, int j, string s, string p, vector<vector<int> >& dp){

    // base case
    if(j < 0 && i < 0) return true;
    if(j < 0 && i >= 0) return false;
    if(i < 0 && j >= 0){
        for(int k=j; k>=0; k--){
            if(p[k] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s[i] == p[j] || p[j] =='?')
        return dp[i][j] = helper(i-1, j-1, s, p, dp);
    if(p[j] == '*')
        return dp[i][j] = helper(i, j-1, s, p, dp) || helper(i-1, j, s, p, dp);
    return dp[i][j] = false;        
}
bool isMatch(string s, string p) {
    int n = s.length();
    int m = p.length();
    vector<vector<int> > dp(n, vector<int>(m, -1));
    return helper(n-1, m-1, s, p, dp);
}

// Tabulation
bool isMatchT(string s, string p) {
    int n = s.length();
    int m = p.length();
    vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));

    dp[0][0] = true;
    for(int i=1; i<=n; i++)
        dp[i][0] = false;
    for(int j=1; j<=m; j++){
        bool fl = true;
        for(int k=1; k<=j; k++){
            if(p[k-1] != '*'){
                fl =  false;
                break;
            }      
        }
        dp[0][j] = fl;
    }    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            if(s[i-1] == p[j-1] || p[j-1] =='?')
                dp[i][j] = dp[i-1][j-1];
            else if(p[j-1] == '*')
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}

// Space Optimization
 bool isMatchS(string s, string p) {
    int n = s.length();
    int m = p.length();
    vector<bool> prev(m+1, false), curr(m+1, false);

    prev[0] = true;
    for(int j=1; j<=m; j++){
        bool fl = true;
        for(int k=1; k<=j; k++){
            if(p[k-1] != '*'){
                fl =  false;
                break;
            }      
        }
        prev[j] = fl;
    }    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            if(s[i-1] == p[j-1] || p[j-1] =='?')
                curr[j] = prev[j-1];
            else if(p[j-1] == '*')
                curr[j] = curr[j-1] || prev[j];
            else curr[j] = false;
        }
        prev = curr;
    }
    return prev[m];
}