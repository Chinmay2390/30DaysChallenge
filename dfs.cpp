#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//dfs function
void dfs(int start,vector<vector<int>>& adj,vector<bool>& visited,vector<int>& ans){
    
    visited[start] = true;
    ans.push_back(start);
    
   
    for(auto node:adj[start]){
        if(!visited[node]){
            dfs(node,adj,visited,ans);
        }
    }
    
    
}


int main()
{   
    //this are edges 
    vector<vector<int>> edges = {{1,2},{1,4},{2,3},{2,4},{4,3},{3,5},{4,5},{5,6},{1,7},{6,8}};
    
    //this are vertices 
    int v = 9;
    
    int start =1;
    
    vector<vector<int>> adj(v);
    
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    vector<int> dfsAns; 
    vector<bool> visited(v,false);
    
    dfs(start,adj,visited,dfsAns);
 
    
    cout<<"DFS TRAVERSAL:"<<endl;
    for(int i:dfsAns){
        cout<<i<<" ";
    }
    cout<<endl;
    

    
    return 0;
}