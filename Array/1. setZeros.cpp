
// To Traverse the whole matrix and if a zero is found, set that row and column to 0
#include<iostream>
#include<vector>
using namespace std;

/*
Brute Force - taking a 2d dummy vector - 
TC -> O(n*m)*O(n*m)
SC -> 
Better - taking 2 1-d dummy vectors for row and col
Optimal - taking the first row and col as dummy vector
*/

void setZeros(vector<vector<int> > &matrix)
{
	int m = matrix.size();
    int n = matrix[0].size();

    bool isRowZero = false;
    bool isColZero = false;
    
    //checking for the first column, if there are any zeroes
    for(int i=0; i<m; i++)
    {
        if(matrix[i][0] == 0)
            isColZero = true;
    }
    //checking for the first row, if there are any zeroes
    for(int j = 0; j<n; j++)
    {
        if(matrix[0][j] == 0)
            isRowZero = true;
    }

    //assuming the first row and the first column as dummy arrays, and setting the particular index of the dummy arrays to be 0.
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    //checking if the dummy col(first col) has any elements that were set to be 0, 
    // if yes, setting the whole row to be zero
    for(int i=1; i<m; i++)
    {
        if(matrix[i][0] == 0)
        {
            for(int j=0; j<n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    //checking if the dummy row(first row) has any elements that were set to be 0, 
    // if yes, setting the whole col to be zero
    for(int j=1; j<n; j++)
    {
        if(matrix[0][j] == 0)
        {
            for(int i=0; i<m; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    //Finally checking if the first row or first column had any zeros
    //(indicated by the true values of isRowZero and isColZero). If yes, setting the
    // first row or col to be 0
     
    if(isRowZero)
    {
        for(int j=0; j<n; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if(isColZero)
    {
        for(int i=0; i<m; i++)
        {
            matrix[i][0] = 0;
        }
    }

}

int main(){
    vector<vector<int> > matrix;
    int m = 2, n=3, num;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>num;
            matrix[i].push_back(num);
        }
    }
    setZeros(matrix);
}