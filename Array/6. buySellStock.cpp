#include<iostream>
#include<vector>
using namespace std;

int maximumProfit(vector<int> &prices){
    
    int minBuy = prices[0], profit = 0;
    for(int i=1; i<prices.size(); i++)
    {
        profit = max(profit, prices[i] - minBuy);
        minBuy = min(minBuy, prices[i]);
    }
    return profit;
}



