#include <iostream>
#include <vector>
using namespace std;

// Memoization
int helper(int idx, int x, vector<int> &num, vector<vector<int> >& dp){

    if(idx == 0){
        if(x % num[idx] == 0) return x/num[idx];
        else return 1e9;
    }

    if(dp[idx][x] != -1)
        return dp[idx][x];

    int notTake = 0 + helper(idx-1, x, num, dp);
    int take = INT_MAX;
    if(num[idx] <= x)
        take = 1 + helper(idx, x-num[idx], num, dp);

    return dp[idx][x] = min(take, notTake);    
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int> > dp(n, vector<int> (x+1, -1));
    int ans = helper(n-1, x, num, dp);
    if(ans >= 1e9) return -1;
    else return ans;
}

// Tabulation
int minimumElementsT(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int> > dp(n, vector<int> (x+1, 0));

    for(int target = 0; target <= x; target++){
        if(target % num[0] == 0)
            dp[0][target] = target/num[0];
        else dp[0][target] = 1e9;    
    }

    for(int idx = 1; idx<n; idx++){
        for(int target = 0; target <=x; target++){
            int notTake = 0 + dp[idx-1][target];
            int take = 1e9;
            if(num[idx] <= target)
                take = 1 + dp[idx][target-num[idx]];

            dp[idx][target] = min(take, notTake);
        }
    }
    int ans = dp[n-1][x];
    if(ans >= 1e9) return -1;
    return ans;
}

// Space Optimization
int minimumElementsS(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev(x+1, 0), curr(x+1, 0);

    for(int target = 0; target <= x; target++){
        if(target % num[0] == 0)
            prev[target] = target/num[0];
        else prev[target] = 1e9;    
    }

    for(int idx = 1; idx<n; idx++){
        for(int target = 0; target <=x; target++){
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(num[idx] <= target)
                take = 1 + curr[target-num[idx]];

            curr[target] = min(take, notTake);
        }
        prev = curr;
    }
    int ans = prev[x];
    if(ans >= 1e9) return -1;
    return ans;
}