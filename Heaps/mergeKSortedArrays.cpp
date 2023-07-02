#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int> >&kArrays, int k)
{
    // minheap for storing a pair of element and index no.
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater <pair<int,pair<int,int> > > > pq;
    vector<int> ans;

    for(int i=0; i<k; i++)
    {
        pq.push(make_pair(kArrays[i][0],make_pair(i,0)));
    }

    while(!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        ans.push_back(x.first);
        int row = x.second.first;
        int col = x.second.second;
        if(col < kArrays[row].size()-1)
        {
            pq.push(make_pair(kArrays[row][col+1], make_pair(row,col+1)));
        }
    }
    return ans;
}