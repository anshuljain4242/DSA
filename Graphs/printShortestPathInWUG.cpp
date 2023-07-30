#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int> >& edges) {
    vector<pair<int,int> > adj[n+1];
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    
    priority_queue< pair<int,int>, vector<pair<int,int> >, 
        greater<pair<int,int> > > pq;
    pq.push(make_pair(0,1));
    
    vector<int> dist(n+1, 1e9);
    dist[1] = 0;
    
    vector<int> parent(n+1);
    for(int i=1; i<=n; i++) parent[i] = i;
    
    while(!pq.empty()){
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();
        
        for(auto it:adj[node]){
            int adjNode = it.first;
            int wt = it.second;
            
            if(dis + wt < dist[adjNode]){
                dist[adjNode] = dis + wt;
                pq.push(make_pair(dist[adjNode], adjNode));
                parent[adjNode] = node;
            }
        }
    }
    if(dist[n] == 1e9) return {-1};
    vector<int> path;
    int node = n;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(node);
    reverse(path.begin(), path.end());
    return path;
}