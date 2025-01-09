// breadth first search

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> adj,int s){
    queue <int> q;
    vector<bool> visited(adj.size(),false);

    q.push(s);
    visited[s] = true;


    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";


        for(int x: adj[temp]){
            if(visited[x] != true){
                q.push(x);
                visited[x] = true;
            }
        }
    }
    
}


void addEdge(vector<vector<int>> &adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u); // because this is undirected graph...
}

int main(){

    int V = 6;
    //graph using list..
    vector<vector<int>> adj(V);

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);

    bfs(adj,0);
    return 0;
}