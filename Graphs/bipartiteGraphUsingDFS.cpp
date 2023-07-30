#include<iostream>
#include<vector>
using namespace std;

bool check(int node, int currColor, vector<int>& color, vector<int>adj[]){
    color[node] = currColor;
    
    for(auto adjNode:adj[node]){
        if(color[adjNode] == -1){
            if(check(adjNode, !currColor, color, adj) == false)
                return false;
        }   
        else if(color[adjNode] == currColor)
            return false;
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    
    vector<int> color(V, -1);
    for(int i=0; i<V; i++){
        if(color[i] == -1){
                if(check(i, 0, color, adj) == false)
                return false;
        }
    }
    return true;
}