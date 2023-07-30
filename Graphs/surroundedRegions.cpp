#include<iostream>
#include<vector>
using namespace std;

/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/

void dfs(int r, int c, vector<vector<int> >& vis, vector<vector<char> >& board, int drow[], int dcol[]){
    vis[r][c] = 1;
    int n = board.size();
    int m = board[0].size();
    for(int i=0; i<4; i++){
        int nrow = r + drow[i];
        int ncol = c + dcol[i];

        if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
            dfs(nrow, ncol, vis, board, drow, dcol);
        }       
    }
}
void solve(vector<vector<char> >& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int> > vis(n, vector<int> (m, 0));
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    // traversing first and last row
    for(int j=0; j<m; j++){
        // first row
        if(!vis[0][j] && board[0][j] == 'O'){
            dfs(0, j, vis, board, drow, dcol);
        }
        // last row
        if(!vis[n-1][j] && board[n-1][j] == 'O'){
            dfs(n-1, j, vis, board, drow, dcol);
        }
    }
    // traversing first and last col
    for(int i=0; i<n; i++){
        // first col
        if(!vis[i][0] && board[i][0] == 'O'){
            dfs(i, 0, vis, board, drow, dcol);
        }
        // last col
        if(!vis[i][m-1] && board[i][m-1] == 'O'){
            dfs(i, m-1, vis, board, drow, dcol);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}