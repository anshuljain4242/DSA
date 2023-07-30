#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &nums, int index, vector<vector<int> > &ans)
{
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j = index; j<nums.size(); j++){
        swap(nums[index], nums[j]);
        solve(nums, index+1, ans);
        // reswap, simple backtracking
        swap(nums[index], nums[j]);
    }
}
void permutations(vector<int> &ds, int map[], vector<int> &nums, vector<vector<int> > &ans)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!map[i])
        {
            ds.push_back(nums[i]);
            map[i] = 1;
            permutations(ds, map, nums, ans);
            map[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int> > permute(vector<int> &nums)
{   
    // Optimal - without using extra map space
    // vector<vector<int>> ans;
    // int index = 0;
    // solve(nums, index, ans);
    // return ans;

    // Better
    vector<vector<int> > ans;
    vector<int> ds;
    int map[nums.size()];
    for (int i = 0; i < nums.size(); i++) map[i] = 0;
    permutations(ds, map, nums, ans);
    return ans;
}