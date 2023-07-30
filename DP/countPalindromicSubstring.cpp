#include<iostream>
#include<string>
using namespace std;

int countSubstrings(string s) {
    int n = s.length();
    bool dp[n][n];
    int count = 0;
    for(int gap=0; gap<n; gap++){
        for(int i=0, j=gap; j<n; i++, j++){

            if(gap == 0) dp[i][j] = true;
            else if(gap == 1) dp[i][j] = s[i] == s[j];
            else{
                if(s[i] == s[j] && dp[i+1][j-1] == true)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;    
            }
            if(dp[i][j] == true)
                count++;
        }
    }
    return count;
}