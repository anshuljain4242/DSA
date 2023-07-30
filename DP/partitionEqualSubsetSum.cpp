#include <iostream>
#include <vector>
#include<numeric>
using namespace std;

// Space Optimized
bool subsetSumToKS(int n, int k, vector<int> &nums) {
    vector<bool> prev(k+1, 0), curr(k+1, 0);
    
    // Base Cases
    prev[0] = curr[0] = true;
    if(nums[0] <= k)
        prev[nums[0]] = true;

    for(int idx=1; idx<n; idx++){
        for(int target = 1; target<=k; target++){
            bool notPick = prev[target];
            bool pick = false;
            if(nums[idx] <= target)
                pick = prev[target - nums[idx]];

            curr[target] = pick || notPick;
        }
        prev = curr;
    }
    return prev[k];
}

bool canPartitionS(vector<int>& nums) {
    
    int total = 0;
    for(int i=0; i<nums.size(); i++)
        total += nums[i];
    
    if(total % 2 != 0)
        return false;

    int k = total/2;

    return subsetSumToKS(nums.size(), k, nums);
}

// using bit manipulation
bool canPartition(vector<int>& nums) {
    int sum = accumulate(begin(nums), end(nums), 0), half = sum / 2;
    if (sum & 1) return false;
    bitset<10001> dp(1);
    for (int &n : nums)
        dp |= dp << n;
    return dp[half];
}