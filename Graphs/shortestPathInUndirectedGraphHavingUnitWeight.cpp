#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> shortestPath(vector<vector<int> >& edges, int N,int M, int src){
    vector<int> adj[N];
    for(int i=0; i<M; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> q;
    q.push(src);
    vector<int> dist(N, -1);
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int it:adj[node]){
            if(dist[it] == -1){
                    dist[it] = dist[node] + 1;
                    q.push(it);
            }
        }
    }
    return dist;
}