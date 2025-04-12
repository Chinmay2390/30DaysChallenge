#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//bfs function
vector<int> bfs(int v,vector<vector<int>>& adj,int start){
    
    vector<int> ans;
    vector<bool> visited(v,false);
    
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        visited[curr] = true;
        
        for(auto node:adj[curr]){
            if(!visited[node]){
                visited[node] = true;
                q.push(node);
            }
        }
    
    }
    
    return ans;

}


int main()
{   
    //this are edges 
    vector<vector<int>> edges = {{1,2},{1,4},{2,3},{2,4},{4,3},{3,5},{4,5},{5,6},{1,7}};
    
    //this are vertices 
    int v = 8;
    
    int start =1;
    
    vector<vector<int>> adj(v);
    
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    vector<int> bfsAns = bfs(v,adj,start);
 
    
    cout<<"BFS TRAVERSAL:"<<endl;
    for(int i:bfsAns){
        cout<<i<<" ";
    }
    cout<<endl;
    

    
    return 0;
}