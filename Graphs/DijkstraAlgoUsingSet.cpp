#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int> > adj[], int S)
{
    set<pair<int, int> >s;

    vector<int> dist(V, 1e9);
    dist[S] =0;
    s.insert(make_pair(0, S));
    while(!s.empty()){
        // s.begin is an iterator poinitng to the address of the first element
        // and star gives the value
        auto it = *(s.begin()); 
        int node = it.second;
        int d = it.first;
        s.erase(it);
        
        for(auto it:adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];
            
            if(d + edgeWeight < dist[adjNode]){
                // erase if it existed
                if(dist[adjNode] != 1e9)
                    s.erase(make_pair(dist[adjNode], adjNode));
                    
                dist[adjNode] = d + edgeWeight;    
                s.insert(make_pair(dist[adjNode], adjNode));
            }
        }
    }
    return dist;
}