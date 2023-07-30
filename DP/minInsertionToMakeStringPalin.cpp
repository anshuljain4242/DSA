#include<iostream>
#include<vector>
#include<string>
using namespace std;


int longestCommonSubsequenceP(string text1, string text2) {
    int len1 = text1.size();
    int len2 = text2.size();

    vector<vector<int> > dp(len1+1, vector<int>(len2+1, -1));

    for(int idx2 = 0; idx2 <= len2; idx2++)
        dp[0][idx2] = 0;
    for(int idx1 = 0; idx1 <= len1; idx1++)
        dp[idx1][0] = 0;

    for(int idx1 = 1; idx1 <= len1; idx1++){
        for(int idx2 = 1; idx2 <= len2; idx2++){
            if(text1[idx1-1] == text2[idx2-1])
                dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
            else 
                dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);           
        }
    }      
    return dp[len1][len2];
    }
int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return longestCommonSubsequenceP(s, t);
}
int minInsertions(string s) {
    int len = s.length();
    int lenPalSub = longestPalindromeSubseq(s);

    return len - lenPalSub;
}