#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell,
and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.
*/

vector < vector < int > > nearest(vector < vector < int > > & mat, int n, int m) {
    
    vector<vector<int> > ans(n, vector<int> (m, 0));
    vector<vector<int> > vis(n, vector<int> (m, 0));
    // {{r,c}, dist}
    queue<pair<pair<int,int>, int> > q;
    int dist = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1){
                q.push(make_pair(make_pair(i,j), 0));
                vis[i][j] = 1;
            }
                
        }
    }
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();
        ans[r][c] = d;

        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                mat[nrow][ncol] == 0 && vis[nrow][ncol] == 0) {
              vis[nrow][ncol] = 1;
              q.push(make_pair(make_pair(nrow, ncol), d + 1));
            }
        }
    }
    return ans;
}