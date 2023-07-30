#include <iostream>
#include <vector>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount 
representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by 
any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.
*/

// Memoization
int helper(int idx, int amount, vector<int>& coins, vector<vector<int> >& dp){

    if(idx == 0){
        return (amount % coins[idx] == 0);
    }
    
    if(dp[idx][amount] != -1)
        return dp[idx][amount];

    int notTake = helper(idx-1, amount, coins, dp);
    int take = 0;
    if(coins[idx] <= amount)
        take = helper(idx, amount - coins[idx], coins, dp);

    return dp[idx][amount] = take + notTake;  
}
int change(int amount, vector<int>& coins) {
    
    int n = coins.size();
    vector<vector<int> > dp(n, vector<int>(amount+1, -1));
    return helper(n-1, amount, coins, dp);
}

// Tabulation
int changeT(int amount, vector<int>& coins) {
    
    int n = coins.size();
    vector<vector<int> > dp(n, vector<int>(amount+1, 0));

    for(int tar=0; tar<=amount; tar++){
        if(tar % coins[0] == 0)
            dp[0][tar] = 1;
    }

    for(int idx = 1; idx<n; idx++){
        for(int tar = 0; tar<=amount; tar++){
            int notTake = dp[idx-1][tar];
            int take = 0;
            if(coins[idx] <= tar)
                take = dp[idx][tar-coins[idx]];

            dp[idx][tar] = take + notTake;
        }
    }
    return dp[n-1][amount];    
}

// Space Optimization
int changeS(int amount, vector<int>& coins) {
        
    int n = coins.size();
    vector<int> prev(amount+1, 0), curr(amount+1, 0);

    for(int tar=0; tar<=amount; tar++){
        if(tar % coins[0] == 0)
            prev[tar] = 1;
    }

    for(int idx = 1; idx<n; idx++){
        for(int tar = 0; tar<=amount; tar++){
            int notTake = prev[tar];
            int take = 0;
            if(coins[idx] <= tar)
                take = curr[tar-coins[idx]];

            curr[tar] = take + notTake;
        }
        prev = curr;
    }
    return prev[amount];    
}
