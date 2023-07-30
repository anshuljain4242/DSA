#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at 
most k. After partitioning, each subarray has their values changed to become the maximum 
value of that subarray.
Return the largest sum of the given array after partitioning. 

Input: arr = [1,15,7,9,2,5,10], k = 3
partitions at [1 15| 7 9 2| 5 10] -> [15 15 9 9 9 10 10] sum = 77
partitions at [1 15 7| 9 | 2 5 10] -> [15 15 15 9 10 10 10] sum = 84 
Find max sum
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
*/

// Memoization
int f(int i, int n, int k, vector<int>& arr, vector<int>& dp){
    // Base Case
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int maxi = INT_MIN;
    int len = 0;
    int maxSum = INT_MIN;
    for(int j=i; j<min(n, i+k); j++){
        len++;
        maxi = max(maxi, arr[j]);

        int sum = len*maxi + f(j+1, n, k, arr, dp);
        maxSum = max(maxSum, sum);
    }
    return dp[i] = maxSum;
}
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return f(0, n, k ,arr, dp);
}

// Tabulation
int maxSumAfterPartitioningT(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n+1, 0);

    for(int i=n-1; i>=0; i--){
        int maxi = INT_MIN;
        int len = 0;
        int maxSum = INT_MIN;
        for(int j=i; j<min(n, i+k); j++){
            len++;
            maxi = max(maxi, arr[j]);

            int sum = len*maxi + dp[j+1];
            maxSum = max(maxSum, sum);
        }
        dp[i] = maxSum;
    }
    return dp[0];
}