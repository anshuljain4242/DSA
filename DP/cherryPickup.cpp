/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] 
represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
~ When any robot passes through a cell, It picks up all cherries, and the cell becomes an 
empty cell.
~ When both robots stay in the same cell, only one takes the cherries.
~ Both robots cannot move outside of the grid at any moment.
~ Both robots should reach the bottom row in grid.
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursion + Memoization
int helper(int i, int j1, int j2, vector<vector<vector<int> > > &dp, vector<vector<int> > &grid)
{

    // Base Case
    if (j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())
        return -1e8;

    if (i == grid.size() - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // Explore all paths of both robots simultaneously
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += helper(i + 1, j1 + dj1, j2 + dj2, dp, grid);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int cherryPickup(vector<vector<int> > &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // dp[r][c][c];
    vector<vector<vector<int> > > dp(rows, vector<vector<int> >(cols, vector<int>(cols, -1)));
    return helper(0, 0, cols - 1, dp, grid); // f(i,j1,j2)
}

// Tabulation
int cherryPickupT(vector<vector<int> >& grid) {
    int r = grid.size();
    int c = grid[0].size();

    // dp[r][c][c];
    vector<vector<vector<int> > > dp(r, vector<vector<int> >(c, vector<int>(c, 0)));

    for(int j1 = 0; j1<c; j1++){
        for(int j2 = 0; j2<c; j2++){
            if(j1 == j2)
                dp[r-1][j1][j2] = grid[r-1][j1];
            else
                dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }  

    for(int i = r-2; i>=0; i--){
        for(int j1 = 0; j1 < c; j1++){
            for(int j2 = 0; j2 < c; j2++){
                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        int value = 0;
                        if(j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if(j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)    
                            value += dp[i+1][j1 + dj1][j2 + dj2];
                        else 
                            value += -1e8;    
                        maxi = max(maxi, value);    
                    }            
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c-1];
}

// Space Optimization
int cherryPickupS(vector<vector<int> >& grid) {
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int> > prev(c, vector<int> (c, 0));

    for(int j1 = 0; j1<c; j1++){
        for(int j2 = 0; j2<c; j2++){
            if(j1 == j2)
                prev[j1][j2] = grid[r-1][j1];
            else
                prev[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }  

    for(int i = r-2; i>=0; i--){
        vector<vector<int> > curr(c, vector<int> (c, 0));
        for(int j1 = 0; j1 < c; j1++){
            for(int j2 = 0; j2 < c; j2++){
                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        int value = 0;
                        if(j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if(j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)    
                            value += prev[j1 + dj1][j2 + dj2];
                        else 
                            value += -1e8;    
                        maxi = max(maxi, value);    
                    }            
                }
                curr[j1][j2] = maxi;
            }
        }
        prev = curr;
    }
    return prev[0][c-1];
}