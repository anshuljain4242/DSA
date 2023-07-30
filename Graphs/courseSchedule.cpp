#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you
must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first 
take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/

 bool canFinish(int n, vector<vector<int> >& prerequisites) {
    // there's an edge from v -> u if(u,v)
    vector<int> adj[n];
    for(int i=0; i<prerequisites.size(); i++){
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adj[v].push_back(u);
    }

    vector<int> indegree(n, 0);
    for(int i=0; i<n; i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
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

    if(topo.size() == n)
        return true;
    return false; 
}       
  