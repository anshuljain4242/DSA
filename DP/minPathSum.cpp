#include <iostream>
#include <vector>
using namespace std;

// Recursion + Memoization
int helper(int i, int j, vector<vector<int> > &grid, vector<vector<int> > &dp)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = grid[i][j] + min(helper(i - 1, j, grid, dp), helper(i, j - 1, grid, dp));
}

int minPathSum(vector<vector<int> > &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int> > dp(m, vector<int>(n, -1));
    return helper(m - 1, n - 1, grid, dp);
}

// Tabulation
int minPathSumT(vector<vector<int> > &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int> > dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int up = INT_MAX;
                int left = INT_MAX;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    return dp[m - 1][n - 1];
}

// Space Optimization
int minPathSumS(vector<vector<int> > &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prevRow(n, -1);

    for (int i = 0; i < m; i++)
    {
        vector<int> curRow(n, -1);
        for (int j = 0; j < n; j++)
        {

            if (i == 0 && j == 0)
                curRow[j] = grid[i][j];
            else
            {
                int up = INT_MAX;
                int left = INT_MAX;
                if (i > 0)
                    up = prevRow[j];
                if (j > 0)
                    left = curRow[j - 1];
                curRow[j] = grid[i][j] + min(up, left);
            }
        }
        prevRow = curRow;
    }
    return prevRow[n - 1];
}