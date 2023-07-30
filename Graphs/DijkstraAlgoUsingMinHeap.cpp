#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int> > adj[], int S)
{
    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> dist(V);
    for(int i=0; i<V; i++) dist[i] = 1e9;
    dist[S] = 0;
    pq.push(make_pair(0,S));
    
    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        for(auto it:adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];
            if(d + edgeWeight < dist[adjNode]){
                dist[adjNode] = d + edgeWeight;
                pq.push(make_pair(dist[adjNode], adjNode));
            }   
        }
    }
    return dist;
}