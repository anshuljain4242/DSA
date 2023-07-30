#include <iostream>
#include <vector>
using namespace std;


// Memoization
long helper(int i, int buy, long *values, int n, vector<vector<int> >& dp){

    if(i == n) return 0;

    if(dp[i][buy] != -1) return dp[i][buy];
    long profit = 0;
    if(buy)
        profit = max(-values[i] + helper(i+1, 0, values, n, dp), helper(i+1, 1, values, n, dp));
    else
        profit = max(values[i] + helper(i+1, 1, values, n, dp), helper(i+1 , 0, values, n, dp));
    return dp[i][buy] = profit;        
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<int> > dp(n, vector<int>(2, -1));
    return helper(0, 1, values, n, dp);
}

// Tabulation
long getMaximumProfitT(long *values, int n)
{
    vector<vector<long> > dp(n+1, vector<long>(2, 0));
    dp[n][0] = dp[n][1] = 0;

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            long profit = 0;
            if(buy)
                profit = max((-values[i] + dp[i+1][0]), dp[i+1][1]);
            else
                profit = max(values[i] + dp[i+1][1], dp[i+1][0]);
            dp[i][buy] = profit;
        }    
    }
    return dp[0][1];
}

// Space Optimization
long getMaximumProfitS(long *values, int n)
{
    vector<long> ahead(2, 0), curr(2, 0);
    ahead[0] = ahead[1] = 0;

    for(int i=n-1; i>=0; i--){
        for(int buy=0; buy<=1; buy++){
            long profit = 0;
            if(buy)
                profit = max((-values[i] + ahead[0]), ahead[1]);
            else
                profit = max(values[i] + ahead[1], ahead[0]);
            curr[buy] = profit;
        } 
        ahead = curr;   
    }
    return ahead[1];
}

// using 4 variables
long getMaximumProfitV(long *values, int n)
{
    long aheadBuy, aheadNotBuy, currBuy, currNotBuy;
    aheadNotBuy = aheadBuy = 0;

    for(int i=n-1; i>=0; i--){

        currBuy = max((-values[i] + aheadNotBuy), aheadBuy);

        currNotBuy = max(values[i] + aheadBuy, aheadNotBuy);

        aheadNotBuy = currNotBuy;
        aheadBuy = currBuy;   
    }
    return aheadBuy;
}