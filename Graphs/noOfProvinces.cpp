#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly 
with city b, and city b is connected directly with city c, then city a is connected indirectly with 
city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city 
are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/


// SC -> O(N) + O(N), TC -> O(N) + O(V + 2E)
void dfs(int node, unordered_map<int, list<int> >& adj, vector<int>& vis){

    vis[node] = 1;
    for( auto &it:adj[node]){
        if(!vis[it])
            dfs(it, adj, vis);
    }
}
int findCircleNum(vector<vector<int> >& isConnected) {
    
    int n = isConnected.size();
    unordered_map<int, list<int> > adj;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> vis(n, 0);
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            cnt++;
            dfs(i, adj, vis);
        }
    }
    return cnt;
}