#include<iostream>
#include<vector>
using namespace std;

/*
Given a wooden stick of length n units. The stick is labelled from 0 to n. For example,
 a stick of length 6 is labelled as follows:

Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of 
all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their 
lengths is the length of the stick before the cut). 
Return the minimum total cost of the cuts.

Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of 
length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the 
last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20. Rearranging the cuts to be 
[3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example 
photo 7 + 4 + 3 + 2 = 16).
*/

// Memoization
int f(int i, int j, vector<int>& cuts, vector<vector<int> >& dp){

    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int mini = INT_MAX;
    for(int idx = i; idx<=j; idx++){
        int cost = cuts[j+1] - cuts[i-1] + f(i, idx-1, cuts, dp) + f(idx+1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int> >dp(cuts.size(),vector<int>(cuts.size(),-1));

    return f(1, c, cuts, dp);
}

// Tabulation
int minCostT(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int> > dp(c+2, vector<int>(c+2, 0));

    for(int i=c; i>=1; i--){
        for(int j=1; j<=c; j++){
            if(i>j) continue;
            int mini = INT_MAX;
            for(int idx = i; idx<=j; idx++){
                int cost = cuts[j+1] - cuts[i-1] + dp[i][idx-1] + dp[idx+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}