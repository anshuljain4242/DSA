#include <iostream>
#include <vector>
using namespace std;

/*
Partition arr into 2 subsets such that P1 has sum S1 and P2 has sum S2. 
S1 >= S2 and S1 - S2 = d
*/

// Memoization
int mod = (int)1e9 + 7;
int helper(int idx, int k, vector<vector<int> >& dp, vector<int>& arr){
	
	if(idx == 0){
        if(k == 0 && arr[0] == 0) return 2;
        if(k == 0 || k == arr[0]) return 1;
        return 0;
    }
		

	if(dp[idx][k] != -1)
		return dp[idx][k] % mod;

	int notPick = helper(idx-1, k, dp, arr) % mod;
	int pick = 0;
	if(arr[idx] <= k)
		pick = helper(idx-1, k - arr[idx], dp, arr) % mod;

	return dp[idx][k] = (pick + notPick) % mod;	

}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int> > dp(n, vector<int>(k+1, -1));
	return helper(n-1, k, dp, arr);
}

int countPartitions(int n, int d, vector<int> &arr) {
    
    int totSum = 0;
    for(auto &it:arr)
        totSum += it;

    if(totSum - d < 0 || (totSum - d) % 2) return 0;
    return findWays(arr, (totSum - d)/2);    
}

// Tabulation
int findWaysT(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int> > dp(n, vector<int>(k+1, 0));

    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

	if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;
	
	for(int idx = 1; idx<n; idx++){
        for (int target = 0; target <= k; target++) {
            int notPick = dp[idx - 1][target] % mod;
            int pick = 0;
            if (arr[idx] <= target)
            pick = dp[idx - 1][target - arr[idx]] % mod;

            dp[idx][target] = (pick + notPick) % mod;
        }
    }

        return dp[n - 1][k];
}

int countPartitionsT(int n, int d, vector<int> &arr) {
    
    int totSum = 0;
    for(auto &it:arr)
        totSum += it;

    if(totSum - d < 0 || (totSum - d) % 2) return 0;
    return findWaysT(arr, (totSum - d)/2);    
}

// Space Optimization
int findWaysS(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<int> prev(k+1, 0), curr(k+1, 0);


    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

	if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;
	
	for(int idx = 1; idx<n; idx++){
        for (int target = 0; target <= k; target++) {
            int notPick = prev[target] % mod;
            int pick = 0;
            if (arr[idx] <= target)
            pick = prev[target - arr[idx]] % mod;

            curr[target] = (pick + notPick) % mod;
        }
        prev = curr;
    }

        return prev[k];
}

int countPartitionsS(int n, int d, vector<int> &arr) {
    
    int totSum = 0;
    for(auto &it:arr)
        totSum += it;

    if(totSum - d < 0 || (totSum - d) % 2) return 0;
    return findWays(arr, (totSum - d)/2);    
}

