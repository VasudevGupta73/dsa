// algorithm to find the shortest path in an directed Acyclic graph (DAG) using topological sorting.
// we will first find the topological sort of the graph and then we will relax the edges in the topological order to find the shortest path from the source node to all the other nodes in the graph.
#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,vector<pair<int,int>>> adj; // pair<node,weight>
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    // step 1: find the topological sort of the graph
    unordered_map<int,bool> visited;
    stack<int> st;
    function<void(int)> dfs=[&](int node){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it.first]){
                dfs(it.first);
            }
        }
        st.push(node);
    };
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    // step 2: relax the edges in the topological order
    vector<int> dist(V,INT_MAX);
    int src; // source node
    cin>>src;
    dist[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(dist[node]!=INT_MAX){
            for(auto it:adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }
    }
    // print the shortest distance from the source node to all the other nodes in the graph
    for(int i=0;i<V;i++){
        if(dist[i]==INT_MAX) cout<<"Distance from "<<src<<" to "<<i<<": "<<"INF"<<endl;
        else cout<<"Distance from "<<src<<" to "<<i<<": "<<dist[i]<<endl;
    }
}