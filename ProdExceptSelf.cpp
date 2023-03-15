/*
Given an integer array nums, return an array answer such that answer[i] is equal to the 
product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include<iostream>
using namespace std;
#include<vector>
vector<int> productExceptSelf(vector<int>& nums, int n){
    vector<int> ans(n);
    int pre = 1;
    
    for(int i = 0; i<n; i++){
        ans[i] = pre;
        pre = pre*nums[i];
    }

    int post = 1;
    for(int i=n-1; i>=0; i--){
        ans[i] *= post;
        post = post*nums[i];
    }
    return ans;
    
}

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        nums.push_back(a);

    }
    for(int i=0; i<n; i++){
        cout<<nums.at(i)<<" ";
    }cout<<endl;
    vector<int> ans = productExceptSelf(nums,n);
    for(int i=0; i<n; i++){
        cout<<ans.at(i)<<" ";
    }cout<<endl;
}
