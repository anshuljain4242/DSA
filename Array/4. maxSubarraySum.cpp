/*
[1,2,7,-4,3,2,-10,9,1]
sum = 11 ([1,2,7,-4,3,2])
*/

#include<iostream>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;
    long long maxSum = INT_MIN;

    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if(sum < 0)
            sum = 0;
    }
    if(maxSum < 0)
        return 0;
    return maxSum;
}

int main()
{
    int arr[15] = {-7, -8, -16, -4, -8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10};

    int n=15;
    cout << maxSubarraySum(arr, n);
    cout << endl;
}