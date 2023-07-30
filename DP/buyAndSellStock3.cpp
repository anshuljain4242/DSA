#include <iostream>
#include <vector>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before
you buy again).
*/

// Memoization
int f(int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int> > >& dp){
    if(cap == 0) return 0;
    if(i == prices.size()) return 0;

    if(dp[i][buy][cap] != -1) 
        return dp[i][buy][cap];

    long profit = 0;
    if(buy)
        profit = max(-prices[i] + f(i+1, 0, cap, prices, dp), f(i+1, 1, cap, prices, dp));
    else
        profit = max(prices[i] + f(i+1, 1, cap-1, prices, dp), f(i+1, 0, cap, prices, dp));

    return dp[i][buy][cap] = profit;        
}

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int> > > dp(n, vector<vector<int> >(2, vector<int>(3, -1)));
    return f(0, 1, 2, prices, dp); 
}

// Tabulation
int maxProfitT(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(2, vector<int>(3, 0)));

    // these base cases are assigning some dp array values to 0, which is already done while initialising
    // dp. so doensn't make sense.
    for(int i=0; i<n; i++){
        for(int buy=1; buy<=1; buy++){
            dp[i][buy][0] = 0;
        }
    }
    for(int cap = 0; cap<=2; cap++){
        dp[n][0][cap] = dp[n][1][cap] = 0;
    }

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                int profit = 0;
                if(buy)
                    profit = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                else
                    profit = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);

                dp[i][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2]; 
}

// Space Optimization
int maxProfitS(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int> > after(2, vector<int>(3, 0));
    vector<vector<int> > curr(2, vector<int>(3, 0));

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                int profit = 0;
                if(buy)
                    profit = max(-prices[i] + after[0][cap], after[1][cap]);
                else
                    profit = max(prices[i] + after[1][cap-1], after[0][cap]);

                curr[buy][cap] = profit;
            }
        }
        after = curr;
    }
    return after[1][2]; 
}

// Using dp[n][4]
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int> > dp(n+1, vector<int>(5, 0));

    for(int i=n-1; i>=0; i--){
        for(int trans = 0; trans<4; trans++){
            int profit = 0;
            if(trans%2 == 0)
                profit = max(-prices[i] + dp[i+1][trans+1], dp[i+1][trans]);
            else
                profit = max(prices[i] + dp[i+1][trans+1], dp[i+1][trans]);  

            dp[i][trans] = profit;      
        }
    }
    return dp[0][0]; 
}
