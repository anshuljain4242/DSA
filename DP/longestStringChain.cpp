#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool ifPredecessor(string &a, string &b){
    
    int len1 = a.length();
    int len2 = b.length();

    if(len2 + 1 != len1) return false;
    int i=0, j=0;
    while(i<len1){
        if(j < len2 && a[i] == b[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(i == len1 && j == len2) return true;
    return false;
}
bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}
int longestStrChain(vector<string> &arr)
{
    sort(arr.begin(), arr.end(), comp);
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxi = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(ifPredecessor(arr[i], arr[j]) && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}