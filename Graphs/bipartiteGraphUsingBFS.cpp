#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool check(int start, vector<int>& color, vector<int>adj[]){
        
    queue<int> q;
    q.push(start);
    color[start] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int adjNode: adj[node]){
            // if the adjacent node is yet not been colored, you will give the opp color of the node
            if(color[adjNode] == -1){
                color[adjNode] = 1 - color[node];
                q.push(adjNode);
            }
            // if the adjacent guy has the same color, someone did color it on some other path
            else if(color[adjNode] == color[node])
                return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    
    vector<int> color(V, -1);
    for(int i=0; i<V; i++){
        if(color[i] == -1){
                if(check(i, color, adj) == false)
                return false;
        }
    }
    return true;
}