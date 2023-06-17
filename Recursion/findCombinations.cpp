#include <iostream>
#include <vector>
using namespace std;
/*
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum 
to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers
is different.
*/
void find_combination(int idx, int target, vector<int> &arr, vector<int> &ds, vector<vector<int> > &ans)
{
    if (idx == arr.size())
    {
        if (target == 0)
            ans.push_back(ds);
        return;
    }
    // Pick up the element
    if (arr[idx] <= target)
    {
        ds.push_back(arr[idx]);
        find_combination(idx, target - arr[idx], arr, ds, ans);
        ds.pop_back();
    }
    // Not pick the element
    find_combination(idx + 1, target, arr, ds, ans);
}
vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int> > ans;
    vector<int> ds;
    find_combination(0, target, candidates, ds, ans);
    return ans;
}

/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

void find_combinations2(int idx, int target, vector<int>& arr, vector<int>& ds, vector<vector<int> >& ans)
    {
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        
        for(int i=idx; i<arr.size(); i++)
        {
            if(i > idx && arr[i] == arr[i-1]) continue; // i>idx suggests that the elements gets repeated, it's not the first time
            if(arr[i] > target) break;
            ds.push_back(arr[i]);

            find_combinations2(i+1, target-arr[i], arr, ds, ans);
            ds.pop_back();
        }
            
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        find_combinations2(0, target, candidates, ds, ans);
    
        return ans;
    }