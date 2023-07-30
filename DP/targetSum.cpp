#include <iostream>
#include <vector>
using namespace std;

/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then 
concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/


int findWaysT(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<vector<int> > dp(n, vector<int>(k+1, 0));

    if(nums[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(nums[0] != 0 && nums[0] <= k) dp[0][nums[0]] = 1;
    
    for(int idx = 1; idx<n; idx++){
        for (int target = 0; target <= k; target++) {
            int notPick = dp[idx - 1][target];
            int pick = 0;
            if (nums[idx] <= target)
            pick = dp[idx - 1][target - nums[idx]];

            dp[idx][target] = (pick + notPick);
        }
    }

        return dp[n - 1][k];
}

int countPartitionsT(int n, int d, vector<int> &nums) {
    
    int totSum = 0;
    for(auto &it:nums)
        totSum += it;

    if(totSum - d < 0 || (totSum - d) % 2) return 0;
    return findWaysT(nums, (totSum - d)/2);    
}

int findTargetSumWays(vector<int>& nums, int target) {
    
    return countPartitionsT(nums.size(), target, nums);
    
}