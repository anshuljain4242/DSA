#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 
1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal 
to another (not rotated or reflected).

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.
*/

void dfs(int r, int c, vector<pair<int,int> >& vec, vector<vector<int> >& grid, vector<vector<int> >& vis, int r0, int c0){
    // n x m x 4 
    vis[r][c] = 1;
    vec.push_back(make_pair(r - r0, c - c0));
    int n = grid.size();
    int m = grid[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    
    for(int i=0; i<4; i++){
        int nrow = r + drow[i];
        int ncol = c + dcol[i];
        if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
            dfs(nrow, ncol, vec, grid, vis, r0, c0);
        }
    }
    
}

int countDistinctIslands(vector<vector<int> >& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int> > vis(n, vector<int>(m, 0));
    set<vector<pair<int,int> > > st;
    // n x m x log(n x m)
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int,int> > vec;
                dfs(i, j, vec, grid, vis, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}