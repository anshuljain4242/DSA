/*
[1,2,3] -> [1,3,2]
Brute Force - 1. Generate all permutations in sorted order
              2. Linear Search the given permutation
              3. Print the next permutation

Better - using STL function -> nextPermutation(vector.begin(), vector.end())

Optimal - 1. Find the longest prefix match (a[i] < a[i+1]) -> [2,1,|5,4,3,0]
          2. Find >1 which is slightly greater, such that you stay close, here 3
          3. Try to place the remaining elements in sorted way. 
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int idx = -1;
    for(int i = n-2; i>=0; i--)
    {
        if(permutation[i] < permutation[i+1])
        {
            idx = i;
            break;
        }
    }
    
    if(idx == -1){
        int s = 0, e = n-1;
        while(s<e)
        {
            swap(permutation[s++], permutation[e--]);
        }
    }
    for(int i = n-1; i>=idx; i--){
        if(permutation[i] > permutation[idx])
        {
            swap(permutation[i], permutation[idx]);
            break;
        }
    }

    reverse(permutation.begin() + idx + 1, permutation.end());
    return permutation;
}

int main()
{

}