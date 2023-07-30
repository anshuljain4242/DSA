#include<iostream>
#include<vector>
using namespace std;

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array 
if you can flip at most k 0's.
*/

int longestOnes(vector<int>& nums, int k) {
    int l = 0;
    int r = 0;
    int result = 0;

    for(int r=0; r<nums.size(); r++){
        if(nums[r] == 0)
            k--;

        while(k<0){
            if(nums[l] == 0)
                k++;
            l++;    
        }    
        result = max(result, r-l+1);
    }
    return result;
}