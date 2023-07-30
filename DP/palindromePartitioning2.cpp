#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
*/
bool isPalin(int i, int j, string& s){

    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++; j--;
    }
    return true;
}
int f(int i, int n, string s, vector<int>& dp){
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];
    int minCost = INT_MAX;

    for(int j=i; j<n; j++){
        if(isPalin(i, j, s)){
            int cost = 1 + f(j+1, n, s, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
int minCut(string s) {
    int n = s.length();
    vector<int> dp(n+1, -1);
    return f(0, n, s, dp) - 1;
}

// Tabulation
bool isPalinT(int i, int j, string& s){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++; j--;
    }
    return true;
}

int minCutT(string s) {
    int n = s.length();
    vector<int> dp(n+1, 0);

    for(int i=n-1; i>=0; i--){
        int minCost = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalinT(i, j, s)){
                int cost = 1 + dp[j+1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0]-1;
}