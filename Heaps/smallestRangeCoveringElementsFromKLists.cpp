#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each 
of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
Ex-
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
*/

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int> > &nums)
    {

        int k = nums.size();

        // pair(element, (row,col))
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;


        // Step1 : creating min heap from the first elements of all the lists
        int maxi = INT_MIN, mini = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            pq.push(make_pair(nums[i][0], make_pair(i, 0)));
        }

        
        int start = mini;
        int end = maxi;
        vector<int> range;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            mini = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            // Range updation
            if ((maxi - mini) < (end - start))
            {
                start = mini;
                end = maxi;
            }
            
            // if next element exist, update maxi and push it into heap
            if (col + 1 < nums[row].size())
            {
                maxi = max(maxi, nums[row][col + 1]);
                pq.push(make_pair(nums[row][col + 1], make_pair(row, col + 1)));
            }
            else
                break;
        }
        range.push_back(start);
        range.push_back(end);
        return range;
    }
};