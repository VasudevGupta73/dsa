#include<bits/stdc++.h>
using namespace std;
bool iscyclicdfs(int node,int parent,unordered_map<int,vector<int>>& adj,unordered_map<int,bool>& visited){
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(iscyclicdfs(it,node,adj,visited)) return true;
        }
        else if(it!=parent) return true;
    }
    return false;
}
int main(){
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> visited;
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

}