#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

// Memoization
int helper(int i, int j, string word1, string word2, vector<vector<int> >& dp){
    // Base Cases
    if(i < 0) return j+1;
    if(j < 0) return i+1;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(word1[i] == word2[j])
        return dp[i][j] = helper(i-1, j-1, word1, word2, dp);

    int ins = 1 + helper(i, j-1, word1, word2, dp);  
    int del = 1 + helper(i-1, j, word1, word2, dp);
    int rep = 1 + helper(i-1, j-1, word1, word2, dp);

    return dp[i][j] =  min(ins, min(del, rep));  
}
int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    vector<vector<int> > dp(n, vector<int>(m, -1));
    return helper(n-1, m-1, word1, word2, dp);
}

// Tabulation
int minDistanceT(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));

    for(int j=0; j<=m; j++)
        dp[0][j] = j;
    for(int i=0; i<=n; i++)
        dp[i][0] = i;    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                int ins = 1 + dp[i][j-1];  
                int del = 1 + dp[i-1][j];
                int rep = 1 + dp[i-1][j-1];

                dp[i][j] =  min(ins, min(del, rep));
            }
                
        }
    }    
    return dp[n][m];
}

// Space Optimization
int minDistanceS(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    vector<int> prev(m+1, 0), curr(m+1, 0);

    for(int j=0; j<=m; j++)
        prev[j] = j;

    for(int i=1; i<=n; i++){
        curr[0] = i;
        for(int j=1; j<=m; j++){
            if(word1[i-1] == word2[j-1])
                curr[j] = prev[j-1];
            else{
                int ins = 1 + curr[j-1];  
                int del = 1 + prev[j];
                int rep = 1 + prev[j-1];

                curr[j] =  min(ins, min(del, rep));
            }
                
        }
        prev = curr;
    }    
    return prev[m];
}