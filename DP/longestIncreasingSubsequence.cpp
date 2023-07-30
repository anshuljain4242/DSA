#include <iostream>
#include <vector>
using namespace std;

// Memoization
int f(int i, int prev, vector<int>& nums, int n, vector<vector<int> >& dp){
    // base case
    if(i == n) return 0;

    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    // not Take;
    int len = 0 + f(i+1, prev, nums, n, dp);
    // Take
    if(prev == -1 || nums[i] > nums[prev])
        len = max(len, 1 + f(i+1, i, nums, n, dp));

    return dp[i][prev+1] = len;    
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int> > dp(n, vector<int>(n+1, -1));
    return f(0, -1, nums, n, dp);
}

// Tabulation
int lengthOfLIST(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

    for(int i=n-1; i>=0; i--){
        for(int prev = i-1; prev >= -1; prev--){
            // not Take
            int len = 0 + dp[i+1][prev+1];
            // Take
            if(prev == -1 || nums[i] > nums[prev])
                len = max(len, 1 + dp[i+1][i+1]);
            dp[i][prev+1] = len;
        }
    }
    return dp[0][-1+1];
}

// Space Optimisation
int lengthOfLISS(vector<int>& nums) {
    int n = nums.size();
    vector<int>next(n+1, 0),curr(n+1, 0);

    for(int i=n-1; i>=0; i--){
        for(int prev = i-1; prev >= -1; prev--){
            // not Take
            int len = 0 + next[prev+1];
            // Take
            if(prev == -1 || nums[i] > nums[prev])
                len = max(len, 1 + next[i+1]);
            curr[prev+1] = len;
        }
        next = curr;
    }
    return next[-1+1];
}


int lengthOfLISs(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for(int i=0; i<n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i]){
                dp[i] = max(1 + dp[prev], dp[i]);
            }
        }
    }    
    return *max_element(dp.begin(), dp.end());
}

// Print LIS
int printLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;

    for(int i=0; i<n; i++){
        hash[i] = i; 
        for(int prev = 0; prev <= i-1; prev++){
            if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    } 
    //for Printing
    /*
    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    } 
    reverse(temp.begin(), temp.end());
    for(auto it:temp) cout<<it<<" ";
    cout<<endl;  
    return maxi;
    */
   
    for(int index = n - 1; index >= 0 ; index--){
        if ( dp[index] == maxi){
            cout<<nums[index] << " ";
            maxi--;
        }
    }
}

// Best Approach - Binary Search
int lenLongestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len=1;
    for(int i=1; i<n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            len++;
        }      
        else{
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }
    return len;
}