#include<iostream>
#include<string>
using namespace std;

// TC -> O(n^2), SC -> O(n^2)
string longestPalinSubstring(string s) {
    int n = s.length();
    bool dp[n][n];
    int count = 0;
    int len = 0;
    int r = 0;
    int c = 0;
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
            if(dp[i][j] && len < gap+1){
                len = gap+1;
                r = i;
            }     
        }
    }
    return s.substr(r, len);
}

// TC -> O(n^2), SC -> O(1)
string check(string s,int left,int right){
    int n=s.length();
    while(left>=0 && right<n){
        if(s[left]!=s[right]) break; 
        left--; right++;
    }
    return s.substr(left+1,right-left-1);
}
string longestPalinSubstringB(string str){
    string longest;
    int n=str.size();
    
    for (int i = 0; i < n; i++) {
        string even = check(str, i, i + 1);
        if (even.size() > longest.size())
            longest = even;
    }

    for (int i = 0; i < n; i++) {
        string odd=check(str,i,i);
        if(odd.size()>longest.size()) 
            longest=odd;
    }

    return longest;
}