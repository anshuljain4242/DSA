#include<iostream>
#include<vector>
using namespace std;

/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Just like Surrounded Regions.
*/


void dfs(int r, int c, vector<vector<int> >& vis, vector<vector<int> >& grid, int drow[], int dcol[]){
    vis[r][c] = 1;
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0; i<4; i++){
        int nrow = r + drow[i];
        int ncol = c + dcol[i];

        if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
            dfs(nrow, ncol, vis, grid, drow, dcol);
        }       
    }
}

int numEnclaves(vector<vector<int> >& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int> > vis(n, vector<int> (m, 0));
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    // traversing first and last row
    for(int j=0; j<m; j++){
        // first row
        if(!vis[0][j] && grid[0][j] == 1){
            dfs(0, j, vis, grid, drow, dcol);
        }
        // last row
        if(!vis[n-1][j] && grid[n-1][j] == 1){
            dfs(n-1, j, vis, grid, drow, dcol);
        }
    }
    // traversing first and last col
    for(int i=0; i<n; i++){
        // first col
        if(!vis[i][0] && grid[i][0] == 1){
            dfs(i, 0, vis, grid, drow, dcol);
        }
        // last col
        if(!vis[i][m-1] && grid[i][m-1] == 1){
            dfs(i, m-1, vis, grid, drow, dcol);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1)
                cnt++;
        }
    }
    return cnt;
    }