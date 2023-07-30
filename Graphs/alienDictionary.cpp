/*
Given a sorted dictionary of an alien language having N words. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid
order and output will be 1 if the order of string returned by the function is correct else 
0 denoting incorrect string returned.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
vector<char> getAlienLanguage(string* dict, int n)
{
    vector<int> adj[26];
    int indegree[26] = {0};

    for(int i=0; i<n-1; i++){
        for(int j=0; j<min(dict[i].size(), dict[i+1].size()); j++){
            if(dict[i][j] != dict[i+1][j]){
                adj[dict[i][j] - 'a'].push_back(dict[i+1][j] - 'a');
                indegree[dict[i+1][j] - 'a']++;
                break;
            }
        }
    }

    vector<char> ans;
    queue<int> q;
    for(int i=0; i<26; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back('a' + node);

        for(auto adjNode:adj[node]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0)
                q.push(adjNode);
        }
    }
    return ans;
}
