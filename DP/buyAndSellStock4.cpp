#include <iostream>
#include <vector>
using namespace std;

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, 
and an integer k. Find the maximum profit you can achieve. You may complete at most k transactions: 
i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before 
you buy again).
*/

// Memoization
int f(int i, int buy, int trans, vector<int>& prices, vector<vector<vector<int> > >& dp){
    if(trans == 0) return 0;
    if(i == prices.size()) return 0;

    if(dp[i][buy][trans] != -1) 
        return dp[i][buy][trans];

    int profit = 0;
    if(buy)
        profit = max(-prices[i] + f(i+1, 0, trans, prices, dp), f(i+1, 1, trans, prices, dp));
    else
        profit = max(prices[i] + f(i+1, 1, trans-1, prices, dp), f(i+1, 0, trans, prices, dp));

    return dp[i][buy][trans] = profit;        
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(2, vector<int>(k+1, -1)));
    return f(0, 1, k, prices, dp); 
}

// Space Optimization dp[n][2k]
int maxProfitS(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int> > dp(n+1, vector<int>(2*k+1, 0));

    for(int i=n-1; i>=0; i--){
        for(int trans = 2*k-1; trans >=0; trans--){
            //buy
            if(trans % 2 == 0)
                dp[i][trans] = max(-prices[i] + dp[i+1][trans+1], dp[i+1][trans]);
            else
                dp[i][trans] = max(prices[i] + dp[i+1][trans+1], dp[i+1][trans]);
        }
    }
    return dp[0][0]; 
}