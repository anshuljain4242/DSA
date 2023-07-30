#include<iostream>
#include<vector>
using namespace std;

/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the 
image. You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting 
from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the 
starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those 
pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
*/

void dfs(int sr, int sc, int color, int inColor, vector<vector<int> >& image, vector<vector<int> >& ans, 
int delrow[], int delcol[], int m, int n){
        
    ans[sr][sc] = color;

    for(int i=0; i<4; i++){
        int nrow = sr + delrow[i];
        int ncol = sc + delcol[i];

        if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == inColor && ans[nrow][ncol] != color){
            dfs(nrow, ncol, color, inColor, image, ans, delrow, delcol, m, n);
        }
    }

}
vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int color) {
    
    int m = image.size();
    int n = image[0].size();
    int inColor = image[sr][sc];
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    vector<vector<int> > ans = image;
    dfs(sr, sc, color, inColor, image, ans, delrow, delcol, m, n);
    return ans;
}