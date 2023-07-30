#include<iostream>
#include<vector>
using namespace std;

/*
Given a rod of length 'N' units. The rod can be cut into different sizes and each size has a cost 
associated with it. 
Determine the maximum cost obtained by cutting the rod and selling it's pieces.
ex -
N = 5
costArr = 2 5 7 8 10
Solution:
All possible partitions are:
1,1,1,1,1           max_cost=(2+2+2+2+2)=10
1,1,1,2             max_cost=(2+2+2+5)=11
1,1,3               max_cost=(2+2+7)=11
1,4                 max_cost=(2+8)=10
5                   max_cost=(10)=10
2,3                 max_cost=(5+7)=12
1,2,2               max _cost=(1+5+5)=12    

Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.
*/
int helper(int idx, int target, vector<int> &price, vector<vector<int> >& dp){

	// Base Case

	if(idx == 0){
			return target*price[idx];
	}
	if(dp[idx][target] != -1)
		return dp[idx][target];
	int notCut = 0 + helper(idx-1, target, price, dp);
	int cut = INT_MIN;
	int rodLength = idx+1;
	if(rodLength <= target)
		cut = price[idx] + helper(idx, target - rodLength, price, dp);

	return dp[idx][target] = max(cut, notCut);	
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int> > dp(n, vector<int>(n+1, -1));
	return helper(n-1, n, price, dp);
}

// Tabulation
int cutRodT(vector<int> &price, int n)
{
	vector<vector<int> > dp(n, vector<int>(n+1, 0));
	for(int tar = 0; tar<=n; tar++){
		dp[0][tar] = tar*price[0];
	}

	for(int idx=1; idx<n; idx++){
		for(int tar = 0; tar<=n; tar++){
			int notCut = 0 + dp[idx-1][tar];
			int cut = INT_MIN;
			int rodLength = idx+1;
			if(rodLength <= tar)
				cut = price[idx] + dp[idx][tar - rodLength];

			dp[idx][tar] = max(cut, notCut);
		}
	}
	return dp[n-1][n];
}

// Space Optimization
int cutRodS(vector<int> &price, int n)
{
	vector<int> prev(n+1, 0), curr(n+1, 0);
	for(int tar = 0; tar<=n; tar++){
		prev[tar] = tar*price[0];
	}

	for(int idx=1; idx<n; idx++){
		for(int tar = 0; tar<=n; tar++){
			int notCut = 0 + prev[tar];
			int cut = INT_MIN;
			int rodLength = idx+1;
			if(rodLength <= tar)
				cut = price[idx] + curr[tar - rodLength];

			curr[tar] = max(cut, notCut);
		}
		prev = curr;
	}
	return prev[n];
}

// Space Optimised to O(n)
int cutRodSS(vector<int> &price, int n)
{
	vector<int> prev(n+1, 0);
	for(int tar = 0; tar<=n; tar++){
		prev[tar] = tar*price[0];
	}

	for(int idx=1; idx<n; idx++){
		for(int tar = 0; tar<=n; tar++){
			int notCut = 0 + prev[tar];
			int cut = INT_MIN;
			int rodLength = idx+1;
			if(rodLength <= tar)
				cut = price[idx] + prev[tar - rodLength];

			prev[tar] = max(cut, notCut);
		}
	}
	return prev[n];
}
