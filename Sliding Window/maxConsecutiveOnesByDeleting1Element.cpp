#include<iostream>
#include<vector>
using namespace std;
/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. 
Return 0 if there is no such subarray.
*/
int longestSubarray(vector<int>& nums) {
    int l = 0;
    int r = 0;
    int k=1;
    int result = 0;

    for(int r=0; r<nums.size(); r++){
        if(nums[r] == 0)
            k--;

        while(k<0){
            if(nums[l] == 0)
                k++;
            l++;    
        }    
        result = max(result, r-l);
    }
    return result;
}   