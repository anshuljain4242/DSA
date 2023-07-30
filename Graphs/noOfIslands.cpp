#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the 
number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.*

*/

void bfs(int r, int c, vector<vector<int> >& vis, vector<vector<char> >& grid, int n, int m){
    vis[r][c] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(r,c));
    
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        q.pop();
        
        // traverse the neighbours
        for(int delrow = -1; delrow <= 1; delrow++){
            for(int delcol = -1; delcol <= 1; delcol++){
                if(abs(delrow) + abs(delcol) == 2)continue;
                int nrow = r + delrow;
                int ncol = c + delcol;

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == '1' && 
                !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push(make_pair(nrow, ncol));
                }
            }
        }
    }
}

int numIslands(vector<vector<char> >& grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > vis(n, vector<int>(m, 0));
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '1' && !vis[i][j]){
                bfs(i, j, vis, grid, n, m);
                cnt++;
            }
        }
    }
    return cnt;
}