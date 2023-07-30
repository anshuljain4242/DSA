#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Memoization
int helper(int idx1, int idx2, string &text1, string &text2,  vector<vector<int> >& dp){

    // Base Case
    if(idx1 < 0 || idx2 < 0)
        return 0;

    if(dp[idx1][idx2] != -1)
        return  dp[idx1][idx2];

    if(text1[idx1] == text2[idx2])
        return dp[idx1][idx2] = 1 + helper(idx1-1, idx2-1, text1, text2, dp);
    
    return dp[idx1][idx2] = max(helper(idx1-1, idx2, text1, text2, dp), helper(idx1, idx2-1, text1, text2, dp));           
}
int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.size();
    int len2 = text2.size();

    vector<vector<int> > dp(len1, vector<int>(len2, -1));
    return helper(len1-1, len2-1, text1, text2, dp);
}

// Tabulation
int longestCommonSubsequenceT(string text1, string text2) {
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

// Space Optimization
int longestCommonSubsequenceS(string text1, string text2) {
    int len1 = text1.size();
    int len2 = text2.size();

    vector<int> prev(len2+1, 0), curr(len2+1, 0);

    for(int idx2 = 0; idx2 <= len2; idx2++)
        prev[idx2] = 0;


    for(int idx1 = 1; idx1 <= len1; idx1++){
        for(int idx2 = 1; idx2 <= len2; idx2++){
            if(text1[idx1-1] == text2[idx2-1])
                curr[idx2] = 1 + prev[idx2-1];
            else 
                curr[idx2] = max(prev[idx2], curr[idx2-1]);           
        }
        prev = curr;
    }        
    return prev[len2];
}

// Printing the longest commmon subsequence
void longestCommonSubsequenceP(string text1, string text2) {
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

    // Backtracking : TC -> O(len1 + len2)  
    int len = dp[len1][len2];
    string ans = "";
    for(int i=0; i<len; i++){
        ans += '$';
    }

    int index = len-1;
    int idx1 = len1;
    int idx2 = len2;
    while(idx1 > 0 && idx2 > 0){
        if(text1[idx1-1] == text2[idx2-1]){
            ans[index] = text1[idx1-1];
            index--;
            idx1--, idx2--;
        }
        else if(dp[idx1-1][idx2] > dp[idx1][idx2-1])
            idx1--;
        else            
            idx2--;    
    }
    cout<< ans;
}

int main(){
    string text1 = "abcde";
    string text2 = "bkdce";

    longestCommonSubsequenceP(text1, text2);
}

