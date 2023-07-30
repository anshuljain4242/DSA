#include <iostream>
#include <vector>
using namespace std;



// Memoization
int helper(int idx, int maxWeight, vector<vector<int> >& dp, vector<int> weight, vector<int> value){

	// Base cases
	if(idx == 0){
		if(weight[0] <= maxWeight) return value[0];
		else return 0;
	}

	if(dp[idx][maxWeight] != -1)
		return dp[idx][maxWeight];

	int notTake = 0 + helper(idx-1, maxWeight, dp, weight, value);
	int take = INT_MIN;
	if(weight[idx] <= maxWeight)
		take = value[idx] + helper(idx-1, maxWeight - weight[idx], dp, weight, value);

	return dp[idx][maxWeight] = max(take, notTake);	
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int> > dp(n, vector<int>(maxWeight+1, -1));
	return helper(n-1, maxWeight, dp, weight, value);
}

// Tabulation
int knapsackT(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int> > dp(n, vector<int>(maxWeight+1, 0));

	for(int W = weight[0]; W<=maxWeight; W++){
		dp[0][W] = value[0];
	}

	for(int idx = 1; idx<n; idx++){
		for(int W = 0; W<=maxWeight; W++){
			int notTake = 0 + dp[idx-1][W];
			int take = INT_MIN;
			if(weight[idx] <= W)
				take = value[idx] + dp[idx-1][W - weight[idx]];

			dp[idx][W] = max(take, notTake);	
		}
	}
	return dp[n-1][maxWeight];
}

// Space Optimization
int knapsackS(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);

	for(int W = weight[0]; W<=maxWeight; W++){
		prev[W] = value[0];
	}

	for(int idx = 1; idx<n; idx++){
		for(int W = 0; W<=maxWeight; W++){
			int notTake = 0 + prev[W];
			int take = INT_MIN;
			if(weight[idx] <= W)
				take = value[idx] + prev[W - weight[idx]];

			curr[W] = max(take, notTake);	
		}
		prev = curr;
	}
	return prev[maxWeight];
}

// Space Optimized - From 2 vectors to 1 vector 
int knapsackSS(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1, 0);

	for(int W = weight[0]; W<=maxWeight; W++){
		prev[W] = value[0];
	}

	for(int idx = 1; idx<n; idx++){
		for(int W = maxWeight; W>= 0; W--){
			int notTake = 0 + prev[W];
			int take = INT_MIN;
			if(weight[idx] <= W)
				take = value[idx] + prev[W - weight[idx]];

			prev[W] = max(take, notTake);	
		}
	}
	return prev[maxWeight];
}