#include<iostream>
#include<vector>
using namespace std;

// Recursion
int helperR(int idx, vector<int> &nums){
    if(idx == 0)
        return nums[0];
    if(idx < 0)
        return 0;

    int pick = nums[idx] + helperR(idx-2, nums);
    int notPick = 0 + helperR(idx-1, nums); 
    return max(pick, notPick);       
}
int maximumNonAdjacentSumR(vector<int> &nums){
    
    return helperR(nums.size()-1, nums);
}

// Memoization
int helperM(int idx, vector<int> &nums, vector<int>& dp){
    if(idx == 0)
        return nums[0];
    if(idx < 0)
        return 0;

    if(dp[idx] != -1)
        return dp[idx];    

    int pick = nums[idx] + helperM(idx-2, nums, dp);
    int notPick = 0 + helperM(idx-1, nums, dp); 
    return dp[idx] = max(pick, notPick);       
}
int maximumNonAdjacentSumM(vector<int> &nums){
    vector<int> dp(nums.size(),-1);
    return helperM(nums.size()-1, nums, dp);
}

// Tabulation
int maximumNonAdjacentSumT(vector<int> &nums){
    vector<int> dp(nums.size(),-1);

    dp[0] = nums[0];

    for(int i=1; i<nums.size(); i++){
        int take = nums[i];
        if(i>1)
            take += dp[i-2];
        int notTake  = 0 + dp[i-1];
        dp[i] = max(take, notTake);  
    }

    return dp[nums.size() - 1];
}

// Space Optimization
int maximumNonAdjacentSumS(vector<int> &nums){
    
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;

    for(int i=1; i<nums.size(); i++){
        int take = nums[i];
        if(i>1)
            take += prev2;   
        int notTake  = 0 + prev1;
        int curr = max(take, notTake); 
        prev2 = prev1;
        prev1 = curr; 
    }

    return prev1;
}

// Greedy Approach
int maximumNonAdjacentSum(vector<int> &nums){
    
    int inc = nums[0];
    int exc = 0;

    for(int i=1; i<nums.size(); i++){
        int ninc = exc + nums[i];
        int nexc = max(inc,exc);

        inc = ninc;
        exc = nexc;
    }
    return max(inc,exc);
}