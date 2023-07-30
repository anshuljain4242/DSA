#include<iostream>
#include<vector>
#include<queue>
using namespace std;


bool detect(int src, vector<int>& vis, vector<int> adj[]){
    vis[src] = 1;
    queue<pair<int, int> > q;
    
    q.push(make_pair(src, -1));
    
    while(!q.empty()){
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push(make_pair(adjNode, node));
            }
            else if(adjNode != prev){
                return true;
            }
        }
    }
    return false;
}

bool isCycleBFS(int V, vector<int> adj[]) {
    
    vector<int> vis(V, 0);
    
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(detect(i, vis, adj))
                return true;
        }
    }
    return false;
}

bool detect(int src, int prev, vector<int>& vis, vector<int> adj[]){
    vis[src] = 1;
    
    for(auto adjNode:adj[src]){
        if(!vis[adjNode]){
            if(detect(adjNode, src, vis, adj) == true) 
                return true;
        }
        else if(adjNode != prev)
            return true;
    }
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycleDFS(int V, vector<int> adj[]) {
    
    vector<int> vis(V, 0);
    
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(detect(i, -1, vis, adj)) return true;
        }
    }
    return false;
}