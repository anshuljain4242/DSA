#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
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
int canYouMake(string &str, string &ptr)
{
    int lcs = longestCommonSubsequence(str, ptr);
    return str.size() + ptr.size() - 2*lcs;
}