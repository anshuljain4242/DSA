#include<iostream>
#include<vector>
using namespace std;

void get_unique_subsets(int idx, vector<int>& ds, vector<vector<int> >& ans, vector<int>& nums)
    {
        ans.push_back(ds);
        for(int i=idx; i<nums.size(); i++)
        {
            if(i != idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            get_unique_subsets(i+1, ds, ans, nums);
            ds.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        // Brute : generating all the subsets with each recursive call. Putting it into a set to remove the duplicates

        //Optimal: generating a list of incrementing size with each recursive call. Do not pick
        //the element if it is the same as one before it
        sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int> > ans;
        get_unique_subsets(0,ds,ans,nums);
        return ans;
    }