#include<iostream>
#include<vector>
using namespace std;

/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater 
than or equal to target. If there is no such subarray, return 0 instead.
*/


int minSubArrayLen(int target, vector<int>& nums) {
    int l=0, r=0, minLength = INT_MAX;
    int n = nums.size();
    int sum = 0;
    while(r < n){
        sum += nums[r];

        while(sum >= target){
            sum = sum - nums[l];
            minLength = min(minLength, r-l+1); 
            l++;   
        }
        r++; 
    }
    if(minLength == INT_MAX)
        return 0;
    return minLength; 
}

// We can also use Binary Search here. 
/*
Intuition can be- We need a minimum length subrray. so the minimum len could be 0,1,2 uptill n. Initialise minL = 0, Start from window
size(length) = 1 and check all subarrays if they have sum >= target. Similary do this for length = 2,3...n Since we are searching
for the length linearly, we can also use binary search.


The windowfind function checks if there exists a subarray of a given size whose sum is greater than or equal to the target.
It uses the sliding window technique to iterate through the array and maintain a window of the specified size.
If the sum of the elements in the window is greater than or equal to the target, it returns true.
Otherwise, it returns false.
The minSubArrayLen function finds the minimum length of a subarray whose sum is greater than or equal to the target using binary search.

1. It initializes a range from 1 to the size of the input array.
2. It repeatedly divides the range in half and checks if a subarray of the mid-point length satisfies the condition using the windowfind function.
3. If a valid subarray is found, it updates the upper bound of the range to mid-1 and stores the mid-point length as the minimum length
found so far.
4. If a valid subarray is not found, it updates the lower bound of the range to mid+1.
5. The search continues until the lower bound is no longer less than or equal to the upper bound.
6. Finally, it returns the minimum length of the subarray.
The code efficiently utilizes the sliding window technique and binary search to find the minimum length subarray satisfying the given condition.


*/

bool windowfind(int size, vector<int>&nums, int target) {
    int sum = 0;
    int i=0;
    int j=0;
    int mx=INT_MIN;
    int n=nums.size();
    while(j<n){
        sum+=nums[j];
        if(j-i+1==size){
            mx=max(sum,mx);
            sum-=nums[i];
            i++;
        }
        j++;
    }
    if(mx>=target)
    return true;
    return false;
}

int minSubArrayLenB(int target, vector<int>& nums) {
    int low = 1, high = nums.size(), mn = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (windowfind(mid, nums, target)) {
            high = mid-1;
            mn = mid;
        } else low = mid + 1;
    }
        return mn;
}

