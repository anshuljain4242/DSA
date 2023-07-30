#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

// Using DFS
void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){  
    vis[node] = 1;
    
    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            dfs(adjNode, vis, adj, st);
        }
    }
    st.push(node);
}


vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> vis(V, 0);
    stack<int> st;
    
    for(int i=0; i<V; i++){
        if(!vis[i])
            dfs(i, vis, adj, st);
    }
    
    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}


