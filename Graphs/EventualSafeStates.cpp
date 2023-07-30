#include<iostream>
#include<vector>
using namespace std;

/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D 
integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i 
to each node in graph[i].
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that 
node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
*/

// using one extra array
void dfs(int node, vector<int>& vis, vector<vector<int> >& graph){
    vis[node] = 2; // path visited, if 2

    for(int adjNode : graph[node]){
        if(!vis[adjNode]){
            dfs(adjNode, vis, graph);
        }
        if(vis[adjNode] == 2) return;
    }
    vis[node] = 1;
}
vector<int> eventualSafeNodes(vector<vector<int> >& graph) {
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> ans;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, vis, graph);
        }
    }
    for(int i=0; i<n; i++){
        if(vis[i] == 1)
            ans.push_back(i);
    }
    return ans;
}

// using 3 arrays
bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int>& check, 
vector<int> adj[]){
    
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;
    for(int adjNode: adj[node]){
        // if the node is not visited
        if(!vis[adjNode]){
            if(dfs(adjNode, vis, pathVis, check, adj) == true){
                check[node] = 0;
                return true;
            }

                
        }
        // if the node has been previously visited 
        // but it has to visited on the same path
        else if(pathVis[adjNode]){
            check[node] = 0;
            return true;
        }
    }
    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);
    vector<int> ans;
    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i, vis, pathVis, check, adj);
        }
    }
    for(int i=0; i<V; i++){
        if(check[i] == 1)
            ans.push_back(i);
    }
    return ans;
}