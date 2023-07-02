#include <iostream>
#include <vector>
using namespace std;

// Recursion + Memoization
int helper(int i, int j, int m, vector<vector<int> > &triangle, vector<vector<int> > &dp)
{
    if (i == m - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = triangle[i][j] + min(helper(i + 1, j, m, triangle, dp), helper(i + 1, j + 1, m, triangle, dp));
}

int minimumTotal(vector<vector<int> > &triangle)
{
    int m = triangle.size();
    vector<vector<int> > dp(m, vector<int>(m, -1));
    return helper(0, 0, m, triangle, dp);
}

// Tabulation
int minimumTotalT(vector<vector<int> > &triangle)
{
    int m = triangle.size();
    vector<vector<int> > dp(m, vector<int>(m, -1));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            if (i == m - 1)
                dp[i][j] = triangle[i][j];
            else
            {
                int d = dp[i + 1][j];
                int r = dp[i + 1][j + 1];
                dp[i][j] = triangle[i][j] + min(d, r);
            }
        }
    }
    return dp[0][0];
}

// Space Optimization
int minimumTotalS(vector<vector<int> > &triangle)
{
    int m = triangle.size();
    vector<int> dumy(m, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        vector<int> curRow(m, 0);
        for (int j = i; j >= 0; j--)
        {
            if (i == m - 1)
                curRow[j] = triangle[i][j];
            else
            {
                int d = dumy[j];
                int r = dumy[j + 1];
                curRow[j] = triangle[i][j] + min(d, r);
            }
        }
        dumy = curRow;
    }
    return dumy[0];
}