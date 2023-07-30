#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>
class graph{
    public: 
        unordered_map<T, list<T> > adj;

        void Edge(T u, T v, bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed

            // create an edge from u to v
            adj[u].push_back(v);
            if(direction == 0)
                adj[v].push_back(u);
        }

        void printAdjList(){
            for(auto i:adj){
                cout << i.first << "-> ";
                for(auto j:i.second){
                    cout << j <<", ";
                }
                cout<<endl;
            }
        }
};


int main(){

    int n,m;
    cin >> n >> m;

    /* Storing using Adjacency Matrix
    int adj[n+1][n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    */

    // Storing using adjacency list 
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    for(int i=1; i<=n; i++){
        cout << "Adjacent nodes of node " << i << ": ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}