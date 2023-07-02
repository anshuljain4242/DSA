#include <iostream>
#include <vector>
using namespace std;

// Recursion + Memoization
int helper(int i, int j, vector<vector<int> > dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = helper(i - 1, j, dp) + helper(i, j - 1, dp);
}

int uniquePaths(int m, int n)
{
    vector<vector<int> > dp(m, vector<int>(n, -1));
    return helper(m - 1, n - 1, dp);
}

// Tabulation
int uniquePathsT(int m, int n)
{
    vector<vector<int> > dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// Space Optimization
int uniquePathsS(int m, int n)
{
    vector<int> prevRow(n, 0); // dummy row

    for (int i = 0; i < m; i++)
    {
        vector<int> currRow(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                currRow[j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prevRow[j];
                if (j > 0)
                    left = currRow[j - 1];

                currRow[j] = up + left;
            }
        }
        prevRow = currRow;
    }
    return prevRow[n - 1];
}