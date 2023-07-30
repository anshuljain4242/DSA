#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// using TOPOLOGICAL SORT
int detectCycleInDirectedGraph(int n, vector < pair < int, int > > & edges) {

    queue<int> q;
    vector<int> indegree(n+1, 0);

    // creating the adjacency list out of edges
    vector<int> adj[n+1];
    int m = edges.size();
    for(int i=0; i<m; i++){
      int u = edges[i].first;
      int v = edges[i].second;

      adj[u].push_back(v);
    } 

    //  filling the indegree vector 
    for(int i=1; i<=n; i++){
      for(int it:adj[i]){
        indegree[it]++;
      }
    }
    // if any node has an indegree = 0, push into queue
    for(int i=1; i<=n; i++){
      if(indegree[i] == 0)
        q.push(i);
    }
    vector<int> topo;
    // BFS traversal
    while(!q.empty()){
      int node = q.front();
      q.pop();
      topo.push_back(node);

      for(int it:adj[node]){
        indegree[it]--;
        if(indegree[it] == 0)
          q.push(it);
      }
    }

    if(topo.size() != n)
      return 1;
    return 0;  
}