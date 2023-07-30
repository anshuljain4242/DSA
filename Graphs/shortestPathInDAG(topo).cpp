#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void topoDFS(int node, vector<int>& vis, stack<int>& st, vector<pair<int,int> > adj[]){
    vis[node] = 1;
        
    for(auto it:adj[node]){
        if(!vis[it.first])
            topoDFS(it.first, vis, st, adj);
            
    }
    st.push(node); 
}

vector<int> shortestPath(int N,int M, vector<vector<int> >& edges){
    // creating the adjacency list  u -> (v,w)
    vector<pair<int,int> > adj[N];
    for(int i=0; i<M; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back(make_pair(v,wt));
    }
    // Topo sort on the graph
    // O(N+M)
    stack<int> st;
    vector<int> vis(N, 0);
    for(int i=0; i<N; i++){
        if(!vis[i])
            topoDFS(i, vis, st, adj);
    }
    
    vector<int> dist(N);
    for(int i=0; i<N; i++) dist[i] = 1e9;
    dist[0] = 0;
    
    // O(N+M)
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        for(auto it:adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[node] + wt < dist[v])
                dist[v] = dist[node] + wt;
        }
    }
    for(int i=0; i<N; i++){
        if(dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}