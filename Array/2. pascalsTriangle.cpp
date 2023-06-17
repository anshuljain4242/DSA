#include<iostream>
#include<vector>
using namespace std;

/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1 up till N

*/

/*
Q1 - Given R and C, give the element at that place. Ex - R = 5, C = 3, then output = 6
Brute force -> can be easily found out by (R-1) C (C-1)

Better -> nCr = n!/(r!)((n-r)!)
ex - 10 C 3  = 10*9*8/3*2*1
TC -> O(r), SC -> O(1)
*/


void nCr(long long int n, long long int r)
{
    long long int res = 1;
    for(long long int i=0; i<r; i++)
    {
        res = res * (n-i);
        res = res / (i+1);
    }
    
}

vector<long long int> nthRow(int n)
{
    vector<long long int> row;
    long long int ans = 1;
    row.push_back(1);

    for(int i=1; i<n; i++)
    {
        ans = ans * (n-i);
        ans = ans/i;
        row.push_back(ans);
    }
    return row;
}

vector<vector<long long int> > printPascal(int n) 
{
    // vector<vector<long long int> > pascal;

    // for(int i=1; i<=n; i++)
    // {
    //     vector<long long int> row = nthRow(i);
    //     pascal.push_back(row);
    // }
    // return pascal;

  vector<vector<long long int> > pascal(n);

  for(int i = 0 ; i < n ; i++){

    pascal[i].resize(i+1);

    pascal[i][0] = pascal[i][i] =1 ;

    for(int j = 1 ; j < i ; j++){

      pascal[i][j] = pascal[i-1][j-1]+ pascal[i-1][j];

    }

  }

  return pascal ;
}