#include<iostream>
#include<vector>
using namespace std;

// only diff from knapsack is that can take a particular weight any number of times

// Memoization
int helper(int idx, int w, vector<int> &profit, vector<int> &weight, vector<vector<int> >& dp){
    // Base Case
    if(idx == 0){
        if(w / weight[idx] >= 0) return (profit[idx]* (w/weight[idx]));
        return 0;
    }

    if(dp[idx][w] != -1)
        return dp[idx][w];

    int notTake = 0 + helper(idx-1, w, profit, weight, dp);
    int take = 0;
    if(weight[idx] <= w)
        take = profit[idx] + helper(idx, w - weight[idx], profit, weight, dp);

    return dp[idx][w] = max(take, notTake);    
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int> > dp(n, vector<int>(w+1, -1));
    return helper(n-1, w, profit, weight, dp);
}

// Tabulation
int unboundedKnapsackT(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int> > dp(n, vector<int>(w+1, 0));

    // Base case
    for(int tar=0; tar<=w; tar++){
        if(tar / weight[0] >= 0)
            dp[0][tar] = (profit[0] * (tar/weight[0]));
    }

    for(int idx = 1; idx<n; idx++){
        for(int tar = 0; tar<=w; tar++){
            int notTake = 0 + dp[idx-1][tar];
            int take = 0;
            if(weight[idx] <= tar)
                take = profit[idx] + dp[idx][tar - weight[idx]];

            dp[idx][tar] = max(take, notTake);
        }
    }
    return dp[n-1][w];
}

// Space Optimization
int unboundedKnapsackS(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w+1, 0), curr(w+1, 0);

    // Base case
    for(int tar=0; tar<=w; tar++){
        if(tar / weight[0] >= 0)
            prev[tar] = (profit[0] * (tar/weight[0]));
    }

    for(int idx = 1; idx<n; idx++){
        for(int tar = 0; tar<=w; tar++){
            int notTake = 0 + prev[tar];
            int take = 0;
            if(weight[idx] <= tar)
                take = profit[idx] + curr[tar - weight[idx]];

            curr[tar] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[w];
}

// Space Optimized to O(W)
int unboundedKnapsackSS(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w+1, 0);

    // Base case
    for(int tar=0; tar<=w; tar++){
        if(tar / weight[0] >= 0)
            prev[tar] = (profit[0] * (tar/weight[0]));
    }

    for(int idx = 1; idx<n; idx++){
        for(int tar = 0; tar<=w; tar++){
            int notTake = 0 + prev[tar];
            int take = 0;
            if(weight[idx] <= tar)
                take = profit[idx] + prev[tar - weight[idx]];

            prev[tar] = max(take, notTake);
        }
    }
    return prev[w];
}