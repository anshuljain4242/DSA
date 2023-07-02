#include <iostream>
#include <vector>
using namespace std;

// Memoization
bool helper(int idx, int k, vector<vector<int> >& dp, vector<int> &arr){

    if(k == 0)
        return true;
    if(idx == 0)
        return arr[0] == k;  

    if(dp[idx][k] != -1)
        return dp[idx][k];

    bool notPick = helper(idx-1, k, dp, arr);
    bool pick = false;
    if(k >= arr[idx])
        pick = helper(idx-1, k - arr[idx], dp, arr);

    return dp[idx][k] = pick | notPick;          
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int> > dp(n, vector<int>(k+1, -1));
    return helper(n-1, k, dp, arr);
}

// Tabulation
bool subsetSumToKT(int n, int k, vector<int> &arr) {
    vector<vector<bool> > dp(n, vector<bool>(k+1, 0));
    
    // Base Cases
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    if(arr[0] <= k)
        dp[0][arr[0]] = true;

    for(int idx=1; idx<n; idx++){
        for(int target = 1; target<=k; target++){
            bool notPick = dp[idx-1][target];
            bool pick = false;
            if(arr[idx] <= target)
                pick = dp[idx-1][target - arr[idx]];

            dp[idx][target] = pick | notPick;
        }
    }
    return dp[n-1][k];
}

// Space Optimization
bool subsetSumToKS(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, 0), curr(k+1, 0);
    
    // Base Cases
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for(int idx=1; idx<n; idx++){
        for(int target = 1; target<=k; target++){
            bool notPick = prev[target];
            bool pick = false;
            if(arr[idx] <= target)
                pick = prev[target - arr[idx]];

            curr[target] = pick | notPick;
        }
        prev = curr;
    }
    return prev[k];
}