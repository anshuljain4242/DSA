#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Given an integer array arr and an integer difference, return the length of the longest 
subsequence in arr which is an arithmetic sequence such that the difference between 
adjacent elements in the subsequence equals difference.

Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
*/


int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    unordered_map<int, int> dp;

    int maxi = 1;

    for(int i=0; i<n; i++){
        int num = arr[i];
        if(dp.find(num - difference) != dp.end())
            dp[num] = 1 + dp[num - difference];
        else
            dp[num] = 1;
        maxi = max(maxi, dp[num]);
    }
    return maxi;
}