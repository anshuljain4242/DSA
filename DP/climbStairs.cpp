#include <iostream>
#include <vector>
using namespace std;

// Recursion
int countDistinctWays(int nStairs)
{
    //  Write your code here.
    if (nStairs < 0)
        return 0;

    if (nStairs == 0)
        return 1;

    int ways = countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
    return ways;
}

// Memoization
int helper(int n, vector<int> &dp)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
}
int climbStairs(int n)
{

    vector<int> dp(n + 1, -1);
    return helper(n, dp);
}

// Tabulation
int climbStairsT(int n)
{

    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space Optimised
int climbStairsS(int n)
{

    vector<int> dp(n + 1, -1);
    int prev2 = 1;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
