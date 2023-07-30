#include <iostream>
#include <vector>
using namespace std;

// Recursion + Memoization
int mod = (int)1e9 + 7;
int helper(int idx, int k, vector<vector<int> >& dp, vector<int>& arr){
	
	if(k == 0)
		return 1;

	if(idx == 0)
		return (arr[idx] == k);

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

// Tabulation

int findWaysT(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int> > dp(n, vector<int>(k+1, 0));

	for(int idx=0; idx<n; idx++){
		dp[idx][0] = 1;
	}
	if(arr[0] <= k)
		dp[0][arr[0]] = 1;
	
	for(int idx = 1; idx<n; idx++){
		for(int target = 1; target <=k; target++){
			int notPick = dp[idx-1][target]%mod;
			int pick = 0;
			if(arr[idx] <= target)
				pick = dp[idx-1][target - arr[idx]]%mod;

			dp[idx][target] = (pick + notPick)%mod;
		}
	}

	return dp[n-1][k];
}

// Space Optimization
int findWaysS(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<int> prev(k+1, 0), curr(k+1, 0);

	prev[0] = curr[0] = 1;
	if(arr[0] <= k)
		prev[arr[0]] = 1;
	
	for(int idx = 1; idx<n; idx++){
		for(int target = 1; target <=k; target++){
			int notPick = prev[target]%mod;
			int pick = 0;
			if(arr[idx] <= target)
				pick = prev[target - arr[idx]]%mod;

			curr[target] = (pick + notPick)%mod;
		}
		prev = curr;
	}

	return prev[k];
}
