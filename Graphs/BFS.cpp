#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;

// set used instead of list because we wanted the ans in sorted order.

void BFSTraversal(int node, unordered_map<int, set<int> >& adj, vector<int>& ans,
 vector<int>& vis){

    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        
        for(auto i:adj[cur]){
            if(vis[i] == 0){
                q.push(i);
                vis[i] = 1;
            }    
        }
    }
}

void prepareAdjList(unordered_map<int, set<int> >& adj, vector<pair<int, int> >& edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
}
vector<int> BFS(int v, vector<pair<int, int> > edges)
{
    int m = edges.size();
    unordered_map<int, set<int> > adj;
    vector<int> ans;
    vector<int> vis(v, 0);
    prepareAdjList(adj, edges);

    // Check for all components as given disconnected graph
    for(int i=0; i<v; i++){
        if(!vis[i])
            BFSTraversal(i, adj, ans, vis);
    }
    return ans;
}