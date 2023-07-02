#include <iostream>
#include <vector>
using namespace std;

// Memoization
int helper(int i, int j, int n, int m, vector<vector<int> > &dp, vector<vector<int> > &matrix)
{
    // Base Case
    if (j < 0 || j > m - 1)
        return -1e9;
    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + helper(i - 1, j, n, m, dp, matrix);
    int ld = matrix[i][j] + helper(i - 1, j - 1, n, m, dp, matrix);
    int rd = matrix[i][j] + helper(i - 1, j + 1, n, m, dp, matrix);

    return dp[i][j] = max(up, max(ld, rd));
}

int getMaxPathSum(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int> > dp(n, vector<int>(m, -1));
    int maxi = -1e9;
    for (int j = m - 1; j >= 0; j--)
    {
        int path = helper(n - 1, j, n, m, dp, matrix);
        maxi = max(maxi, path);
    }
    return maxi;
}

// Tabulation
int getMaxPathSumT(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int> > dp(n, vector<int>(m, -1));

    for (int j = m - 1; j >= 0; j--)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];
            int ld = INT_MIN;
            if (j - 1 >= 0)
                ld = matrix[i][j] + dp[i - 1][j - 1];
            int rd = INT_MIN;
            if (j + 1 < m)
                rd = matrix[i][j] + dp[i - 1][j + 1];

            dp[i][j] = max(up, max(ld, rd));
        }
    }
    int maxi = dp[n - 1][0];
    for (int j = 1; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }
    return maxi;
}

// Space Optimization
int getMaxPathSumS(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prevRow(m, 0);

    for (int j = m - 1; j >= 0; j--)
    {
        prevRow[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> curRow(m, 0);
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + prevRow[j];
            int ld = INT_MIN;
            if (j - 1 >= 0)
                ld = matrix[i][j] + prevRow[j - 1];
            int rd = INT_MIN;
            if (j + 1 < m)
                rd = matrix[i][j] + prevRow[j + 1];

            curRow[j] = max(up, max(ld, rd));
        }
        prevRow = curRow;
    }
    int maxi = *max_element(prevRow.begin(), prevRow.end());
    return maxi;
}